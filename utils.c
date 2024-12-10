#include "utils.h"


void measure_time(struct timespec start, struct timespec end) {
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    if (nanoseconds < 0) {
        --seconds;
        nanoseconds += 1e9;
    }
    printf("Temps d'exécution : %f ms\n", seconds * 1000. + nanoseconds / 1e6);
}

/*
DESCRIPTION :
    

INPUT :
    -
    -
    -

OUTPUT :
    -
    -
    -
*/

void displayText(const char *str){
    write(STDOUT_FILENO, str, strlen(str));
}


char **parse_command(char *command) {
    
    char **args = malloc((MAX_COMMAND_LENGTH / 2 + 1) * sizeof(char*));
    if (args == NULL) {
        perror("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    int i = 0;

    char *token = strtok(token, " ");

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    
    args[i] = NULL;
    return args;
}

void free_args(char **args) {
    if (args != NULL) {
        for (int i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
        free(args);
    }
}



char* get_prompt(int status) {
    static char prompt[MAX_COMMAND_LENGTH];
  
    if (WIFEXITED(status)) {
        sprintf(prompt, "enseash [retour: %d]> ", WEXITSTATUS(status));
    }
    
    else if (WIFSIGNALED(status)) {
        sprintf(prompt, "enseash [signal: %d]> ", WTERMSIG(status));
    }
    
    else {
        sprintf(prompt, "enseash> ");
    }

    return prompt;
}
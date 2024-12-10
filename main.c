#include "main.h"
#include "utils.h"

// Je viens de modifier mon code dans mon shell,
// Cela fonctionne tres bien

int main() {
    char command[MAX_COMMAND_LENGTH];
    int status = STATUS;

    
    displayText(WELCOME_MESSAGE);
    displayText(EXIT_MESSAGE);

    while (1) {
        // Créer un prompt dynamique
        char *prompt = get_prompt(status);
        displayText(prompt);

        // Lire la commande utilisateur
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            perror("Erreur lors de la lecture de l'entrée");
            continue;
        }

        // Supprimer le caractère de nouvelle ligne
        command[strcspn(command, "\n")] = 0;

        // Vérifier la commande 'exit'
        if (strcmp(command, "exit") == 0) {
            displayText(BYE);
            break;
        }

        char **args = parse_command(command);

        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

    
        pid_t pid = fork();
        if (pid == 0) {
            
            

            if (execvp(args[0], args) == -1) {
                perror("Erreur d'exécution");
                free_args(args);
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            perror("Erreur de fork");
        } else {
            waitpid(pid, &status, 0);
            clock_gettime(CLOCK_MONOTONIC, &end);
            measure_time(start, end);
        }
        free_args(args);
    }

    return EXIT_SUCCESS;
}

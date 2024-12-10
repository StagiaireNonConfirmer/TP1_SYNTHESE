#include "main.h"

void measure_time(struct timespec start, struct timespec end);
void displayText(const char *str);
char **parse_command(char *command);
char* get_prompt(int status);
void free_args(char **args);
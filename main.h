
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024
#define STATUS 0
#define WELCOME_MESSAGE "Bienvenue dans le Shell ENSEA.\n"
#define EXIT_MESSAGE "Pour quitter, tapez 'exit'.\n"
#define BYE "Bye bye\n"

extern char command[MAX_COMMAND_LENGTH];

#endif  // MAIN_H



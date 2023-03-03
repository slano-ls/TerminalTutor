#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "explain.h"
#include "misc.h"

#define INPUT_SIZE 1024
static char input[INPUT_SIZE + 1];
static char input_copy[INPUT_SIZE + 1];

#define ARG_COUNT 16
static char *command[ARG_COUNT];
static int arg_index;

int get_input();
int parse_input();
int exec_input();

int get_parse_execute()
{
    return (get_input() &&
            parse_input() &&
            exec_input());
}

int get_input()
{
    static char *tmp;
    static char wd[1024];
    static char prompt[1024];

    getcwd(wd, 1024);
    snprintf(prompt, 1024, "%s%s%s%s%s%s", "\033[1;31m", "bashtutor",
                           "\033[0m:", "\033[1;32m", wd, ">\033[0m ");
    tmp = readline(prompt);

    strcpy(input, tmp);
    strcpy(input_copy, input);

    return true;
}

int parse_input()
{
    char *parsed, *delim;

    arg_index = 0;
    delim = " ";

    parsed = strtok(input_copy, delim);
    while (parsed != NULL) {
        command[arg_index] = parsed;
        arg_index++;

        parsed = strtok(NULL, delim);
    }

    return true;
}

int exec_input()
{
    if (strcmp(command[0], "@help") == 0 || strcmp(command[0], "@h") == 0) {
        print_help();
        return true;
    }
    if (strcmp(command[0], "@quit") == 0 || strcmp(command[0], "@q") == 0) {
        return false;
    }
    if (strcmp(command[0], "@explain") == 0 || strcmp(command[0], "@e") == 0) {
        explain();
        return true;
    }
    if (strcmp(command[0], "@next") == 0 || strcmp(command[0], "@n") == 0) {
        jump_next();
        explain();
        return true;
    }
    if (strcmp(command[0], "@previous") == 0 || strcmp(command[0], "@p") == 0) {
        jump_previous();
        explain();
        return true;
    }
    if (strcmp(command[0], "@jump") == 0 || strcmp(command[0], "@j") == 0) {
        if (jump_progress(atoi(command[1])))
            explain();
        
        return true;
    }

    if (strcmp(command[0], "cd") == 0) {
        if (arg_index > 2) {
            printf("cd: too many arguments\n");
            return true;
        }

        if (chdir(command[1]) == -1)
            perror("cd");
        return true;
    }

    system(input);

    return true;
}

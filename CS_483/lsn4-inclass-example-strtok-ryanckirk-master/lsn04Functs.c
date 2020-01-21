//
// Created by troywein on 1/9/19.
//
#include <stdio.h>
#include <string.h>

void printToks(char* str) {
    // A pointer to the start of a token
    char* token = NULL;

    // Find the first token
    token = strtok(str, " \t");

    // while there are tokens to be found
    // find them and print them
    while (token != NULL) {
        printf("token = %s\n",token);
        token = strtok(NULL, " \t");
    }
}
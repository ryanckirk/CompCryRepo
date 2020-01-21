//
// Created by troywein on 1/9/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** storeToks(char* str) {
    // Allocate a static array of pointers to tokens
    char** toksPtr = malloc(30 * sizeof(char*));
    int curTok = 0;

    // A pointer to the start of a token
    char* token = NULL;

    // Find the first token and store it
    token = strtok(str, " ");
    toksPtr[curTok++] = strdup(token);

    // while there are tokens to be found
    // find them and print them
    while (token != NULL) {
        printf("token = %s\n",token);
        token = strtok(NULL, " ");
        if (token != NULL) {
            toksPtr[curTok++] = strdup(token);
        }
    }
    toksPtr[curTok] = NULL;
    return toksPtr;
}

void printStoredToks(char** tokArrayPtr) {
//    int i = 0;
//    while (tokArrayPtr[i] != NULL) {
//        printf("token = %s\n", tokArrayPtr[i++]);
//    }

    char** curPtr = tokArrayPtr;
    while (*curPtr != NULL) {
        printf("tok=%s\n", *curPtr++);
    }

}

void deallocateToks(char** tokArrayPtr) {
    int i = 0;
    while (tokArrayPtr[i] != NULL) {
        free(tokArrayPtr[i++]);
    }
    free(tokArrayPtr);
}
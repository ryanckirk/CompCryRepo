//
// Created by troywein on 1/17/19.
//
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <string.h>

int main() {

    // Exercise 01
    pid_t retVal;
    int status;
    char *argv[4] = {"man", "-k", "pid", NULL};

    retVal = fork();
    if (retVal != 0) {
        printf("Waiting for child to terminate.\n");
        wait(&status);
        printf("Child terminates.\n");
    } else {
        printf("In child...\n");
        execvp(argv[0], argv);
    }
    // don't need to guard against child executing following code
    // as execvp overwrites the child with the man executable and
    // then terminates when complete

    // Exercise 02
    char inputBuf[50];
    char * cmdPtrArray[20];

    printf("Enter a command: ");
    fgets(inputBuf,49,stdin);
    inputBuf[strlen(inputBuf)-1]='\0';

    char * tmpPtr;

    tmpPtr = strtok(inputBuf," \t");
    int i = 0;
    while (tmpPtr != NULL) {
        cmdPtrArray[i] = strdup(tmpPtr);
        printf("token[%d] = \"%s\"\n",i,cmdPtrArray[i]);
        tmpPtr = strtok(NULL," \t");
        i++;
    }
    cmdPtrArray[i] = NULL;

    return 0;
}
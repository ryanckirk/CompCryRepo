//
// Created by troywein on 1/9/19.
//
#include <stdio.h>
#include <wait.h> // for pid_t
#include <unistd.h> // for fork() etc


int main() {

    pid_t ret_val;
    int x = 0;

    ret_val = fork();
    if (ret_val != 0) {
        // fork returned a non zero value (typically pid of the child)
        // This code executes in the parent (parent runs this code)
        //pid_t pid_term = wait(&x);  // wait for the child to go first
        //printf("In parent...pid of terminated process is %d\n",pid_term);  // print pid terminated proc

        printf("In parent...pid of terminated process is ");  // print pid terminated proc
        printf("My process ID : %d\n", getpid());  // print my pid
        printf("My parent's ID: %d\n", getppid()); // print parents pid
    } else {
        // fork returned 0 - This code executes in child (child runs this code)
        printf("In child...\n");
        printf("My process ID : %d\n", getpid());
        printf("My parent's ID: %d\n", getppid());
    }

    printf("You should see this message 2x once from the parent and once from child prior to termination.\n");

    return 0;

}
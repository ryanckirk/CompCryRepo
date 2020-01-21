//
// Created by troywein on 1/9/19.
//
#include <stdio.h>
#include <string.h>
#include "lsn04Functs.h"


int main() {

    char buf[50];

    // get a string from the user
    printf("Enter a string: ");
    fgets(buf, 49, stdin);
    buf[strlen(buf)-1] = '\0';

    char** myToks = storeToks(buf);

    printStoredToks(myToks);

    deallocateToks(myToks);

    return 0;
}

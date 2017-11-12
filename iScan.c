#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H
#include "arrayTools.h"
#endif

char* iScan(){
//    char *arrayPointer;

    char* string = makeCharArray();
    char k;
    int i;
    for(i = 0; (k = getchar()) != EOF && k != '\n'; i++){
        string = pushbackChar(&string,k);
    }
    return string;
}

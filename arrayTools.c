#ifndef ISVALID_H
#define ISVALID_H
#include "isValid.h"
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif
//makes a character array of size 1 on heap;
char *makeCharArray(){
    char *p;
    p = (char *) malloc(sizeof(char)*1);
    p[0] = '\0';
    return p;
}

//makes an array of size n
char *makeCharArrayOfSize(int n){
    char *p;
    p = (char *) malloc(sizeof(char)*n+1);
    p[n] = '\0';
    return p;
}

//stores a given character c at the end of the given character array givenArray
char *pushbackChar(char **givenArray, char c){

    int i, sizeOfGivenArray;
    char *newArray;
    sizeOfGivenArray = getSize(*givenArray);
    newArray = (char *) malloc(sizeof(char)*(sizeOfGivenArray+2));
    for(i = 0; i < sizeOfGivenArray; i++){
        newArray[i] = (*givenArray)[i];
    }
    newArray[sizeOfGivenArray] = c;
    newArray[sizeOfGivenArray+1] = '\0';
    free(*givenArray);
    *givenArray = newArray;
    return *givenArray;
}


//Shrinks the given array by 1
char *popOffChar(char **givenArray){
    int i, sizeOfGivenArray;
    sizeOfGivenArray = getSize(*givenArray);
    if(sizeOfGivenArray > 0){
        char *newArray;
        newArray = (char *) malloc(sizeof(char)*(sizeOfGivenArray));
        for(i = 0; i < sizeOfGivenArray-1; i++){
            newArray[i] = (*givenArray)[i];
        }
        newArray[sizeOfGivenArray-1] = '\0';
        free(*givenArray);
        *givenArray = newArray;
    }
    else{
        free(*givenArray);
        *givenArray = NULL;
    }
    return *givenArray;

}

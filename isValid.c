#ifndef ISVALID_H
#define ISVALID_H
#include "isValid.h"
#endif

#define CLIMIT 256 /*Character size limit of input*/

int getSize(char *txt){
    int size =0;
    int i;
    for( i = 0; i < CLIMIT; i++){
        if(txt[i] != '\0'){size++;}
        else{break;}
    }
    return size;
}

int getSizeConst(const char *txt){
    int size =0;
    int i; 
    for(i = 0; i < CLIMIT; i++){
        if(txt[i] != '\0'){size++;}
        else{break;}
    }
    return size;
}

int isValidintMore(char *txt, int size){
    int i;
    for( i =0; i < size; i++){
        if( (int)txt[i] >= 48 && (int)txt[i] <= 57){}/*char is a number 0-9*/
        else{return 0;}
    }
    return 1;
}

int isValidalphaMore(char *txt, int size){
    int i;
    for( i =0; i < size; i++){
        if( ((int)txt[i] >= 65 && (int)txt[i] <= 90) ||/*check if char is Uppercase*/
                ((int)txt[i] >= 97 && (int)txt[i] <= 122) /*Checks if char is lowercase*/
          ){}
        else{return 0;}
    }
    return 1;
}

int isValidalphaIntMore(char *txt, int size){
    int i;
    for( i =0; i < size; i++){
        if( 
            (
                ((int)txt[i] >= 65 && (int)txt[i] <= 90) /*char is Uppercase Lettter*/||
                ((int)txt[i] >= 97 && (int)txt[i] <= 122) /*char is lowercase letter*/
            ) || /*or*/
            (
                ((int)txt[i] >= 48 && (int)txt[i] <= 57) /*char is a number 0-9*/
            )
          ){}
        else{return 0;}
    }
    return 1;
}
int isValidalphaInt(char *txt){
    int size;
    size = getSize(txt);
    return isValidalphaIntMore(txt, size);
}

int isValidalpha(char *txt){
    int size;
    size = getSize(txt);
    return isValidalphaMore(txt, size);
}

int isValidint(char *txt){
    int size;
    size = getSize(txt);
    return isValidintMore(txt, size);
}



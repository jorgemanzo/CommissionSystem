#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

/*
 *  This is a version of my isValid function tool box for C. 
 * */
int isValidint(char *txt);
/*
 * takes in a null terminated cstring and returns a 1(true) or 0(false)
 * depending if the given cstring contains all numeric characters
 * or not. This function will find the right size of the string
 * */

int isValidintMore(char *txt, int size);
/*
 * takes in a null terminated cstring, as well
 * as the EXACT size of the cstring. 
 * If exact size is unknown, just dont pass it, or just use
 * getSize(char *txt);
 * */

int isValidalpha(char *txt); 
/* Takes in a null terminated cstring and returns a 1(true) or 0(false)
 * depending if the given cstring contains all Alphabetic
 * characters
 * */

int isValidalphaMore(char *txt, int size);
/*
 *  Takes in a null terminated cstring and the EXACT size of the cstring.
 *  It will return a 1(true) or 0(false) depending on if the string is all Alphabetic characters
 *  if the exact size is unkown, just dont pass the size, or use
 *  getSize(char *txt) to get the exact size.
 *
 * */

int isValidalphaInt(char *txt);
/*
 * Takes in a null terminated cstring and returns a 1(true) or 0(false)
 * depending on if the characters in the string are either Alhpabetical or Ints
 * */

int isValidalphaIntMore(char *txt, int size);
/*
 * Takes in a null terminated cstring and the EXACT size of the string
 * returning a 1(true) or 0(false) depending if the characters in the string are either Alphabetical
 * or Ints
 * */

int getSize(char *txt);
/* takes in a null terminated cstring and returns an int of
 * that string's size
 * */

int getSizeiConst(const char *txt);
/*
 * Takes in a null termindated constant cstring and returns an int of 
 * that string's size
 * */

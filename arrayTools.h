#ifndef ISVALID_H
#define ISVALID_H
#include "isValid.h"
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

/*
 * These are some useful C functions for making arrays faster and growing them more easily
 */
char *makeCharArray();
/*
 * creates a character array of size 1 on heap, terminating it with '\0'
 */

char *makeCharArrayOfSize(int n);
/*
 * Creates a character array of a given size n, placing a null character at the end
 */

char *pushbackChar(char **givenArray, char c);
/*
 * Takes in the ADDRESS OF an array of characters POINTER along with the character
 * to be stored at the end of the array of characters. Creating an completely new array
 * of the size+1 of the given array, storing the characters from the givenArray in
 * the newly created array, appending the given character c at the location [size], 
 * finally appending '\0' to the end of the array
 */

char *popOffChar(char **givenArray);
/*
 * Takes in the ADDRESS OF an array of characters POINTER, then removes the furthest
 * right character, replacing it with the null character as long as the given array
 * size is > 0. If it isn't, then the given array will be cleared from memory and
 * a NULL is returned. 
 */

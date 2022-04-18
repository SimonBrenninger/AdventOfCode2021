#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED

// include header files here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// put macros here

// put prototypes here
int is_digit(char c);           // check if c is a digit (0-9)
int is_hex_digit(char c);       // check if c is a hex digit (0-9, a-f, A-F)
int fget_number(FILE *fp);      // gets one (decimal) number from file
int fget_hex_number(FILE *fp);  // gets one hex number from file

#endif // HEADER_INCLUDED
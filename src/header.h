#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED

// include header files here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// put macros here
#define ALLOC_CHUNK_SIZE    16

// put prototypes here

// check if c is a digit (0-9)
// return: TRUE: c is a digit; FALSE: c is not a digit
int is_dec_digit(char c);
// check if c is a hex digit (0-9, a-f, A-F)
// return: TRUE: c is a hex-digit; FALSE: c is not a hex-digit
int is_hex_digit(char c);
int fget_dec_number(int *number, FILE *fp);
// gets numbers from file until 'end' character is reached
// arr: pointer to number array; end: end-character
// return: number of elements inserted
int fget_numbers(int **arr, char end, FILE *fp);

#endif // HEADER_INCLUDED
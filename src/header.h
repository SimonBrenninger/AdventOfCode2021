#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED

// include header files here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include <unistd.h>

// put macros here
#define MAX_PUZZLE_DAYS     25
#define ALLOC_CHUNK_SIZE    16

// put prototypes here

// converts string to integer (expects decimal notation)
// *s pointer to first string element; *dec: pointer to integer
// return 1: no error occurred; 0: non-decimal character found
uint8_t str_to_int(char *s, int *dec);

// check if c is a digit (0-9)
// return: 1: c is a digit; 0: c is not a digit
int is_dec_digit(char c);

// check if c is a hex digit (0-9, a-f, A-F)
// return: 1: c is a hex-digit; 0: c is not a hex-digit
int is_hex_digit(char c);

// opens file and checks if an error occurred
// fp: filepointer
// return 1: error occurred; 0: no error occurred
int file_open(char *fname, FILE **fp);

// gets one number from file
// *number: pointer to integer variable, fp: file pointer
// return: last character read from file; not a decimal digit
int fget_dec_number(int *number, FILE *fp);

// gets numbers from file until 'end' character is reached
// arr: pointer to number array; end: end-character
// num_elements: returns number of elements read
// return: last character read (either end or EOF)
int fget_numbers(int **arr, char end, int *num_elements, FILE *fp);

/*      functions for each day          */
void day1(FILE *fp);
void day2(FILE *fp);
void day3(FILE *fp);
void day4(FILE *fp);
void day5(FILE *fp);
void day6(FILE *fp);
void day7(FILE *fp);
void day8(FILE *fp);
void day9(FILE *fp);
void day10(FILE *fp);
void day11(FILE *fp);
void day12(FILE *fp);
void day13(FILE *fp);
void day14(FILE *fp);
void day15(FILE *fp);
void day16(FILE *fp);
void day17(FILE *fp);
void day18(FILE *fp);
void day19(FILE *fp);
void day20(FILE *fp);
void day21(FILE *fp);
void day22(FILE *fp);
void day23(FILE *fp);
void day24(FILE *fp);
void day25(FILE *fp);

#endif // HEADER_INCLUDED
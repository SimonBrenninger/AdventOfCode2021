#include "header.h"

uint8_t str_to_int(char *s, int *dec)
{
    int i=0, buff=0;
    while(s[i] != '\0')
    {
        if(!is_dec_digit(s[i]))
            return 0;   // non-decimal character found; abort
        
        buff = buff * 10 + s[i] - '0';
        i++;
    }
    *dec = buff;    // no error converting; copy buff to dec
    return 1;
}

int is_dec_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_hex_digit(char c)
{
    return (is_dec_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int file_open(char *fname, FILE **fp)
{
    *fp = fopen(fname, "r");
    if(*fp == NULL)
    {
        printf("error occurred while opening from file!\n");
        return 0;
    }
    return 1;
}

int fget_dec_number(int *number, FILE *fp)
{
    char next_char;
    *number = 0;
    // read characters until first digit
    do
    {
        next_char = fgetc(fp);
    }
    while (!is_dec_digit(next_char));
    
    // read until next character is not a digit anymore
    while(is_dec_digit(next_char))
    {
        *number = *number * 10 + next_char - '0';
        next_char = fgetc(fp);
    }
    return next_char;
}

int fget_numbers(int **arr, char end, FILE *fp)
{
    char c;
    int allocd = 0, num_elements = 0;

    do
    {
        if(num_elements == allocd)  // alloc more memory if needed
        {
            allocd += ALLOC_CHUNK_SIZE;
            *arr = realloc(*arr, allocd * sizeof(int));
            if(*arr == NULL)
                printf("error reallocating memory!\n");
        }
        c = fget_dec_number(&(*arr)[num_elements++], fp);
    }
    while (c != end);
    *arr = realloc(*arr, num_elements * sizeof(int));
    if(*arr == NULL)
        printf("error reallocating memory!\n");

    return num_elements;
}
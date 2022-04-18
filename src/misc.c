#include "header.h"

int is_dec_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_hex_digit(char c)
{
    return (is_dec_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
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
    
    // read until character is not a digit anymore
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
    int buff, allocd = 0, num_elements = 0;

    do
    {
        if(num_elements == allocd)  // alloc more memory if needed
        {
            allocd += ALLOC_CHUNK_SIZE;
            *arr = realloc(*arr, allocd * sizeof(int));
            if(*arr == NULL)
                printf("error reallocating memory!\n");
        }
        c = fget_dec_number(&buff, fp);
        (*arr)[num_elements++] = buff;
    }
    while (c != end);
    *arr = realloc(*arr, num_elements * sizeof(int));
    if(*arr == NULL)
        printf("error reallocating memory!\n");

    return num_elements;
}
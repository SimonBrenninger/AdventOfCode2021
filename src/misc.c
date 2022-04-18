#include "header.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_hex_digit(char c)
{
    return (is_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int fget_number(FILE *fp)
{
    char c = 0;
    do
    {
        c = fgetc(fp);  // get next char from file
    }
    while(!is_digit(c));

    return c;
}

int fget_hex_number(FILE *fp)
{
    return 0;
    
}
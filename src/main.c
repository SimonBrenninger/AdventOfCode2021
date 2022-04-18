#include "header.h"

int main()
{
    FILE *fp = fopen("test/day1.txt", "r");
    int *arr = NULL;
    int i, num_elements = 0;
    if(fp != NULL)
    {
        num_elements = fget_numbers(&arr, EOF, fp);
        fclose(fp);
    }
    
    i=0;
    while(i<num_elements)
    {
        printf("%d\n", arr[i++]);
    }

    free(arr);
    return 0;
}
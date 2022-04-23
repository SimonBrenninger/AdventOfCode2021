#include "header.h"

static void day1_part1(int *arr, const int num_elements);
static void day1_part2(int *arr, const int num_elements);

void day1(FILE *fp)
{
    int num_elements, *arr = NULL;
    // get puzzle input
    num_elements = fget_numbers(&arr, EOF, fp);
    fclose(fp);

    // solve both puzzles
    day1_part1(arr, num_elements);
    day1_part2(arr, num_elements);
    free(arr);
}

static void day1_part1(int *arr, const int num_elements)
{
    int i, num_increased = 0;
    // cumpute how many times the distance increased
    for(i = 1; i < num_elements; i++)
    {
        if(arr[i-1] < arr[i])
        {
            num_increased++;
        }
    }

    printf("Puzzle Solution Part 1: %d times increased\n", num_increased);
}


static void day1_part2(int *arr, const int num_elements)
{
    int i, num_increased = 0;
    int window_a, window_b, window_size=3;

    for(i = 0; i < num_elements-window_size; i++)
    {
        window_a = arr[i]   + arr[i+1] + arr[i+2];
        window_b = arr[i+1] + arr[i+2] + arr[i+3];
        // check if window increased
        if(window_a < window_b)
        {
            num_increased++;
        }
    }

    printf("Puzzle Solution Part 2: %d times increased\n", num_increased);
}
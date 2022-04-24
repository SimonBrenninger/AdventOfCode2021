#include "header.h"

int main(int argc, char **argv)
{
    // create function pointer array to select which day to solve
    void (*fun_ptr_arr[25])(FILE *fp) = {day1,  day2,  day3,  day4,  day5,  \
                                            day6,  day7,  day8,  day9,  day10, \
                                            day11, day12, day13, day14, day15, \
                                            day16, day17, day18, day19, day20, \
                                            day21, day22, day23, day24, day25};

    // create default day and default data
    int i, day = 1;
    char data_dir[] = "input";  // directory name
    char data_path[25] = "";    // full data path
    // if available use arguments from termial
    for(i = 1; i < argc; i++)
    {
        // set the data directory to read from
        // dont bother about "input" since it is the default folder
        if(strcmp(argv[i], "test") == 0)
        {
            strcpy(data_dir, argv[i]);
        }
        if(str_to_int(argv[i], &day))    // no error during conversion
        {
            if(day < 1 || day > MAX_PUZZLE_DAYS) 
            {
                day = 1;    // day is out of 'day-range' --> set default day
            }
        }
    }


    // concat filename and data_path
    sprintf(data_path, "%s/day%d.txt", data_dir, day);

    // create file pointer
    FILE *fp;

    // open file and check if file exists
    if(file_open(data_path, &fp))
    {
        printf("\nSolving day %d with data from '%s' directory...\n", day, data_dir);
        // solve the correct day
        (*fun_ptr_arr[day-1])(fp);
    }
    else
    {
        printf("error: file '%s' doesn't exist! aborting...\n", data_path);
    }
    return 0;
}
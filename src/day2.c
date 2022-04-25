#include "header.h"

#define ERR_UKNOWN_DIR -2

#define FORWARD 0
#define DOWN 1
#define UP 2

static int fget_next_position(int *dir, int *val, FILE *fp);
static void day2_part1(FILE *fp);
static void day2_part2(FILE *fp);

void day2(FILE *fp)
{
    day2_part1(fp);
    rewind(fp);     // set file pointer to start of file
    day2_part2(fp);
    fclose(fp);
}

static int fget_next_position(int *dir, int *val, FILE *fp)
{
    char direction[8];
    if(fscanf(fp, "%s %d", direction, val) == EOF)
    {
        return EOF;
    }

    if(strcmp(direction, "forward") == 0)
    {
        *dir = FORWARD;
    }
    else if(strcmp(direction, "down") == 0)
    {
        *dir = DOWN;
    }
    else if(strcmp(direction, "up") == 0)
    {
        *dir = UP;
    }
    else
    {
        return ERR_UKNOWN_DIR;
    }
    return 1;
}

static void day2_part1(FILE *fp)
{
    int dir, val, h_rel=0, v_rel=0;
    int ret;

    // read file line by line
    while((ret = fget_next_position(&dir, &val, fp)) && ret != EOF && ret != ERR_UKNOWN_DIR)
    {
        if(ret == ERR_UKNOWN_DIR)
        {
            printf("unknown string in puzzle data! aborting...\n");
            return;
        }
        switch(dir)
        {
            case FORWARD:
            {
                h_rel += val;
                break;
            }
            case DOWN:
            {
                v_rel += val;
                break;
            }
            case UP:
            {
                v_rel -= val;
                break;
            }
            default:
                break;
        }
    }
    printf("Puzzle Solution Part 1: %d\n", (h_rel * v_rel));
}

static void day2_part2(FILE *fp)
{
    int dir, val, h_rel=0, v_rel=0, aim=0;
    int ret;

    // read file line by line
    while((ret = fget_next_position(&dir, &val, fp)) && ret != EOF && ret != ERR_UKNOWN_DIR)
    {
        if(ret == ERR_UKNOWN_DIR)
        {
            printf("unknown string in puzzle data! aborting...\n");
            return;
        }
        switch(dir)
        {
            case FORWARD:
            {
                h_rel += val;
                v_rel += aim * val;
                break;
            }
            case DOWN:
            {
                aim += val;
                break;
            }
            case UP:
            {
                aim -= val;
                break;
            }
            default:
                break;
        }
    }
    printf("Puzzle Solution Part 2: %d\n", (h_rel * v_rel));
}
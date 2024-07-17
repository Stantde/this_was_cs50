#include <cs50.h>
#include <stdio.h>

int get_height(void);
void build_pyramid(int max_height);
void print_spaces(int num_spaces);
void print_bricks(int num_bricks);

int main(void)
{
    int height = get_height();
    build_pyramid(height);
}

int get_height(void)
{
    int h;

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}

void build_pyramid(int max_height)
{
    int num_spaces;
    int num_bricks;

    for (int curr_height = 0; curr_height < max_height; curr_height++)
    {
        num_spaces = max_height - curr_height - 1;
        num_bricks = curr_height + 1;

        print_spaces(num_spaces);
        print_bricks(num_bricks);
    }
}

void print_spaces(int num_spaces)
{
    for (int j = 0; j < num_spaces; j++) // spaces
    {
        printf(" ");
    }
}

void print_bricks(int num_bricks)
{
    const string BRICK = "#";
    string end;

    for (int loop = 0; loop < 2; loop++)
    {
        for (int j = 0; j < num_bricks; j++) // bricks
        {
            printf("%s", BRICK);
        }
        end = (loop == 0) ? "  " : "\n";
        printf("%s", end);
    }
}
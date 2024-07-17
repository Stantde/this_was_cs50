#include <cs50.h>
#include <stdio.h>

int main(void)
{
    strings[] = "battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    int n = get_string("String: ");
    for (int i = 0; i < 7; i++)
    {
        if (strings[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
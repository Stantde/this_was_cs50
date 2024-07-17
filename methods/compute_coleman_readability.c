#include <cs50.h>
#include <stdio.h>

int main(void)
{
    bool DEBUG = true;
    int index;
    if (DEBUG)
    {
        float L = 464.29;
        printf("float L is: %.2f\n", L);
        float S = 28.57;        // feeds in L and S. returns index
    }
    /*
    index = 0.0588 * L - 0.296 * S - 15.8;
    printf("int index is: %i\n", index);*/
    // Calculate Coleman-Liau  //will need to be int, but handle floats.
    //return index;
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    do
    {
    length = get_int("Length :");
    }
    while (length < 1);
    int array[length];
    array[0] = 1;
    printf("Array index: %i, Array value: %i\n", 0, array[0]);
    for (int i = 0; i < length; i++)
    {
        array[i + 1] = 2 * array[i];
        printf("Array index: %i, Array value: %i\n", i + 1, array[i + 1]);
    }

}
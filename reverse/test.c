// The purpose of test_one is to determine which numbers are considered true, and which numbers
// are considered false.
#include <stdio.h>
#include <stdlib.h>

void test_one(void);
void test_two(void);
int main(void)
{
    test_two();
}
void test_one(void)
{
    for (int i = 0; i < 10; i++)
    {
        if (i)
        {
            printf("%i is considered true.\n", i);
        }
    }
/*
Results:

1 is considered true.
2 is considered true.
3 is considered true.
4 is considered true.
5 is considered true.
6 is considered true.
7 is considered true.
8 is considered true.
9 is considered true.
*/
}

void test_two(void)
{
    char *hex = "FF";
    long dec = strtol(hex, NULL, 16);
    printf("%ld\n", dec);
/*
Results:

255

Yes, you can still use the strtol function to convert a hexadecimal string to a long integer. After that, you can cast the result to a short int.
However, be careful with this approach because if the hexadecimal number is too large for a short int, you may encounter overflow issues. Here's a brief example:

char *hexString = "A1B2";
long int longValue = strtol(hexString, NULL, 16);
short int shortValue = (short int) longValue;
Remember to check that your hexadecimal number fits into a short int to avoid any potential issues.
*/
}
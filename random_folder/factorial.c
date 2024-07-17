#include <cs50.h>
#include <stdio.h>
#include <string.h>

int factorial(int a);
int main(void)
{
    printf("%i\n", factorial(get_int("Input number: ")));

}
//
int factorial(int a)
{
    if (a > 1)
    {
        return factorial(a-1)*a;
    }
    return a;
}
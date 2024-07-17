#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("you entered: x: %i\ny: %i\n", x, y);

    int z = pow(x, y);

    printf("%i raised to the %i power yields\n%i\n", x, y, z);

    double a = atan(z);
    printf("The square of which is: %f\n", a);
    return 1;
// kill poison armor rainbow robes
}
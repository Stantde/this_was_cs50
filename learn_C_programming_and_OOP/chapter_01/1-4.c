#include <stdio.h>

/* Write a program to print the corresponding Celsius to Fahrenheit table.
 */

int main()
{
    int lower, upper, step;
    float fahr, celsius;
    lower = -20.0; /* lower limit of temperature table */
    upper = 100; /* upper limit */
    step = 10; /* step size */
    celsius = lower;
    printf("celsius\tfahr\n");

    while (celsius <= upper) {
        //celsius = (5.0/9.0) * (fahr-32.0); // fahr to celsius
        fahr = 9.0/5.0*celsius + 32.0 ;// celsius to fahr
        printf("%6.1f %4.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
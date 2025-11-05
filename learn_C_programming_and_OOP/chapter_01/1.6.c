#include <stdio.h>

int main() /* Exercise 1-6. Write a program to count blanks, tabs, and newlines. */
{
    int c, b, t, nl;

    b = 0;
    t = 0;
    nl = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ')
            ++b;
        if (c == '\t')
            ++t;
        if (c == '\n')
            ++nl;
    }
    printf("blanks: %d\ntabs: %d\nnewlines: %d\n", b, t, nl);
    return 0;
}
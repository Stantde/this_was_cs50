#include <stdio.h>

int main() /* Exercise 1-7. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
{
    int c;
    int count_of_spaces = 0;
    while ((c = getchar()) != EOF){
        if (c != ' '){
            putchar(c);
            count_of_spaces = 0;
        }        
        else {
            count_of_spaces++;
            if (count_of_spaces < 2){
                putchar(c);        
            }
        }
    }
    return 0;
}
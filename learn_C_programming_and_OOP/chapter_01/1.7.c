#include <stdio.h>

int main() /* Exercise 1-7. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
{
    int c;
    int p =0;
    int count = 0;
    //c=getchar();
    while ((c = getchar()) != EOF){
        /*if (count = 0){
            p = c;
            putchar(c);
        }*/
        if (c != ' '){
            putchar(c);        
        }        
        else {
            if (p == ' '){
                putchar(c);        
            }
        }
        p = c;        
    }
    return 0;
}
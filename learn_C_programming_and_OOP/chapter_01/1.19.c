#include <stdio.h>

#define TABCONVERSION 4

/*
Exercise 1-19. Write a program detab which replaces tabs in the input with 
the proper number of blanks to space to the next tab stop. Assume a fixed set 
of tab stops, say every n positions.
*/


int main(){
    int c;

    while ((c=getchar())!= EOF){
        if (c =='\t'){
            c=' ';
            for (int i = 0; i < TABCONVERSION-1; i++){
                putchar(' ');
            }
        }
        putchar(c);
    }    
    return 0;
}
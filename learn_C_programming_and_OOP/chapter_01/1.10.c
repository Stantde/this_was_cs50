#include <stdio.h>

#define YES 1
#define NO  0

/* 
Exercise 1-10. Write a program which prints the words in its input, one per 
line. 
*/
int main() 
{
    int c, nl, nw, nc, inword;

    inword = NO;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n' )
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t' ){
            inword = NO;
            printf("\n");
        }
        else if ( inword == NO ) {
            inword = YES;
            ++nw;
        }
        if (inword == YES){
            putchar(c);
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
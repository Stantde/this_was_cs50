#include <stdio.h>
#define FALSE 0
#define TRUE 1
/*
for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
     s[i] = c;


Exercise 2-1. Write a loop equivalent to the for loop above without using &&.

*/
int main(void){
    // start
    char c;
    int i=0;
    int lim=10;
    int loop=TRUE;
    char s[lim];

    while (loop){
        if (i<lim-1){
            if((c=getchar()) != '\n' ){
                if (c != EOF){
                    s[i] = c;
                    ++i;
                } else {loop=FALSE;}
            } else {loop=FALSE;}
        } else {loop=FALSE;}
    }
    return 0;
}

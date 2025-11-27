#include <stdio.h>
/*
Exercise 2-7. Write the function rightrot(n, b) which rotates the integer n to the right by b bit positions.
*/
int wordlength(void);
int rightrot(unsigned int n, int b);
int main() {
    int a=rightrot(0x1A, 3);
    printf("%X\n", a);

    return 0;
}
int wordlength(void){
/*
*/
    unsigned int bit_tracker=1;
    int count=0;

    while(bit_tracker){
        bit_tracker=bit_tracker<<1;
        ++count;
        //printf("%i\n", count);
        //printf("%b\n", bit_tracker);
    }
    return count;
}
int rightrot(unsigned int n, int b){
    int tmp=n&~(~0<<b);
    int diff=wordlength()-b;
    return ((n>>3)|(tmp<<diff));

}

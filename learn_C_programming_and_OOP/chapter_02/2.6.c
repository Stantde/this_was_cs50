#include <stdio.h>
/*
Exercise 2-6. Write a function wordlength() which computes the word length of
the host machine, that is, the number of bits in an int. The function should be
portable, in the sense that the same source code works on all machines.
*/
int wordlength(void);
int main() {
    int a;
    a=wordlength();
    printf("%i\n", a);

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

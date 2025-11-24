#include <stdio.h>
/*
Exercise 2-7. Write the function rightrot(n, b) which rotates the integer n to the right by b bit positions.
*/
int wordlength(void);
int rightrot(unsigned int n, int b);
int main() {
    int a;
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
        printf("%i\n", count);
        printf("%b\n", bit_tracker);
    }
    return count;
}
int rightrot(unsigned int n, int b){
    int a;
    a=wordlength();
  
    return 0;
}

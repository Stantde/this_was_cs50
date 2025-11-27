#include <stdio.h>

int bitcount(unsigned int n);
int revised_bitcount(unsigned int n);
int main(void){
    unsigned int n = 0x9;
    printf("Number of 1 bits in %b is %i\n", n, bitcount(n));
    printf("Number of 1 bits in %b is %i\n", n, revised_bitcount(n));
    return 0;
}
int bitcount(unsigned int n){
    int b;

    for (b = 0; n != 0; n >>= 1)
        if (n & 01)
            b++;
    return(b);
}
int revised_bitcount(unsigned int n){
    int b=0;
    while(n &= ( n-1 )){
        b++;
    }
    b++;
    return b;
}
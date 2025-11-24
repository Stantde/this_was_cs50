#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define LIMIT 1000
/*
Exercise 2-5. Modify getbits to number bits from left to right.

To illustrate the use of some of the bit operators, consider the function 
getbits(x, p, n) which returns (right adjusted) the n-bit field of x that 
begins at position p. We assume that bit position 0 is at the right end and 
that n and p are sensible positive values. For example, getbits(x, 4, 3) 
returns the three bits in bit positions 4, 3 and 2, right adjusted.

getbits(x, p, n) /* get n bits from position p *\/
unsigned x, p, n;
{
    return((x >> (p+1-n)) &  ~(~0 << n));
}

*/
int modified_getbits(unsigned x, int p, int n);
int main() {
    int a;
    a=modified_getbits(0b00110000000000000000000000000000, 2, 2);
    printf("%b\n", a); // Outputs 11

    return 0;
}
int modified_getbits(unsigned x, int p, int n){
/*
At present, this implementation of modified_getbits will return 0 for bits that
are not defined. Would it be better to return -1 or similar value ??
*/
int b = 32; // b represents the number of bits in an unsigned int. At this point, assume 32.
return (( x >> (( b - 1 - p)-( n - 1 ))) & ~( ~0 << n ));
}

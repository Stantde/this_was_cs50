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
int getbits(unsigned x, unsigned p, unsigned n);
int main(void){
    int result = getbits(21, 4, 3);
    printf("%b\n", result);
    return 0;
}
int getbits(unsigned x, unsigned p, unsigned n){
/* get n bits from position p */

    return((x >> (p+1-n)) &  ~(~0 << n));
}


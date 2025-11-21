getbits(x, p, n) /* get n bits from position p */
/*getbits(x, p, n) which returns (right adjusted) the n-bit field of x that begins at position p. We assume that bit position 0 is at the right end and that n and p are sensible positive values. For example, getbits(x, 4, 3) returns the three bits in bit positions 4, 3 and 2, right adjusted.*/
unsigned x, p, n;
{
    return((x >> (p+1-n)) &  ~(~0 << n));
}

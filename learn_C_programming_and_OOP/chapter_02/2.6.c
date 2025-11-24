modified_getbits(unsigned x, int p, int n){
int b = 32; // b represents the number of bits in an unsigned int. At this point, assume 32.
return (( x >> (( b - 1 - p)-( n - 1 ))) & ~( ~0 << n ))
}

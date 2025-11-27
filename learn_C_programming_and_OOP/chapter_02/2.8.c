#include <stdio.h>
/*
Exercise 2-8. Write the function invert(x, p, n) which inverts (i.e., changes 1 
into 0 and vice versa) the n bits of x that begin at position p, leaving the 
others unchanged.
*/
unsigned int invert(unsigned int x, int p, int n);
int main() {
    unsigned int x=0x1A;
    int p=5;
    int n=3;
    unsigned int a=invert(x, p, n);
    
    printf("Value in 32 bit binary: %.32b\n", x);
    printf("Invert starting at position %i, %i bits.\n", p, n);
    printf("Result: %.32b\n", a);

    return 0;
}
unsigned int invert(unsigned int x, int p, int n){
/*
Exercise 2-8. Write the function invert(x, p, n) which inverts (i.e., changes 1 
into 0 and vice versa) the n bits of x that begin at position p, leaving the 
others unchanged.
*/
    int right_bits;
    int bits_to_invert;
    int inverted_bits;
    int left_bits;
    int output=0;
    int num_of_right_bits;

    // printf("x: %.32b\n", x);
    num_of_right_bits = p-(n-1);
    right_bits= x&~(~0<<num_of_right_bits);
    // printf("num of right bits: %i\n", num_of_right_bits);
    // printf("significant right bits: %b\n", right_bits);
    // printf("x remaining (with leading 0s): %.32b\n", x>>num_of_right_bits);
    bits_to_invert=(x>>num_of_right_bits)&~(~0<<n);
    // printf("Number of bits to invert: %i\n", n);
    // printf("bits to invert: %.3b\n", bits_to_invert);
    inverted_bits = ~bits_to_invert&~(~0<<n);
    // printf("Inverted bits: %.3b\n", inverted_bits);
    left_bits=x>>num_of_right_bits>>n;
    // printf("Left bits: %b\n", left_bits);
//starting appending bits back on
    // printf("(left_bits<<n): %b\n", (left_bits<<n));
    // printf("((left_bits<<n)|inverted_bits): %b\n", ((left_bits<<n)|inverted_bits));
    // printf("(((left_bits<<n)|inverted_bits)<<num_of_right_bits): %b\n", (((left_bits<<n)|inverted_bits)<<num_of_right_bits));
    // printf("(((left_bits<<n)|inverted_bits)<<num_of_right_bits)|right_bits: %b\n",(((left_bits<<n)|inverted_bits)<<num_of_right_bits)|right_bits);
    output = (((left_bits<<n)|inverted_bits)<<num_of_right_bits)|right_bits;
    // printf("Inverted x, at p, n bits: %.32b\n", output);
    return output;

}
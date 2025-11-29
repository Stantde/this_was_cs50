#include <stdio.h>
#define MAXLINE 1000

void itob(unsigned int n, char s[]);
void itoh(int n, char s[]);
void itoany(int n, char s[], int base);
int power_to_b(int a, int b);
void reverse(char s[], int len);

int main(void){
/*
Exercise 3-4. Write the analogous function itob(n, s) which converts the 
unsigned integer n into a binary character representation in s. Write itoh, 
which converts an integer to hexadecimal representation.

Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s. 

*/
    char s[MAXLINE];
    unsigned int n = 20;
    int hex_test=50406;
    int base=16;
    
    itob(n, s);
    printf("%i itob: %s\n", n, s);
    itoh(hex_test, s);
    printf("%i itoh: %s\n", hex_test, s);
    itoany(hex_test, s, base);
    printf("%i itoany: %s\n", hex_test, s);
    
    return 0;
}

void itob(unsigned int n, char s[]){
/* 
converts the unsigned integer n into a binary character representation in s
*/
    // First test, use 20. Do you remember how to convert d to b?
    int i=0;
    int MASK=~(~0<<1);
    for (i=0; n>0; i++){
        int r = n&MASK;
        s[i]= r + '0';
        n>>=1;
    }
    s[i]='\0';    
    reverse(s, i);
    
    return;
}
void itoh(int n, char s[]){
/*
converts an integer to hexadecimal representation.
*/
    int i=0;
    int base=16;
    for (i=0; n>0; i++){
        s[i] = (n%base>9)?((n%base)-10 + 'A'):(n%base)+'0';
        n/=base;
    }
    s[i]='\0';    
    reverse(s, i);
    return;
}
void itoany(int n, char s[], int base){
/*
converts the integer n into a base b character representation in the string s.
*/
    int i=0;
    for (i=0; n>0; i++){
        s[i] = (n%base>9)?((n%base)-10 + 'A'):(n%base)+'0';
        n/=base;
    }
    s[i]='\0';    
    reverse(s, i);

    return;
}
void reverse(char s[], int len){
    int c, i, j;
    for (i = 0, j = len-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
 }
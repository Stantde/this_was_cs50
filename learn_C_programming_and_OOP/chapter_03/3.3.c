#include <stdio.h>
#define MAXLINE 1000

unsigned int convert (int n);
void reverse(char s[]);
void itoa(int n, char s[]);
int main(){
/*
[Exercise 3-3.](./chapter_03/3.3.c) In a 2's complement number representation, 
our version of itoa does not handle the largest negative number, that is, the 
value of n equal to -(2wordsize-1). Explain why not. Modify it to print that 
value correctly, regardless of the machine it runs on.

/* itoa: convert n to characters in s *\/
 void itoa(int n, char s[])
 {
 int i, sign;
 if ((sign = n) < 0) /* record sign *\/
 n = -n; /* make n positive *\/
 i = 0;
 do { /* generate digits in reverse order *\/
 s[i++] = n % 10 + '0'; /* get next digit *\/
 } while ((n /= 10) > 0); /* delete it *\/
 if (sign < 0)
 s[i++] = '-';
 s[i] = '\0';
 reverse(s);
 }
*/  
    int max_neg=-2147483648;
    int two_digit_positive = 65;
    int three_digit_negative = -489;
    char s[MAXLINE];
    printf("\n%b\n", max_neg);
    printf("\n%i\n", max_neg);
    itoa(max_neg,s);
    printf("\n%s\n", s);
    
    printf("\n%b\n", two_digit_positive);
    printf("\n%i\n", two_digit_positive);
    itoa(two_digit_positive,s);
    printf("\n%s\n", s);
    
    printf("\n%b\n", three_digit_negative);
    printf("\n%i\n", three_digit_negative);
    itoa(three_digit_negative,s);
    printf("\n%s\n", s);
    return 0;
}


/* itoa: convert n to characters in s */
 void itoa(int n, char s[]){
    int i, sign;
    i = 0;
    if ((sign = n) < 0){
    ;
    }
 
    
    do { /* generate digits in reverse order */
        int r;
        r = (n<0)?(-1)*(n%10):n%10;
        s[i++] = r + '0'; /* get next digit */
    } while ((n /= 10) != 0); /* delete it */
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

 void reverse(char s[]){
    int i;
    char t[MAXLINE];
    for (i=0; s[i]!='\0'; i++){
        t[i]=s[i];
    }
    int max=i;
    while(i>0){        
        s[max-(i)]=t[i-1];
        i--;
    }
    return;
 }
    
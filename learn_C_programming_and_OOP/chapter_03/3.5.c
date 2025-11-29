#include <stdio.h>
#define MAXLINE 1000

void itoa(int n, char s[], int min_width);
int power_to_b(int a, int b);
void reverse(char s[], int len);

int main(void){
/*
* Exercise 3-5. Write a version of itoa which accepts three arguments instead 
of two. The third argument is a minimum field width; the converted number must 
be padded with blanks on the left if necessary to make it wide enough.

*/
    char s[MAXLINE];
    int num=50406;
    int padding = 10;
    
    itoa(num, s, padding);
    printf("%i itoa: %s\n", num, s);
    
    return 0;
}

void itoa(int n, char s[], int min_width){
/*

*/
    int base=10;
    int i=0;
    for (i=0; n>0; i++){
        s[i] = (n%base>9)?((n%base)-10 + 'A'):(n%base)+'0';
        n/=base;
    }
    if (i<min_width){
        while (i<min_width){
            s[i++]=' ';
        }
        //i++;
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
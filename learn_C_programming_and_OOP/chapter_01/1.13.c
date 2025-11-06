#include <stdio.h>
/*
Exercise 1-13. Write a program to convert its input to lower case, using a 
function lower(c) which returns c if c is not a letter, and the lower case 
value of c if it is a letter.
*/
// What will the function return?
int lower(int c);

int main(){
    int c;
    while ((c=getchar())!=EOF){
        if ('A'<= c && c <='Z'){
            putchar(lower(c));
        } else {
            putchar(c);
        }
    }
    return 0;
}

int lower(int c){
    int difference = 'a' - 'A';
    return c + difference;
}
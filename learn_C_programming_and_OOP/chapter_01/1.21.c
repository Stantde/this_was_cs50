#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define COLUMNMAX 80

int get_blank(char c);
void get_line(char line[], int lim);


/*
* Exercise 1-21. Write a program to "fold" long input lines after the last non-blank character that occurs before the n-th column of input, where n is a parameter. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

*/
int main() /* find longest line */
{
    char *test = "* Exercise 1-21. Write a program to 'fold' long input lines after the last non-blank character that occurs before the n-th column of input, where n is a parameter. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.";
    // printf("%s", test);
    char line[MAXLINE]; /* current input line */
    char output[MAXLINE]; 
    
    get_line(test, COLUMNMAX);
    get_line(line, COLUMNMAX);    
    return 0;
}
void get_line(char line[], int lim){
    printf("Hi!\n");    
}

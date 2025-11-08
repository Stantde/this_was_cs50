#include <stdio.h>

int main(){
    int i = 0;
    int j = 0;
    for (i; i<10; i++, j++){
        printf("i: %d\tj: %d\n", i,j);        
    }
    return 0;
}
//* Exercise 1-21. Write a program to "fold" long input lines after the last non-blank character that occurs before the n-th column of input, where n is a parameter. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
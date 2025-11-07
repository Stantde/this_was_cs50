#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
int get_line(char s[], int lim);
void copy(char s1[], char s2[]);
void reverse(char s1[], char s2[], int len);
/*
Exercise 1-17. Write a function reverse(s) which reverses the character 
string s. Use it to write a program which reverses its input a line at 
a time.
*/
int main() /* find longest line */
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char save[MAXLINE]; /* longest line, saved */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(line, save);
            reverse(line, save, len);
        }
    if (max < 80) /* there was a line */
        printf("%s\n length: %d\n", save, max);
}

int get_line(char s[], int lim) /* get line into s, return length */
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return(i);
}

void copy(char s1[], char s2[]) /* copy s1 to s2; assume s2 big enough */

{
    int i;

    i = 0;
    while ((s2[i] = s1[i]) != '\0')
        ++i;
}
void reverse(char s1[], char s2[], int len){
    int i;

    i = 0;
    s2[len]='\0';
    while ((s1[i]) != '\0'){
        s2[len-(i+1)] = s1[i];
        ++i;
        
        
    }
}
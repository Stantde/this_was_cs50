#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
get_line(char s[], int lim);
copy(char s1[], char s2[]);
/*
Exercise 1-15. Write a program to print all lines that are longer than 80 
characters.

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
            if (len > 79)
                printf("%s",line)
            copy(line, save);
        }
    if (max < 80) /* there was a line */
        printf("%s", save);
}

get_line(char s[], int lim) /* get line into s, return length */
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

copy(char s1[], char s2[]) /* copy s1 to s2; assume s2 big enough */

{
    int i;

    i = 0;
    while ((s2[i] = s1[i]) != '\0')
        ++i;
}
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define TAB 10
int get_line(char s[], int lim);
void copy(char s1[], char s2[]);
/*
Exercise 1-20. Write the program entab which replaces strings of blanks by the 
minimum number of tabs and blanks to achieve the same spacing. Use the same tab 
stops as for detab.
*/
int main() /* entab */
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
        }
    if (max > 0) /* there was a line */
        printf("%s\n", save);
}

int get_line(char s[], int lim) /* get line into s, return length */
{
    int c, i, b;

    b=0;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){        
        
        if (c == ' '){
            b++;
            if (b==TAB){
                i = i-(b-1);
                c='\t';
            }
        } else {
            b=0;
        }
        s[i] = c;
    }
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
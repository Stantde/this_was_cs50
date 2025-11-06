#include <stdio.h>
// Default program yields line \n length 230 for
// gcc c_026_01.c ;./a.out < index.html >output.txt
// where index is lorem ipsum text.
// Reduce MAXLINE to 200 and observe effect.
// updated...
// gcc c_026_01.c ;./a.out < index.html >output.txt; cat output.txt 
// length is 199last word is deserun, where it had been doloremque!

// Strategy 1: Check last couple indicies for '\n', if not
// found, add len to max and check again?

#define MAXLINE 5
#define TRUE 0
#define FALSE 1
int get_line(char s[], int lim);
void copy(char s1[], char s2[]); 

/*
Exercise 1-14. Revise the main routine of the longest-line program so it will 
correctly print the length of arbitrarily long input lines, and as much as 
possible of the text.
*/
int main() /* find longest line */
{
    int len; /* current line length */
    int max = 0; /* maximum length seen so far */
    int rel_max = 0; /* current max*/
    char line[MAXLINE]; /* current input line */
    char save[MAXLINE]; /* longest line, saved */
    int line_complete = TRUE;
    
    while ((len = get_line(line, MAXLINE)) > 0)
        if ((line[len-1]=='\n' || line[len-2] == '\n') && line_complete == TRUE){
            if (len > rel_max) {
                rel_max = len;
                copy(line, save);
                if (rel_max > max){
                    max = rel_max;                    
                }
                rel_max =0;
            }
        } else if ((line[len-1]=='\n' || line[len-2] == '\n') && line_complete == FALSE){
            rel_max += len;
            copy(line, save);
            line_complete = TRUE;
            if (rel_max > max){
                max = rel_max;
            }
            rel_max =0;
                
    
        } else if (line[len-1]!='\n' && line[len-2] != '\n') {
            rel_max += len; // change to +=            
            line_complete = FALSE;
        }        
    if (max > 0) /* there was a line */
        printf("%s\nlength: %d\n", save, max);
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
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define FALSE 0
#define TRUE 1
int get_line(char s[], int lim);
void copy(char s1[], char s2[]);
void get_rid_of_trailing_blanks(char s[], int index_position);
int get_new_index(char s[], int i);
/*
Exercise 1-16. Write a program to remove trailing blanks and tabs from each 
line of input, and to delete entirely blank lines.
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
        }
    if (max < 80) /* there was a line */
        printf("%s", save);
}

int get_line(char s[], int lim) /* get line into s, return length */
{
    int c, i;
    int trailing_blank_at_end;
    
    trailing_blank_at_end = FALSE;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        s[i] = c;        
        if (c == '\t' || c == ' '){
            trailing_blank_at_end = TRUE;
        } else {
            trailing_blank_at_end = FALSE;
        }

    }
    if (c == '\n') {
        s[i] = c;
        if (trailing_blank_at_end == TRUE){
            // Get rid of all trailing '\t' and ' '
            get_rid_of_trailing_blanks(s, i);
        }
        ++i;
    }
    i = get_new_index(s, i);
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
// Get rid of all trailing '\t' and ' '
void get_rid_of_trailing_blanks(char s[], int index_position){
    // Starting position is '\n'    
    if ((s[index_position] != ' ')&&(s[index_position] != '\t')&&(s[index_position] != '\n')){
        return;
    }
    int previous_index = index_position-1;
    
    if (previous_index < 0){ // continuing to reduce index goes out of index. line is blank.
        s[index_position]='\n';
        return;
    } 
    
    if ((s[previous_index] == ' ')||(s[previous_index] == '\t')){
        s[previous_index] = '\n';
        get_rid_of_trailing_blanks(s, previous_index);
    }
    return;
}
int get_new_index(char s[], int i){
    if (i<0){
        return 1;
    }    
    if (i-1){}
    if (s[i-1] != '\n'){
        return i;
    }
    return get_new_index(s, i-1);
}
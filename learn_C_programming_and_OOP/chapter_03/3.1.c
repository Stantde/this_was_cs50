#include <stdio.h>
#define MAXLINE 1000

void copy(char s1[], char s2[]);
void expand(char s[], char t[]);
int get_line(char s[], int lim);

int main(){
/*
Exercise 3-1. Write a function expand(s, t) which converts characters like 
newline and tab into visible escape sequences like \n and \t as it copies the 
string s to t. Use a switch.
*/  
    char before[MAXLINE], after[2*MAXLINE];

    get_line(before, MAXLINE);
    expand(before, after);
    printf("before\n%s\nafter:\n%s\n", before, after);
    return 0;
}

int get_line(char s[], int lim){
/* get line into s, return length */
    int c, i, b;

    b=0;

    for (i=0; i<lim-1 && (c=getchar())!=EOF /*&& c!='\n'*/; ++i){        
        s[i] = c;
    }
    // if (c == '\n') {
    //     s[i] = c;
    //     ++i;
    // }
    s[i] = '\0';
    return(i);
}

void copy(char s1[], char s2[]){
/* copy s1 to s2*/
    int i;

    i = 0;
    while ((s2[i] = s1[i]) != '\0')
        ++i;
}
void expand(char s[], char t[]){
/*
converts characters like newline and tab into visible escape sequences like \n 
and \t as it copies the string s to t. Use a switch.
*/
    int i, j;
    i=j=0;
        while (s[i] != '\0'){
            switch (s[i]){
                case '\n':
                    t[j]='\\';
                    t[j+1] ='n';
                    j++;
                    break;
                case '\t':
                    t[j]='\\';
                    t[j+1] ='t';
                    j++;
                    break;
                default:
                    t[j]=s[i];
                    break;
            }
            i++;
            j++;
        }
    printf("i: %i, j: %i\n", i, j);
    return;
}
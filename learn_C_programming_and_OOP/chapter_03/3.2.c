#include <stdio.h>
#define MAXLINE 1000

int check(char s[], int i, int max);
void expand(char s[], char t[], int lim);
int get_line(char s[], int lim);

int main(){
/*
Exercise 3-2. Write a function expand(s1 , s2) which expands shorthand 
notations like a-z in the string s1 into the equivalent complete list abc...xyz 
in s2. Allow for letters of either case and digits, and be prepared to handle 
cases like a-b-c and a-z0-9 and -a-z. (A useful convention is that a leading or 
trailing - is taken literally.)
*/  
    char before[MAXLINE], after[26*MAXLINE];

    int before_line_length = get_line(before, MAXLINE);
    expand(before, after, before_line_length);
    printf("before\n%s\nafter:\n%s\n", before, after);
    return 0;
}

int get_line(char s[], int lim){
/* get line into s, return length, where length is also the index of '\0' */
    int c, i, b;
    b=0;
    for (i=0; i<lim-1 && (c=getchar())!=EOF /*&& c!='\n'*/; ++i){       /* Ctrl+D = EOF*/ 
        s[i] = c;
    }
    s[i] = '\0';
    return(i);
}
void expand(char s[], char t[], int lim){
/*
Exercise 3-2. Write a function expand(s1 , s2) which expands shorthand 
notations like a-z in the string s1 into the equivalent complete list abc...xyz 
in s2. Allow for letters of either case and digits, and be prepared to handle 
cases like a-b-c and a-z0-9 and -a-z. (A useful convention is that a leading or 
trailing - is taken literally.)
*/  
/*
Cases for expansion:
a-z, a-Z, A-z, A-Z, a-b-c, a-b-C, a-B-c, a-B-C, A-b-c, A-b-C, A-B-c, A-B-C.
*/
    int i, j;
    i=j=0;
        while (s[i] != '\0'){
            switch (check(s, i, lim)){
                case 0:
                    // jump(s,t)
                    break;
                case 1:
                    break;
                case 2:
                    s[i++]=t[j++];
                    break;                    
                default:
                    printf("Impossible! What happened?!");
                    return;
            }
            
        }
    printf("i: %i, j: %i\n", i, j);
    return;
}
// jump (t or f)// t space = x f space = y indicates return value for adding to index i or j
int check(char s[], int i, int max){
/*
Evaluates the current position and returns an int indicating the switch case,
0, found match partial expansion increase i by 3 on return
1, full expansion increase i by 5 or so
2, none found
base case... impossible? exit safely.
*/
    int outcome = 2;
    if ((s[i] == 'a' ||s[i] == 'A' ) && i+2<max){ // Just enough room for a-z
        // Could indicate start of pattern for expansion.
        if (s[i+1]=='-' && (s[i+2]=='z'||s[i+2]=='Z')){
            // partial expansion confirmed, return to reading from i+=3
            // jump requires current j, and returns new j
            outcome=0;
        }
        else if (s[i+1]=='-' && (s[i+2]=='b'||s[i+2]=='b') &&
                    s[i+3]=='-' && (s[i+4]=='c'||s[i+4]=='C')){
            // found full match
            outcome=1;
        }
    }
    return outcome;
}
#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define LIMIT 1000
/*
Exercise 2-3. Write an alternate version of squeeze(s1, s2) which deletes 
each character in s1 which matches any character in the string s2.

Default:
squeeze(s, c) / delete all c from s /
char s[];
int c;
{
  int i,  j;

  for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
  s[j] = '\0';
}

*/
void squeeze(char s1[],char s2[]);
void generate_str(char s[], char *str);
int main(void){
    char s1[LIMIT], s2[LIMIT];
    char *str = "Hello World!";
    char *letters_to_remove="lr";
    generate_str(s1, str);
    generate_str(s2, letters_to_remove);
    printf("%s\n", s1);
    printf("Removing letters: %s\n", s2);
    squeeze(s1,s2);
    printf("%s\n", s1);    
    return 0;
}
void squeeze(char s1[],char s2[]){
  int i, j, k;
    for (k=0; s2[k] != '\0'; k++){
        for (i = j = 0; s1[i] != '\0'; i++){
            if (s1[i] != s2[k]){
                s1[j++] = s1[i];
            }
        }
    s1[j] = '\0';
    }
    return;
}
void generate_str(char s[], char *str){
    int i=0;
    while(str[i]!='\0'){
        s[i] = str[i];
        i++;
    }
    s[i]='\0';
    
    return;
}
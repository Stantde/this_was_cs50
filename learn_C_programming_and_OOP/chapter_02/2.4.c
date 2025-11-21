#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define LIMIT 1000
/*
Exercise 2-4. Write the function any(s1, s2) which returns the first location 
in the string s1 where any character from the string s2 occurs, or -1 if s1 
contains no characters from s2.
*/
int any(char s1[],char s2[]);
void generate_str(char s[], char *str);
int main(void){
    char s1[LIMIT], s2[LIMIT];
    char *str = "Hello World!";
    char *letters_to_find="z";
    generate_str(s1, str);
    generate_str(s2, letters_to_find);
    printf("%s\n", s1);
    printf("Searching for letters: \"%s\"\n", s2);
    printf("Index of first occurence of a letter from s2 in s1: %i\n", 
        any(s1,s2)
    );
    return 0;
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
/*
Exercise 2-4. Write the function any(s1, s2) which returns the first location 
in the string s1 where any character from the string s2 occurs, or -1 if s1 
contains no characters from s2.
*/
int any(char s1[],char s2[]){
    int index=-1;
    int i, k;
    for (k=0; s2[k] != '\0'; k++){
        for (i = 0; s1[i] != '\0'; i++){
            if (s1[i] == s2[k]){
                return i;
            }
        }
    }
    return index;
}

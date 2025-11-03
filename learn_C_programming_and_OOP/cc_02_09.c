#include <stdio.h>
/* Line Input (safe) */
int main(){
    char line[1000];
    printf("Enter line\n");
    fgets(line, 1000, stdin);
    printf("Line: %s\n", line);    
}
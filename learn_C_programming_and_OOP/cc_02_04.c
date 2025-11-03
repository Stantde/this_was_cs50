#include <stdio.h>
/* Line Input */
int main(){
    char line[1000];
    printf("Enter line\n");
    scanf("%[^\n]1000s", line);
    printf("Line: %s\n", line);    
}
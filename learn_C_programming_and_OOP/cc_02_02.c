#include <stdio.h>
/* Number input */
int main(){
    int usf, euf;
    printf("Enter US Floor\n");
    scanf("%d", &usf);
    euf = usf - 1;
    printf("EU Floor %d\n", euf);
}
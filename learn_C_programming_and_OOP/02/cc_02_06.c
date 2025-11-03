#include <stdio.h>
/* Read A File */
int main(){
    char line[1000];
    FILE *hand;
    hand = fopen("romeo.txt", "r");
    while( fgets(line, 1000, hand) != NULL){
        printf("%s", line);
    }
}
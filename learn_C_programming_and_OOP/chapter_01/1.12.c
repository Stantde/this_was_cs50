/*
Exercise 1-12. Write a program to print a histogram of the lengths of words in 
its input. It is easiest to draw the histogram horizontally; a vertical 
orientation is more challenging.

Ok... Initial thoughts, int for length of words... int for number of words which 
are l length... then final for l +...

*/
#include <stdio.h>
#define MAX_LENGTH 10
#define TRUE 1
#define FALSE 0
#define SPACE 0x20

int main(){
    int current_character;
    int is_word = FALSE; //is_seq_of_lttrs_dgts_apos
    int length_of_word;
    /* 
    num_of_words[0] represents words of length =1... num_of_words[9] 
    represent words of length 10 +.
    */
    int num_of_words[MAX_LENGTH];
    
    for (int i=0; i<MAX_LENGTH; i++){
        num_of_words[i]=0;
    }

    //get words, and count length.
    while((current_character = getchar()) != EOF){
        if ((is_word == FALSE && ('A' <=current_character && current_character<='Z'))||
            (is_word == FALSE && ('a' <= current_character && current_character <= 'z'))){
            is_word = TRUE;
            length_of_word=1;
        } else if ((is_word == TRUE && !((current_character >= '0' && current_character <= '9')||
            (current_character >= 'A' && current_character <='Z')||
            (current_character >= 'a' && current_character <= 'z')||
            (current_character == '\'')))) {
            is_word = FALSE;
                if (length_of_word >= 10){
                    num_of_words[9]++;
                } else {
                    num_of_words[length_of_word-1]++;

                }
            length_of_word=0;
                
        } else if (is_word==TRUE){
            length_of_word++;
        }
        




    }


    // Printing histogram at end of program execution
    for (int i=0; i<MAX_LENGTH; i++){
        printf("words of length %d", i+1);
        if (i==MAX_LENGTH-1)
            printf("+");
        for (int j= 0; j<num_of_words[i]; j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
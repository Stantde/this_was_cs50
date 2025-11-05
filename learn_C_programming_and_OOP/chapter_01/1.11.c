#include <stdio.h>

/* 
Exercise 1-11. Revise the word count program to use a better definition of 
"word," for example, a sequence of letters, digits and apostrophes that begins 
with a letter.

It's time to take a break.
*/
int main(){
    int current_character, new_word, word_count= 0;
    while((current_character = getchar()) != EOF){
        // if current character is a letter, new_word increases.
        if (current_character >= 0x30)
        // put char
        
            putchar(current_character);
    }
    return 0;
}
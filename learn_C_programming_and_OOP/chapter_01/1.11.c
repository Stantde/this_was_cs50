#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define SPACE 0x20
#define APOSTROPHE 0x27
#define ZERO 0x30
#define NINE 0x39
#define UPPERCASE_A 0x41
#define UPPERCASE_Z 0x5A
#define LOWERCASE_A 0x61
#define LOWERCASE_Z 0x7A
/* 
Exercise 1-11. Revise the word count program to use a better definition of 
"word," for example, a sequence of letters, digits and apostrophes that begins 
with a letter.

ASCII reference table: https://www.ascii-code.com/
{SPACE} = 0x20
{'} = 0X27
{0-9} = 0x30 - 0x39
{A-Z} = 0x41 - 0x5A
{a-z} = 0X61 - 0X7A

It's time to take a break.
*/

// Example strings: This is a series of words.
int main(){
    int current_character;
    int is_seq_of_lttrs_dgts_apos = FALSE;
    int word_count= 0;
    while((current_character = getchar()) != EOF){
        if ((is_seq_of_lttrs_dgts_apos == FALSE && (UPPERCASE_A <=current_character && current_character<=UPPERCASE_Z))||
            (is_seq_of_lttrs_dgts_apos == FALSE && (LOWERCASE_A <= current_character && current_character <= LOWERCASE_Z))){
            is_seq_of_lttrs_dgts_apos = TRUE;
            word_count++;
        }
        if ((is_seq_of_lttrs_dgts_apos == TRUE && !((current_character >= ZERO && current_character <= NINE)||
            (current_character >= UPPERCASE_A && current_character <=UPPERCASE_Z)||
            (current_character >= LOWERCASE_A && current_character <= LOWERCASE_Z)||
            (current_character == APOSTROPHE)))) {
            is_seq_of_lttrs_dgts_apos = FALSE;
        }
        putchar(current_character);            
    }
    printf("Number of words: %d\n", word_count);
    return 0;
}
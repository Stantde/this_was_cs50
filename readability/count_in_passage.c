/*
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words
is an average of about 464.29 letters per 100 words (because 65 / 14 * 100 = 464.29). And 4
sentences per 14 words is an average of about 28.57 sentences per 100 words
(because 4 / 14 * 100 = 28.57). Plugged into the Coleman-Liau formula, and rounded to the nearest
integer, we get an answer of 3 (because 0.0588 * 464.29 - 0.296 * 28.57 - 15.8 = 3): so this
passage is at a third-grade reading level.
*/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    string passage = "Harry Potter was a ";
    char letters_sentences_words = 'W';
    int count_of = 0;
    if(letters_sentences_words =='W')
    {
        count_of++;
    }
    int i = 0;
    while (passage[i] != '\0')
    {
        if (letters_sentences_words =='L')
        {
            if isalpha(passage[i])
            {
                count_of++;
            }
        }
        else if (letters_sentences_words =='S')
        {
            if (passage[i] == '.' || passage[i] == '?' || passage[i] == '!')
            {
                count_of++;
            }
        }
        else if(letters_sentences_words =='W')
        {
            if (passage[i] == ' ')
            count_of++;
        }
        i++;
    }
    //loop through passage and count letters.
    //return count_of;
    printf("count of %c: %i\n", letters_sentences_words, count_of);
}

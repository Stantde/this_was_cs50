/*
A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text.
One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level
that is needed to understand some text.
*/

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

float average_per_100_words(int input, int words);
void compute_coleman_readability(float L, float S);
int count_in_passage(string passage, char letters_sentences_words);

int main(void)
{
    string passage = get_string("Input passage: ");
    char letters_sentences_words[3] = {'L', 'S', 'W'};
    int letters_in_passage = count_in_passage(passage, letters_sentences_words[0]);
    int sentences_in_passage = count_in_passage(passage, letters_sentences_words[1]);
    int words_in_passage = count_in_passage(passage, letters_sentences_words[2]);
    float L = average_per_100_words(letters_in_passage, words_in_passage);
    float S = average_per_100_words(sentences_in_passage, words_in_passage);
    compute_coleman_readability(L, S);
}
int count_in_passage(string passage, char letters_sentences_words)
{
    int count_of = 0;
    if (letters_sentences_words == 'W')
    {
        count_of++;
    }
    int i = 0;
    while (passage[i] != '\0')
    {
        if (letters_sentences_words == 'L')
        {
            if isalpha (passage[i])
            {
                count_of++;
            }
        }
        else if (letters_sentences_words == 'S')
        {
            if (passage[i] == '.' || passage[i] == '?' || passage[i] == '!')
            {
                count_of++;
            }
        }
        else if (letters_sentences_words == 'W')
        {
            if (passage[i] == ' ')
                count_of++;
        }
        i++;
    }
    return count_of;
}
float average_per_100_words(int input, int words)
{
    float one_hundred = 100.00;
    return (one_hundred * input / words);
}
void compute_coleman_readability(float L, float S)
{
    int index;
    index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
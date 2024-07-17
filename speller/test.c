#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DICTIONARY "dictionaries/large"

const int MAX_WORD_SIZE = 45;

int count_of_words(FILE *input);
void factors_of(int number);
float find_average(FILE *input, int total_word_count);

int main(void)
{
    // Load dictionary
    FILE *infile = fopen(DICTIONARY, "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }
    // count number of words total
    int count = count_of_words(infile); // 143091
    //factors_of(count);//{1, 3, 9, 13, 39, 117, 1223, 3669, 11007, 15899, 47697}
    //float average_letters_per_word = find_average(infile, count);// Returns 9.05813110
    fclose(infile);
    //printf("Number of words: %f\n", average_letters_per_word);
    printf("Number of words: %i\n", count);
}

// Returns the number of words in the input file
int count_of_words(FILE *input)
{
    char buffer[MAX_WORD_SIZE];
    int count = 0;
    while (fscanf(input, "%s", buffer) == 1)
    {
        // If first letter is capitalized, increase count.
        if ( buffer[0] < 96)
        {
            count++;
        }
    }
    return count;

}

// Finds the factors of the int passed to the function and prints them.
void factors_of(int number)
{
    // How do I store a list of factors? I could print them as I find them...
    /*
    Consider 10(number)
    factors are {1, 2, 5, 10}
    Let's loop through every int between 1 and midpoint (10(number) / 2).
    when i is 1, I should print i, because the other factor is 10.
    // see this through:I know this because, the number divided by 1 then multiplied by itself is the number
    next up is 2.
    when 10 is divided by two the result is 5. 5 times two is ten.
    this is a property unique to int data types in C.
    when 10 is divided by 3, the result is 3. however, 3 times 3 is 9, not ten.
    in slightly more formal language:
    the number (ten) is dvided by i to get a quotient. When the quotient is then multiplied by
    i, the result MUST be the number, or it is not a prime.
    */
    for (int i = 1; i <= number / 2; i++)
    {
        int quotient = number / i;
        if ((quotient * i) == number)
        {
            // Print quotient and i
            printf("factors found: %i, %i\n\n", i, quotient);
        }
    }
    return;
}

// The returns the average number of letters per word.
float find_average(FILE *input, int total_word_count)
{
    /*
    The average number of letters may be difficult to accurately compute directly, so this
    function serves as a work around. First, I will attempt the direct method.

    Direct Method:
    The average number of letters is defined as the total number of letters divided by the total
    number of words, times 100.
    That is: average_letters = total_letter_count / total_word_count * 100.
*/
    // Obtain total letter count
    char buffer[MAX_WORD_SIZE];
    double total_letter_count = 0;
    while (fscanf(input, "%s", buffer) == 1)
    {
        total_letter_count += strlen(buffer);
    }
    return (float) total_letter_count / total_word_count ;
    // Returns 9.05813110
    // This actually worked. I'm not bothering with the indirect method.
}
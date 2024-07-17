#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    printf("Player 1's word: %s earned %i points!\n", word1, score1);
    printf("Player 2's word: %s earned %i points!\n", word2, score2);
}
// Compute and return score for string
int compute_score(string word)
{
    int i = 0, running_tally = 0;
    while (word[i] != '\0')
    {
        if (isalpha(word[i]))
        {
            int special = toupper(word[i]) - 65;
            // printf("Letter: %i\nPoints: %i\n", special, POINTS[special]);
            running_tally += POINTS[special];
        }
        else
        {
            running_tally += 0;
        }
        i++;
    }
    return running_tally;
}

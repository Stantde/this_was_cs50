#include <cs50.h>
#include <stdio.h>

int prompt_for_start_size(void);
int prompt_for_end_size(int a);
int number_of_years(int b, int c);
const int MINIMUM_POPULATION_SIZE = 9;

int main(void)
{
    int start = prompt_for_start_size();    // Prompt for start size
    int end = prompt_for_end_size(start);    //  Prompt for end size
    int years = number_of_years(start, end);    // Calculate number of years until we reach threshold
    printf("\nUnder current conditions, it will take %i years to reach the end population.\n", years);    // Print number of years
}

int prompt_for_start_size(void)
{
    int start;
    do
    {
        printf("Please enter the initial population size for the llamas. \n");
        start = get_int("Number must be greater than 8!): ");
    }
    while (start < MINIMUM_POPULATION_SIZE);
    return start;
}

int prompt_for_end_size(int a)
{
    int end;
    do
    {
        printf("\nPlease enter the final population size for the llamas. \n");
        end = get_int("Number must be greater than or equal to the starting size!): ");
    }
    while (end < a);
    return end;
}

int number_of_years(int b, int c)
{
    int n = b; // Number of llamas.
    int birth_rate = 3;
    int death_rate = 4;
    int count_of_years = 0;

    while (n < c)
    {
        n = n + (n/birth_rate) - (n/death_rate);
        count_of_years++;
    }
    return count_of_years;
}


/*
* Deepen an understanding of strings
* Practice creating recursive functions
*/
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);
string remove_last_char(string input, int los);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    // Verify input is a number by checking every character in the input string.
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}
/*
// This works with loops.
int convert(string input)
{
    int string_length = strlen(input);
    int string_to_key[string_length];
    int key = 0;
    int power_of_ten = 1;
    int i = 0;
    while (input[i] != '\0')
    {
        string_to_key[string_length - i - 1] = input[i] - 48;
        i++;
    }

    for (i = 0; i < string_length; i++, power_of_ten *= 10)
    {
        key += string_to_key[i] * power_of_ten;
    }
    return key;
}
*/
// Now try recursion!
int convert(string input)
{
    int converted_from_string = 0;
    int length_of_str = strlen(input);
    if (strlen(input) >= 1)
    {
        converted_from_string = input[length_of_str - 1] - 48;
        input = remove_last_char(input, length_of_str);
        converted_from_string += 10 * convert(input);
    }
    return converted_from_string;
}
string remove_last_char(string input, int los)
{
    input[los - 1] = '\0';
    return input;
}
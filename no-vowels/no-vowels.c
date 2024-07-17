#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
string replace(string input);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Command-Line argument required.\n");
        return 1;
    }
    else
    {
        printf("%s\n", replace(argv[1]));
    }
}
// This function will change the following vowels to numbers: a becomes 6, e becomes 3, i becomes 1, o becomes 0 and u does not
// change.
string replace(string input)
{
    string output = input;
    int i = 0;
    while (input[i] != '\0')
    {
        switch (tolower(input[i]))
        {
            case 'a':
                input[i] = '6';
                break;
            case 'e':
                input[i] = '3';
                break;
            case 'i':
                input[i] = '1';
                break;
            case 'o':
                input[i] = '0';
                break;
        }
        i++;
    }
    return output;
}
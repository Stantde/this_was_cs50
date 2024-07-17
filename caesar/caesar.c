#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int assign_to_key(string input);
void encrypt(string pt, int key);
int fail_test(int c, string v);

int main(int argc, string argv[])
{
    int fail_state = fail_test(argc, argv[1]);
    if (fail_state != 0)
    {
        return fail_state;
    }
    int key = assign_to_key(argv[1]);
    string plain_text = get_string("plaintext : ");
    encrypt(plain_text, key);
}
int fail_test(int c, string v)
{
    if (c != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (c == 2)
    {
        int i = 0;
        while (v[i] != '\0')
        {
            if (!isdigit(v[i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            i++;
        }
    }
    return 0;
}
int assign_to_key(string input)
{
    // create int array
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
void encrypt(string pt, int key)
{
    int i = 0;
    const int NUMBER_OF_LETTERS = 26;
    const int UPPER = 65;
    const int LOWER = 97;
    printf("ciphertext: ");
    while (pt[i] != '\0')
    {
        if (isupper(pt[i]))
        {
            printf("%c", ((pt[i] - UPPER + key) % NUMBER_OF_LETTERS) + UPPER);
        }
        else if (islower(pt[i]))
        {
            printf("%c", ((pt[i] - LOWER + key) % NUMBER_OF_LETTERS) + LOWER);
        }
        else
        {
            printf("%c", pt[i]);
        }
        i++;
    }
    printf("\n");
}
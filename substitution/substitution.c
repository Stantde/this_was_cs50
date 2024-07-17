#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void ciphertext(string key, string plain_text);
bool is_duplicate(char test, string reference, int test_index);
int key_validation(int c, string v);

int main(int argc, string argv[])
{
    int validation_result = key_validation(argc, argv[1]);
    if (validation_result != 0)
    {
        return validation_result;
    }
    string key = argv[1];
    string plain_text = get_string("plaintext: ");
    ciphertext(key, plain_text);
}
int key_validation(int c, string v)
{
    if (c != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (c == 2)
    {
        if (strlen(v) != 26)
        {
            printf("Invalid length of key. Must be 26 letters long!\n");
            return 1;
        }
        int i = 0;
        while (v[i] != '\0')
        {
            if (isalpha(v[i]))
            {
                v[i] = toupper(v[i]);
            }
            else
            {
                printf("Key must consist of letters only!\n");
                return 1;
            }
            if (is_duplicate(v[i], v, i))
            {
                printf("All values of array must be unique!\n");
                return 1;
            }
            i++;
        }
    }
    return 0;
}
bool is_duplicate(char test, string reference, int test_index)
{
    for (int i = 0; i < strlen(reference); i++)
    {
        if (i == test_index)
        {
            i++;
        }
        if (test == reference[i])
        {
            return true;
        }
    }
    return false;
}
void ciphertext(string key, string plain_text)
{
    printf("ciphertext: ");
    int i = 0;
    while (plain_text[i] != '\0')
    {
        int j;
        if (isupper(plain_text[i]))
        {
            j = plain_text[i] - 65;
            printf("%c", (key[j]));
        }
        else if (islower(plain_text[i]))
        {
            j = plain_text[i] - 97;
            printf("%c", (key[j]) + 32);
        }
        else
        {
            printf("%c", plain_text[i]);
        }
        i++;
    }
    printf("\n");
}
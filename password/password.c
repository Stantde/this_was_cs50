// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// You are to complete the function, valid,
// which returns true if the password passes all criteria, and false if it does not.
// TODO: Complete the Boolean function below
bool valid(string password)
{
    int i = 0;
    bool uppr = false, lwr = false, num = false, sym = false;
    while (password[i] != '\0')
    {
        if (isupper(password[i]))
        {
            uppr = true;
            printf("Upper found\n");
            i++;
            continue;
        }
        else if (islower(password[i]))
        {
            lwr = true;
            printf("lower found\n");
            i++;
            continue;
        }
        else if (isdigit(password[i]))
        {
            num = true;
            printf("digit found\n");
            i++;
            continue;
        }
        else if (!isalnum(password[i]))
        {
            sym = true;
            printf("symbol found\n");
            i++;
            continue;
        }
        i++;
    }
    if (uppr && lwr && num && sym)
    {
        return true;
    }
    return false;
}

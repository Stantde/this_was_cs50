#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

// int pdf[4] = {37, 80, 68, 70};

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    // Open file.
    FILE *file = fopen(argv[1], "r");

    // Check file exists.
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t buffer[4];
    uint8_t signature[4] = {37, 80, 68, 70};

    fread(buffer, 1, 4, file);

    // Check file is .pdf
    for (int i = 0; i < 4; i++)
    {
        if(buffer[i] != signature[i])
        {
            printf("Likely not a .pdf.\n");
            fclose(file);
            return 0;
        }
    }

    printf("Likely a .pdf.\n");
    fclose(file);
    return 0;
}
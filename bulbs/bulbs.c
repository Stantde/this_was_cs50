#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void convert_dec_to_bin(int c);

int main(void)
{
    string input = get_string("Please enter string: ");
    int i = 0;
    while (input[i] != '\0')
    {
        int c = input[i];
        convert_dec_to_bin(c);
        printf("\n");
        i++;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
void convert_dec_to_bin(int c)
{
    int byte[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int max_val = 128;
    for (int i = 0; i < BITS_IN_BYTE; i++, max_val /= 2)
    {
        if (c == 0)
        {
            byte[i] = 0;
        }
        else if (c - max_val >= 0)
        {
            c -= max_val;
            byte[i] = 1;
        }
        print_bulb(byte[i]);
    }
}
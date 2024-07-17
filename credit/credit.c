/*Design program to check validity of credit card number and tell if it is AMEX, MC, or VISA.*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

void cardtype(int ltd, int card_length);
bool chksumpass(long card);
bool isAMEX(int first_two_digits, int card_length);
bool isMC(int first_two_digits, int card_length);
bool isVISA(int first_two_digits, int card_length);
int last_two_digits(long card);
int longlen(long card);

int main(int argc, string argv[])
{
    long card_number = get_long("input credit card number: ");
    if (!chksumpass(card_number))
    {
        cardtype(last_two_digits(card_number), longlen(card_number));
    }
    else
    {
        printf("INVALID\n");
    }
}
int sum_of_two_digits(remainder)
{
    int sum = 0;
    sum += remainder % 10;
    remainder = (remainder - remainder % 10) / 10;
    sum += remainder % 10;
    return sum;
}
// Test check sum of card by Luhn’s algorithm.
bool chksumpass(long card)
{
    int counter = 0;
    int doubled_sum = 0;
    int remainder;
    int normal_sum = 0;
    long reduced_card = card;
    while (reduced_card > 0)
    {
        if (counter % 2 == 0)
        {
            remainder = reduced_card % 10;
            reduced_card = (reduced_card - remainder) / 10;
            normal_sum += remainder;
            counter++;
        }
        if (counter % 2 == 1 && reduced_card > 0)
        {
            remainder = reduced_card % 10;
            reduced_card = (reduced_card - remainder) / 10;
            if (2 * remainder >= 10)
            {
                doubled_sum += sum_of_two_digits(2 * remainder);
            }
            else
            {
                doubled_sum += 2 * remainder;
            }
            counter++;
        }
    }
    return (normal_sum + doubled_sum) % 10;
}
int last_two_digits(long card)
{
    int counter = 0, doubled_sum = 0, normal_sum = 0;
    int last_two_digits, remainder;
    long reduced_card = card;
    while (reduced_card > 99)
    {
        if (counter % 2 == 0)
        {
            remainder = reduced_card % 10;
            reduced_card = (reduced_card - remainder) / 10;
            normal_sum += remainder;
            counter++;
        }
        if (counter % 2 == 1 && reduced_card > 99)
        {
            remainder = reduced_card % 10;
            reduced_card = (reduced_card - remainder) / 10;
            counter++;
        }
    }
    return (reduced_card % 100);
}

bool isAMEX(int first_two_digits, int card_length)
{
    if (card_length == 15)
    {
        if (first_two_digits == 34 || first_two_digits == 37)
        {
            return 1;
        }
    }
    return 0;
}

bool isMC(int first_two_digits, int card_length)
{
    if (card_length == 16)
    {
        if ((first_two_digits - first_two_digits % 10) / 10 == 5)
        {
            if (0 < first_two_digits % 10 && first_two_digits % 10 < 6)
            {
                return 1;
            }
        }
    }
    return 0;
}

bool isVISA(int first_two_digits, int card_length)
{
    first_two_digits = (first_two_digits - first_two_digits % 10) / 10;
    if (card_length == 16 || card_length == 13)
    {
        if (first_two_digits == 4)
        {
            return 1;
        }
    }
    return 0;
}

int longlen(long reduced_card)
{
    int counter = 0;
    int remainder;
    while (reduced_card > 0)
    {
        remainder = reduced_card % 10;
        reduced_card = (reduced_card - remainder) / 10;
        counter++;
    }
    return counter;
}
void cardtype(int ltd, int card_length)
{
    if (isAMEX(ltd, card_length))
    {
        printf("AMEX\n");
    }
    else if (isMC(ltd, card_length))
    {
        printf("MASTERCARD\n");
    }
    else if (isVISA(ltd, card_length))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
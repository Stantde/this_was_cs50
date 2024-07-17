#!/usr/local/bin/python
# chmod a+x mario.py


'''
This is CS50x 2024. 🎉 Curious how your 2023 work counts toward the 2024 course? See our FAQs if you started
in 2023 or earlier. Interested in a verified certificate, a professional certificate, or transfer credit and
accreditation?

This is CS50
CS50’s Introduction to Computer Science
OpenCourseWare

Donate

David J. Malan
malan@harvard.edu
Facebook GitHub Instagram LinkedIn Reddit Threads Twitter

Ready Player 50
Zoom Meetingsnew
CS50.ai
Ed Discussion for Q&A
Visual Studio Code
CS50 Educator Workshop
CS50x Puzzle Day 2024
Gallery of Final Projects🖼️
What’s new for 2024?
Week 0 Scratch
Week 1 C
Week 2 Arrays
Week 3 Algorithms
Week 4 Memory
CS50 Python
CS50 Scratch
CS50 SQL
CS50 Technology
CS50 Web
Harvard Shop

License

2024-02-24 15:59:12

Credit
Problem to Solve
In a filed called credit.py in a folder called sentimental-credit, write a program that prompts
the user for a credit card number and then reports (via print) whether it is a valid American Express,
MasterCard, or Visa card number, exactly as you did in Problem Set 1. Your program this time should be
written in Python!

Demo

Specification
So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n
or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less.
For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as
might be printed on an actual card).
Best to use get_int or get_string from CS50’s library to get users’ input, depending on how you to decide
to implement this one.
Hints
It’s possible to use regular expressions to validate user input. You might use Python’s re module, for
example, to check whether the user’s input is indeed a sequence of digits of the correct length.
How to Test
While check50 is available for this problem, you’re encouraged to first test your code on your own for
each of the following.

Run your program as python credit.py, and wait for a prompt for input. Type in 378282246310005 and press
enter. Your program should output AMEX.
Run your program as python credit.py, and wait for a prompt for input. Type in 371449635398431 and press
enter. Your program should output AMEX.
Run your program as python credit.py, and wait for a prompt for input. Type in 5555555555554444 and press
enter. Your program should output MASTERCARD.
Run your program as python credit.py, and wait for a prompt for input. Type in 5105105105105100 and press
enter. Your program should output MASTERCARD.
Run your program as python credit.py, and wait for a prompt for input. Type in 4111111111111111 and press
enter. Your program should output VISA.
Run your program as python credit.py, and wait for a prompt for input. Type in 4012888888881881 and press
enter. Your program should output VISA.
Run your program as python credit.py, and wait for a prompt for input. Type in 1234567890 and press enter.
Your program should output INVALID.
Correctness
check50 cs50/problems/2024/x/sentimental/credit
Style
style50 credit.py
How to Submit
submit50 cs50/problems/2024/x/sentimental/credit
Why does my submission pass check50, but shows “No results” in my Gradebook after running submit50?

In some cases, submit50 may not grade the assignment due to inconsistent formatting in your credit.py file. To fix this issue, run black credit.py in the sentimental-credit folder. Address any issues that are revealed. Run check50 again to ensure your submission still functions. Finally, run the submit50 command above again. Your result will appear in your Gradebook within a few minutes.

Please note that if there is a numerical score next to your credit submission in the submissions area of your Gradebook, the procedure discussed above does not apply to you. Likely, you have not fully addressed the requirements of the problem set and should rely upon check50 for clues as to what work remains.


This is CS50x 2024. 🎉 Curious how your 2023 work counts toward the 2024 course? See our FAQs if you started in 2023 or earlier. Interested in a verified certificate, a professional certificate, or transfer credit and accreditation?

This is CS50
CS50’s Introduction to Computer Science
OpenCourseWare

Donate

David J. Malan
malan@harvard.edu
Facebook GitHub Instagram LinkedIn Reddit Threads Twitter

Ready Player 50
Zoom Meetingsnew
CS50.ai
Ed Discussion for Q&A
Visual Studio Code
CS50 Educator Workshop
CS50x Puzzle Day 2024
Gallery of Final Projects🖼️
What’s new for 2024?
Week 0 Scratch
Week 1 C
Week 2 Arrays
Week 3 Algorithms
Week 4 Memory
Week 5 Data Structures
Week 6 Python
Week 6.5 Artificial Intelligence
Week 7 SQL
Week 8 HTML, CSS, JavaScript
Week 9 Flask
Week 10 Cybersecurity
Additional Practice
Final Project
Gallery of Final Projects🖼️
Seminars
Academic Honesty
CS50 Certificate
FAQs
Gradebook
Staff
Syllabus
Apple TV
edX
Google TV
Harvard Extension School
Harvard Summer School
YouTube
Manual Pages
Style Guide
Status Page
Communities
Bluesky
Clubhouse
Discord Q&A
Ed Q&A
Facebook Group Q&A
Facebook Page
GitHub
Gitter Q&A
Instagram
LinkedIn Group
LinkedIn Page
Medium
Quora
Reddit Q&A
Slack Q&A
Snapchat
SoundCloud
Stack Exchange Q&A
TikTok
Twitter Account
Twitter Community
YouTube
Courses
CS50x
CS50 AI
CS50 Business
CS50 Cybersecurity
CS50 for Lawyers
CS50 Games
CS50 Python
CS50 Scratch
CS50 SQL
CS50 Technology
CS50 Web
Harvard Shop

License

2024-02-24 15:59:11

Credit
Person holding credit cards

Problem to Solve
A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um, a quadrillion.)

Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

In a file called credit.c in a folder called credit, implement a program in C that checks the validity of a given credit card number.

Luhn’s Algorithm
So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

4003600000000014

Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.

Implementation Details
In the file called credit.c in the credit directory, write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have leading zeroes. But do not assume that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input. (Why?)

Consider the below representative of how your own program should behave when passed a valid credit card number (sans hyphens).

$ ./credit
Number: 4003600000000014
VISA
Now, get_long itself will reject hyphens (and more) anyway:

$ ./credit
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA
But it’s up to you to catch inputs that are not credit card numbers (e.g., a phone number), even if numeric:

$ ./credit
Number: 6176292929
INVALID
Test out your program with a whole bunch of inputs, both valid and invalid. (We certainly will!) Here are a few card numbers that PayPal recommends for testing.

If your program behaves incorrectly on some inputs (or doesn’t compile at all), time to debug!

Walkthrough

How to Test Your Code
You can also execute the below to evaluate the correctness of your code using check50. But be sure to compile and test it yourself as well!

Correctness
In your terminal, execute the below to check your work’s correctness.

check50 cs50/problems/2024/x/credit
Style
Execute the below to evaluate the style of your code using style50.

style50 credit.c
How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2024/x/credit

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
'''
AMEX = ['34', '37']
MASTERCARD = ['51', '52', '53', '54', '55']
VISA = ['4']


def main():
    '''
    discussion on card number, to collect as str, or collect as int?
    Though the card number is a number, I don't intend to do math with the entire number
    Instead, any math will be performed on the digit. The card number will be collected as a str,
    then each digit will e checked to ensure they are numberical.
    '''
    card_number = input("Input credit card number: ")
    card_type = c_type(card_number)
    print(card_type)
    ...

# Test check sum of card by Luhn’s algorithm.


def chksumpass(card_number):
    valid_number = False
    # Check that each digit of the str is a number.
    if not card_number.isdecimal():
        # If not, return.
        return valid_number
    # Go through each in reverse order digit, if odd add number to sum. if even, double then add number to sum
    card_number = card_number[::-1]
    check_sum = 0
    for digit in range(len(card_number)):
        if digit % 2 == 1:
            product = 2 * int(card_number[digit])
            # if product has two digits, get sum of both digits
            if product > 9:
                product = int(str(product)[0]) + int(str(product)[1])
            check_sum = check_sum + product
        else:
            check_sum = check_sum + int(card_number[digit])
    if check_sum % 10 == 0:
        valid_number = True
    return valid_number

# print type of card


def c_type(card_number):
    card_type = "INVALID"
    if chksumpass(card_number):
        # determine type
        first_two_digits = card_number[0:2]
        card_length = len(card_number)
        if first_two_digits in AMEX and card_length == 15:
            card_type = "AMEX"
        elif first_two_digits in MASTERCARD and card_length == 16:
            card_type = "MASTERCARD"
        elif first_two_digits[0] in VISA and (card_length == 13 or card_length == 16):
            card_type = "VISA"

    return card_type


if __name__ == '__main__':
    main()

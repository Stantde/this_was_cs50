#!/usr/bin/python3
# don't include the <>
# chmod a+x <file>
'''

Interested in a verified certificate or a professional certificate?

CS50’s Introduction to Programming with Python
OpenCourseWare

Donate

David J. Malan
malan@harvard.edu
Facebook GitHub Instagram LinkedIn Reddit Threads Twitter

Ready Player 50new
Zoom Meetingsnew
Functions, Variables
Conditionals
Loops
Exceptions
Libraries
Unit Tests
File I/O
Regular Expressions
Object-Oriented Programming
Et Cetera
Academic Honesty
CS50 Certificate
FAQs
Gradebook
Shorts
Ed Discussion for Q&A
Quick Start Guide
Apple TV
edX
Google TV
YouTube
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
Twitter
YouTube
Harvard Shop

License

Coke Machine
CS50 Coke Bottle
Suppose that a machine sells bottles of Coca-Cola (Coke) for 50 cents and only accepts coins in these denominations: 25 cents, 10 cents, and 5 cents.

In a file called coke.py, implement a program that prompts the user to insert a coin, one at a time, each time informing the user of the amount due. Once the user has inputted at least 50 cents, output how many cents in change the user is owed. Assume that the user will only input integers, and ignore any integer that isn’t an accepted denomination.

Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir coke
to make a folder called coke in your codespace.

Then execute

cd coke
to change directories into that folder. You should now see your terminal prompt as coke/ $. You can now execute

code coke.py
to make a file called coke.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python coke.py. At your Insert Coin: prompt, type 25 and press Enter. Your program should output:
Amount Due: 25
and continue prompting the user for coins.

Run your program with python coke.py. At your Insert Coin: prompt, type 10 and press Enter. Your program should output:
Amount Due: 40
and continue prompting the user for coins.

Run your program with python coke.py. At your Insert Coin: prompt, type 5 and press Enter. Your program should output:
Amount Due: 45
and continue prompting the user for coins.

Run your program with python coke.py. At your Insert Coin: prompt, type 30 and press Enter. Your program should output:
Amount Due: 50
because the machine doesn’t accept 30-cent coins! Your program should then continue prompting the user for coins.

Run your program with python coke.py. At your Insert Coin: prompt, type 25 and press Enter, then type 25 again and press Enter. Your program should halt and display:
Change Owed: 0
Run your program with python coke.py. At your Insert Coin: prompt, type 25 and press Enter, then type 10 and press Enter. Type 25 again and press Enter, after which your program should halt and display:
Change Owed: 10
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/coke
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

Hint
Be careful to print the prompts and responses exactly as shown above. If your program prints any extra text, it may fail check50.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/coke
'''
def main():
    COINS = [25, 10, 5]
    coke_price = 50
    while coke_price > 0:
        print(f"Amount Due: {coke_price}")
        coin_deposited = int(input('Insert Coin: '))
        if coin_deposited in COINS:
            coke_price -= coin_deposited
        else:
            continue
    print(f'Change Owed: {coke_price * (-1)}')
    ...


if __name__ == '__main__':
    main()
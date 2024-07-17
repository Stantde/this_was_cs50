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

Felipe’s Taqueria
Felipe's Taqueria
One of the most popular places to eat in Harvard Square is Felipe’s Taqueria, which offers a menu of entrees, per the dict below, wherein the value of each key is a price in dollars:

{
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}
In a file called taqueria.py, implement a program that enables a user to place an order, prompting them for items, one per line, until the user inputs control-d (which is a common way of ending one’s input to a program). After each inputted item, display the total cost of all items inputted thus far, prefixed with a dollar sign ($) and formatted to two decimal places. Treat the user’s input case insensitively. Ignore any input that isn’t an item. Assume that every item on the menu will be titlecased.

Hints
Note that you can detect when the user has inputted control-d by catching an EOFError with code like:
try:
    item = input()
except EOFError:
    ...
You might want to print a new line so that the user’s cursor (and subsequent prompt) doesn’t remain on the same line as your program’s own prompt.

Inputting control-d does not require inputting Enter as well, and so the user’s cursor (and subsequent prompt) might thus remain on the same line as your program’s own prompt. You can move the user’s cursor to a new line by printing \n yourself!
Note that a dict comes with quite a few methods, per docs.python.org/3/library/stdtypes.html#mapping-types-dict, among them get, and supports operations like:
d[key]
and

if key in d:
    ...
wherein d is a dict and key is a str.

Be sure to avoid or catch any KeyError.
Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir taqueria
to make a folder called taqueria in your codespace.

Then execute

cd taqueria
to change directories into that folder. You should now see your terminal prompt as taqueria/ $. You can now execute

code taqueria.py
to make a file called taqueria.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python taqueria.py. Type Taco and press Enter, then type Taco again and press Enter. Your program should output:
Total: $6.00
and continue prompting the user until they input control-d.

Run your program with python taqueria.py. Type Baja Taco and press Enter, then type Tortilla Salad and press enter. Your program should output:
Total: $12.00
and continue prompting the user until they input control-d.

Run your program with python taqueria.py. Type Burger and press Enter. Your program should reprompt the user.
Be sure to try other foods and vary the casing of your input. Your program should behave as expected, case-insensitively.

You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/taqueria
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/taqueria
'''
import sys

MENU = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def main():
    # Enable a user to place an order, prompting them for items, one per line, until the user inputs control-d? (ctrl + c?)
    order = get_order()
    print_total(order)
    sys.exit(0)
    ...

def get_order():
    # Prompts user for their order, one line at a time
    order = []
    running_total = 0.00
    try:
        while True:
            order_item = input("Item: ").title()
            if verify_item(order_item):
                order.append(order_item)
                # After each inputted item, display the total cost of all items inputted thus far, prefixed with a dollar sign ($) and formatted to two decimal places.
                running_total += add_to_total(order_item)
                print(f'Total: ${running_total:.2f}')
            else:
                continue
    except (KeyboardInterrupt, EOFError):
        # returns a list consisting of the completed order on keyboard interrupt
        return order
    ...

def verify_item(oi):
    for item in MENU.keys():
        if item == oi:
            return True
    return False

def add_to_total(oi):
    return MENU[oi]

def print_total(order):
    #order is a list of the entire order.
    #for eahc item in the order, use as key in meny to get value, sum the values.
    # print the sum of values
    total = 0.00
    for item in order:
        total += MENU[item]
    print(f'Total: ${total:.2f}')

    ...

if __name__ == '__main__':
    main()
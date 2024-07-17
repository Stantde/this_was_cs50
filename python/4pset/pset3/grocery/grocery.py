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

Grocery List
Suppose that you’re in the habit of making a list of items you need from the grocery store.

In a file called grocery.py, implement a program that prompts the user for items, one per line, until the user inputs control-d (which is a common way of ending one’s input to a program). Then output the user’s grocery list in all uppercase, sorted alphabetically by item, prefixing each line with the number of times the user inputted that item. No need to pluralize the items. Treat the user’s input case-insensitively.

Hints
Note that you can detect when the user has inputted control-d by catching an EOFError with code like:
try:
    item = input()
except EOFError:
    ...
Odds are you’ll want to store your grocery list as a dict.
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

mkdir grocery
to make a folder called grocery in your codespace.

Then execute

cd grocery
to change directories into that folder. You should now see your terminal prompt as grocery/ $. You can now execute

code grocery.py
to make a file called grocery.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python grocery.py. Type mango and press Enter, then type strawberry and press Enter, followed by control-d. Your program should output:
1 MANGO
1 STRAWBERRY
Run your program with python grocery.py. Type milk and press Enter, then type milk again and press Enter, followed by control-d. Your program should output:
2 MILK
Run your program with python grocery.py. Type tortilla and press Enter, then type sweet potato and press Enter, followed by control-d. Your program should output:
1 SWEET POTATO
1 TORTILLA
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/grocery
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/grocery
'''
import sys

def main():
    # Prompts the user for items.
    grocery_list = get_grocery_list()
    # line, until the user inputs control-d. Then output the user’s grocery list in all uppercase,
    # sorted alphabetically by item, prefixing each line with the number of times the user inputted
    # that item. No need to pluralize the items. Treat the user’s input case-insensitively.
    print_grocery_list(grocery_list)
    sys.exit(0)
    ...

def get_grocery_list():
    groceries = {}
    try:
        while True:
            item = input().upper()
            groceries.update(add_to(item, groceries))
    except (KeyboardInterrupt, EOFError):
        return groceries

def add_to(item, groceries):
    # if item in list, increase count.
    if item in list(groceries):
        groceries[item] += 1
    # else add to list and set count to 1
    else:
        groceries.update({item : 1})
    return groceries

def print_grocery_list(grocery_list):
    # Sort keys alphabetically and print list prefixed with count
    my_keys = list(grocery_list.keys())
    my_keys.sort()
    for key in my_keys:
        print(f'{grocery_list[key]} {key}')
    ...

if __name__ == '__main__':
    main()
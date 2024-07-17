#!/usr/bin/python3
# don't include the <>
# chmod a+x <file>
# the shebange doesn't always play well with these files, but I'll include it anyway.
'''

Interested in a verified certificate or a professional certificate?

CS50’s Introduction to Programming with Python
OpenCourseWare

Donate

David J. Malan
malan@harvard.edu
Facebook GitHub Instagram LinkedIn Reddit Threads Twitter

Ready Player 50
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

Back to the Bank
In a file called bank.py, reimplement Home Federal Savings Bank from Problem Set 1, restructuring your code per the below, wherein value expects a str as input and returns 0 if that str starts with “hello”, 20 if that str starts with an “h” (but not “hello”), or 100 otherwise, treating the str case-insensitively. You can assume that the string passed to the value function will not contain any leading spaces. Only main should call print.

def main():
    ...


def value(value):
    ...


if __name__ == "__main__":
    main()
Then, in a file called test_bank.py, implement three or more functions that collectively test your implementation of value thoroughly, each of whose names should begin with test_ so that you can execute your tests with:

pytest test_bank.py
Hints
Be sure to include
import bank
or

from bank import value
atop test_bank.py so that you can call value in your tests.

Take care to return, not print, an int in value. Only main should call print.
Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir test_bank
to make a folder called test_bank in your codespace.

Then execute

cd test_bank
to change directories into that folder. You should now see your terminal prompt as test_bank/ $. You can now execute

code test_bank.py
to make a file called test_bank.py where you’ll write your tests.

How to Test
To test your tests, run pytest test_bank.py. Be sure you have a copy of a bank.py file in the same folder. Try to use correct and incorrect versions of bank.py to determine how well your tests spot errors:

Ensure you have a correct version of bank.py. Run your tests by executing pytest test_bank.py. pytest should show that all of your tests have passed.
Modify the correct version of bank.py, changing the values provided for each value. Your program might, for example, mistakenly provide $100 to a customer greeted by “Hello” and $0 to a customer greeted with “What’s up”! Now, run your tests by executing pytest test_bank.py. pytest should show that at least one of your tests has failed.
You can execute the below to check your tests using check50, a program CS50 will use to test your code when you submit. (Now there are tests to test your tests!). Be sure to test your tests yourself and determine which tests are needed to ensure bank.py is checked thoroughly.

check50 cs50/problems/2022/python/tests/bank
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/tests/bank
'''
from bank import value


def test_hello():
    assert value('hello') == 0
    assert value('       hello') == 0
    assert value('       hello           ') == 0
    assert value('hello       ') == 0
    assert value('hElLo       ') == 0


def test_hi():
    assert value('hi') == 20
    assert value('       h e l l o           ') == 20



def test_not_value():
    assert value('gibberish') == 100
    assert value('44hi') == 100
    assert value('      ') == 100
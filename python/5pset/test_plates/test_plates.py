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

Re-requesting a Vanity Plate

In a file called plates.py, reimplement Vanity Plates from Problem Set 2, restructuring your code per the below, wherein is_valid still expects a str as input and returns True if that str meets all requirements and False if it does not, but main is only called if the value of __name__ is "__main__":

def main():
    ...


def is_valid(s):
    ...


if __name__ == "__main__":
    main()
Then, in a file called test_plates.py, implement four or more functions that collectively test your implementation of is_valid thoroughly, each of whose names should begin with test_ so that you can execute your tests with:

pytest test_plates.py
Hints
Be sure to include
import plates
or

from plates import is_valid
atop test_plates.py so that you can call is_valid in your tests.

Take care to return, not print, a bool in is_valid. Only main should call print.
Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir test_plates
to make a folder called test_plates in your codespace.

Then execute

cd test_plates
to change directories into that folder. You should now see your terminal prompt as test_plates/ $. You can now execute

code test_plates.py
to make a file called test_plates.py where you’ll write your tests.

How to Test
To test your tests, run pytest test_plates.py. Be sure you have a copy of a plates.py file in the same folder. Try to use correct and incorrect versions of plates.py to determine how well your tests spot errors:

Ensure you have a correct version of plates.py. Run your tests by executing pytest test_plates.py. pytest should show that all of your tests have passed.
Modify the correct version of plates.py, perhaps eliminating some of its constraints. Your program might, for example, mistakenly print “Valid” for a license plate of any length! Run your tests by executing pytest test_plates.py. pytest should show that at least one of your tests has failed.
You can execute the below to check your tests using check50, a program CS50 will use to test your code when you submit. (Now there are tests to test your tests!). Be sure to test your tests yourself and determine which tests are needed to ensure plates.py is checked thoroughly.

check50 cs50/problems/2022/python/tests/plates
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/tests/plates
'''
from plates import is_valid


def test_null():
    assert 1 == 1

def test_not_long_enough():
    assert is_valid('N') == False


def test_too_long():
    assert is_valid('Nweorgweoirutyowieurytowieuryoti') == False

def test_wn_min_max():
    assert is_valid('eferg5') == True
    assert is_valid('hello') == True


def test_has_two_letters():
    assert is_valid('54968eferg5') == False
    assert is_valid('cs50') == True
    assert is_valid(' eferg5') == False
    #.lstrip(' ')


def test_wn_min_max():
    assert is_valid('cs05') == False
    assert is_valid('cs50P') == False
    assert is_valid('g5') == False
    assert is_valid('6g') == False


def test_nmbr_rule():
    assert is_valid('pi3.14') == False
    assert is_valid('H') == False


def test_punc():
    assert is_valid('OUTATIME') == False
    assert is_valid('0Asa') == False


def test_begin_num():
    assert is_valid('21pilots') == False
    assert is_valid("TEEKAY") == True
    assert is_valid("CS50") == True
    assert is_valid("B2MEN") == False
    assert is_valid("2GREAT") == False
    assert is_valid("TEEKAY") == True
    assert is_valid("C S50") == False
    assert is_valid("[S50") == False
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

Refueling
In a file called fuel.py, reimplement Fuel Gauge from Problem Set 3, restructuring your code per the below, wherein:

convert expects a str in X/Y format as input, wherein each of X and Y is an integer, and returns that fraction as a percentage rounded to the nearest int between 0 and 100, inclusive. If X and/or Y is not an integer, or if X is greater than Y, then convert should raise a ValueError. If Y is 0, then convert should raise a ZeroDivisionError.
gauge expects an int and returns a str that is:
"E" if that int is less than or equal to 1,
"F" if that int is greater than or equal to 99,
and "Z%" otherwise, wherein Z is that same int.
def main():
    ...


def convert(fraction):
    ...


def gauge(percentage):
    ...


if __name__ == "__main__":
    main()
Then, in a file called test_fuel.py, implement two or more functions that collectively test your implementations of convert and gauge thoroughly, each of whose names should begin with test_ so that you can execute your tests with:

pytest test_fuel.py
Hints
Be sure to include
import fuel
or

from fuel import convert, gauge
atop test_fuel.py so that you can call convert and gauge in your tests.

Take care to return, not print, an int in convert and a str in gauge. Only main should call print.
Note that you can check with pytest whether a function has raised an exception, per docs.pytest.org/en/latest/how-to/assert.html#assertions-about-expected-exceptions.
Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir test_fuel
to make a folder called test_fuel in your codespace.

Then execute

cd test_fuel
to change directories into that folder. You should now see your terminal prompt as test_fuel/ $. You can now execute

code test_fuel.py
to make a file called test_fuel.py where you’ll write your tests.

How to Test
To test your tests, run pytest test_fuel.py. Be sure you have a copy of a fuel.py file in the same folder. Try to use correct and incorrect versions of fuel.py to determine how well your tests spot errors:

Ensure you have a correct version of fuel.py. Run your tests by executing pytest test_fuel.py. pytest should show that all of your tests have passed.
Modify the correct version of fuel.py, changing the return values of convert. Your program might, for example, mistakenly return a str instead of an int. Run your tests by executing pytest test_fuel.py. pytest should show that at least one of your tests has failed.
Similarly, modify the correct version of fuel.py, changing the return values of gauge. Your program might, for example, mistakenly omit a % in the resulting str. Run your tests by executing pytest test_fuel.py. pytest should show that at least one of your tests has failed.
You can execute the below to check your tests using check50, a program CS50 will use to test your code when you submit. (Now there are tests to test your tests!). Be sure to test your tests yourself and determine which tests are needed to ensure fuel.py is checked thoroughly.

check50 cs50/problems/2022/python/tests/fuel
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/tests/fuel
'''
import pytest

from fuel import convert
from fuel import gauge

def test_convert_positive_nonzero_numbers():
    #try 3/4
    assert convert('3/4') == 75
    #1/4
    assert convert('1/4') == 25
    ...

def test_convert_negative_numbers():
    #Let's not...
    assert convert('-24/40') == -60
    ...

def test_convert_zero_containing_numbers():
    #0/4
    assert convert('0/4') == 0
    #0000/5
    assert convert('0000/5') == 0
    #4/0
    with pytest.raises(ZeroDivisionError):
        convert('4/0')

def test_convert_improper_fractions():
    #5/4
    with pytest.raises(ValueError):
        convert('5/4')

def test_convert_not_numbers():
    #cat/dog
    with pytest.raises(ValueError):
        convert('cat/dog')
        convert('.hack//sign')


def test_gauge_approach_zero_from_right():
    assert gauge(1) == "E"
    assert gauge(0.5) == "E"
    assert gauge(0) == "E"


def test_gauge_approach_full_from_left():
    assert gauge(100) == "F"
    assert gauge(99) == "F"
    assert gauge(99.5) == "F"


def test_gauge_on_target():
    #50%
    assert gauge(50) == "50%"
    #try -32 Stay away fromthevoodoo...
    ...


def test_gauge_below_the_min():
    assert gauge(-60) == "E"


def test_gauge_above_the_max():
    assert gauge(120) == "F"


if __name__ == '__main__':
    main()
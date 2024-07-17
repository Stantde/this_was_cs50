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

Just setting up my twttr

When texting or tweeting, it’s not uncommon to shorten words to save time or space, as by omitting vowels, much like Twitter was originally called twttr. In a file called twttr.py, implement a program that prompts the user for a str of text and then outputs that same text but with all vowels (A, E, I, O, and U) omitted, whether inputted in uppercase or lowercase.

Hints
Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir twttr
to make a folder called twttr in your codespace.

Then execute

cd twttr
to change directories into that folder. You should now see your terminal prompt as twttr/ $. You can now execute

code twttr.py
to make a file called twttr.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python twttr.py. Type Twitter and press Enter. Your program should output:
Twttr
Run your program with python twttr.py. Type What's your name? and press Enter. Your program should output:
Wht's yr nm?
Run your program with python twttr.py. Type CS50 and press Enter. Your program should output
CS50
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/twttr
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/twttr
'''
def main():
    # Take a str from the user
    user_tweet = input("Tweet: ")
    # Remove all vowels from the str
    tweet = remove_vowels(user_tweet)
    # Print the str
    print(tweet)
    ...

def list_vowels():
    lower_case_vowels = ['a','e','i','o','u']
    total_vowels = []
    for vowel in lower_case_vowels:
        total_vowels.append(vowel.upper())
        total_vowels.append(vowel)
    return total_vowels

def remove_vowels(user_tweet):
    vowels = list_vowels()
    for vowel in vowels:
        user_tweet = user_tweet.replace(vowel, '')
    return user_tweet
    ...


if __name__ == '__main__':
    main()
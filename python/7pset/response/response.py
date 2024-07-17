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

Response Validation
When creating a Google Form that prompts users for a short answer (or paragraph), it’s possible to enable response validation and require that the user’s input match a regular expression. For instance, you could require that a user input an email address with a regex like this one:

^[a-zA-Z0-9.!#$%&'*+\/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$
Or you could more easily use Google’s built-in support for validating an email address, per the screenshot below, much like you could use a library in your own code:

Google Form

In a file called response.py, using either validator-collection or validators from PyPI, implement a program that prompts the user for an email address via input and then prints Valid or Invalid, respectively, if the input is a syntatically valid email address. You may not use re. And do not validate whether the email address’s domain name actually exists.

Hints
Note that you can install validator-collection with:
pip install validator-collection
Click Homepage to find your way to the library’s documentation.

Note that you can install validators with:
pip install validators
Click Homepage to find your way to the library’s documentation.

Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir response
to make a folder called response in your codespace.

Then execute

cd response
to change directories into that folder. You should now see your terminal prompt as response/ $. You can now execute

code response.py
to make a file called response.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python response.py. Ensure your program prompts you for an email, then type malan@harvard.edu, followed by Enter. Your program should output Valid.
Run your program with python response.py. Type your own email, followed by Enter. Your program should output Valid.
Run your program with python response.py. Type malan@@@harvard.edu, followed by Enter. Your program should output Invalid.
Run your program with python response.py. Mistype your own email, including an extra . before .com, for example. Press enter and your program should output Invalid.
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/response
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/response
'''
'''
I want to add some additional notes here. The validators link took me to github, not pypi. I don't know
if that was intentional. However, I became intersted in learning how to install a python package from
github. it was simple, but I don't know that I'll recall this later:

pip install -e git+https://github.com/python-validators/validators#egg=validators

-e ~~~has something to do with making it "editable".
 git+ ~~~had to be typed.
 https://github.com/python-validators/validators ~~~was the link to the page
 #egg= ~~~also necessary
 validators ~~~name I gave to the package, which also matches the name of the package.
 '''


import validators

e_mail = input("What's you email address? ")
if validators.email(e_mail):
    print('Valid')
else:
    print('Invalid')
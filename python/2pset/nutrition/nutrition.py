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

Nutrition Facts
The U.S. Food & Drug Adminstration (FDA) offers downloadable/printable posters that “show nutrition information for the 20 most frequently consumed raw fruits … in the United States. Retail stores are welcome to download the posters, print, display and/or distribute them to consumers in close proximity to the relevant foods in the stores.”

In a file called nutrition.py, implement a program that prompts consumers users to input a fruit (case-insensitively) and then outputs the number of calories in one portion of that fruit, per the FDA’s poster for fruits, which is also available as text. Capitalization aside, assume that users will input fruits exactly as written in the poster (e.g., strawberries, not strawberry). Ignore any input that isn’t a fruit.

Hints
Rather than use a conditional with 20 Boolean expressions, one for each fruit, better to use a dict to associate a fruit with its calories!
If k is a str and d is a dict, you can check whether k is a key in d with code like:
if k in d:
    ...
Take care to output the fruit’s calories, not calories from fat!
Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir nutrition
to make a folder called nutrition in your codespace.

Then execute

cd nutrition
to change directories into that folder. You should now see your terminal prompt as nutrition/ $. You can now execute

code nutrition.py
to make a file called nutrition.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python nutrition.py. Type Apple and press Enter. Your program should output:
Calories: 130
Run your program with python nutrition.py. Type Avocado and press Enter. Your program should output:
Calories: 50
Run your program with python nutrition.py. Type Sweet Cherries and press Enter. Your program should output
Calories: 100
Run your program with python nutrition.py. Type Tomato and press Enter. Your program should output nothing.
Be sure to try other fruits and vary the casing of your input. Your program should behave as expected, case-insensitively.
https://www.fda.gov/food/food-labeling-nutrition/raw-fruits-poster-text-version-accessible-version
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/nutrition
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/nutrition
'''
def define_dict():
    nutrition_dict = {
        'Apple'		:	'130',
        'Avocado' 	:	'50',
        'Banana'	:	'110',
        'Cantaloupe'	:	'50',
        'Grapefruit'	:	'60',
        'Grapes'	:	'90',
        'Honeydew' 	:	'50',
        'Kiwifruit'	:	'90',
        'Lemon'		:	'15',
        'Lime'		:	'20',
        'Nectarine'	:	'60',
        'Orange'	:	'80',
        'Peach'		:	'60',
        'Pear'		:	'100',
        'Pineapple'	:	'50',
        'Plums'		:	'70',
        'Strawberries'	:	'50',
        'Sweet Cherries':	'100',
        'Tangerine'	:	'50',
        'Watermelon'	:	'80',
        'diced pieces'	:	'80'
    }
    return nutrition_dict

def main():
    # outputs the number of calories in one portion of that fruit, per the FDA’s poster for fruits, which is also available as text. Capitalization aside, assume that users will input fruits exactly as written in the poster (e.g., strawberries, not strawberry). Ignore any input that isn’t a fruit.
    # Prompt user for a fruit
    prompt = input('Item: ').lower()
    print(calories_in_fruit(prompt))
    ...

def calories_in_fruit(p):
    fruit_info = define_dict()
    for key in fruit_info.keys():
        if p == key.lower():
            return 'Calories: ' + fruit_info[key]
    return ''


main()
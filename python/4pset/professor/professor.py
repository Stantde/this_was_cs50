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

Little Professor

One of David’s first toys as a child, funny enough, was Little Professor, a “calculator” that would generate ten different math problems for David to solve. For instance, if the toy were to display 4 + 0 = , David would (hopefully) answer with 4. If the toy were to display 4 + 1 = , David would (hopefully) answer with 5. If David were to answer incorrectly, the toy would display EEE. And after three incorrect answers for the same problem, the toy would simply display the correct answer (e.g., 4 + 0 = 4 or 4 + 1 = 5).

In a file called professor.py, implement a program that:

Prompts the user for a level,
. If the user does not input 1, 2, or 3, the program should prompt again.
Randomly generates ten (10) math problems formatted as X + Y = , wherein each of X and Y is a non-negative integer with
 digits. No need to support operations other than addition (+).
Prompts the user to solve each of those problems. If an answer is not correct (or not even a number), the program should output EEE and prompt the user again, allowing the user up to three tries in total for that problem. If the user has still not answered correctly after three tries, the program should output the correct answer.
The program should ultimately output the user’s score: the number of correct answers out of 10.
Structure your program as follows, wherein get_level prompts (and, if need be, re-prompts) the user for a level and returns 1, 2, or 3, and generate_integer returns a randomly generated non-negative integer with level digits or raises a ValueError if level is not 1, 2, or 3:

import random


def main():
    ...


def get_level():
    ...


def generate_integer(level):
    ...


if __name__ == "__main__":
    main()
Hints
Note that you can raise an exception like ValueError with code like:
raise ValueError
Note that the random module comes with quite a few functions, per docs.python.org/3/library/random.html.
Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir professor
to make a folder called professor in your codespace.

Then execute

cd professor
to change directories into that folder. You should now see your terminal prompt as professor/ $. You can now execute

code professor.py
to make a file called professor.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python professor.py. Type -1 and press Enter. Your program should reprompt you:
Level:
Run your program with python professor.py. Type 4 and press Enter. Your program should reprompt you:
Level:
Run your program with python professor.py. Type 1 and press Enter. Your program should begin posing addition problems with positive, single-digit integers. For example:
6 + 6 =
Your program should output 10 distinct problems before printing the number of questions you answered correctly and exiting.

Run your program with python professor.py. Type 1 and press Enter. Answer the first question incorrectly. Your program should output:
EEE
before reprompting you with the same question.

Run your program with python professor.py. Type 1 and press Enter. Answer the first question incorrectly, three times. Your program should output the correct answer. For example:
6 + 6 = 12
and then move on to another question. Answer the remaining questions correctly. Your program should output a score of 9.

Run your program with python professor.py. Type 1 and press Enter. Answer all 10 questions correctly. Your program should output a score of 10.
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/professor
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/professor
'''
import random
LEVELS = (1, 2, 3)
test_set = {
    0 : '',
    1 : '',
    2 : '',
    3 : '',
    4 : '',
    5 : '',
    6 : '',
    7 : '',
    8 : '',
    9 : ''
}


def main():
    # Level = max number of digits in x or y  in x + y = sum.
    level = get_level()
    generate_integer(level)
    score = play_game()
    print(f'Score: {score}')
    ...


# Prompt user for level, 1, 2, or 3. If the user doesn't input 1, 2, or 3, prompt user again.
def get_int(prompt):
    while True:
        user_int = input(f'{prompt}')
        try:
            user_int = int(user_int)
        except ValueError:
            user_int = get_int(prompt)
        return user_int

def get_level():
    prompt = 'Level: '
    level = get_int(prompt)
    while level not in LEVELS:
        level = get_int(prompt)
    return level

def generate_integer(level):
    for key in test_set.keys():
        # Generate x and y, and sum values then append to list. Add as values to key in test_set.
        a = []
        x = generate_x(level)
        a.append(x)
        y = generate_y(level)
        a.append(y)
        sum  = x + y
        a.append(sum)
  #      >>> test_set['1'][0] = x
  #      >>> test_set['1'][1] = y
  #      >>> test_set['1'][2] = sum
        test_set[key] = a
    return
    ...

def generate_x(level):
    '''
    # if level = 1, generate one random didgit
    # if level equal two, generate two random digits..
    x_digit = []
    for _ in range(level):
        x_digit.append(str(random.randint(0,9)))
    x =''.join(x_digit)
    x = int(x)
    '''
    if level == 1:
        x = random.randint(0,9)
    elif level == 2:
        x = random.randint(10,99)
    else:
        x = random.randint(100,999)
    return x

def generate_y(level):
    y = generate_x(level)
    return y

def play_game():
    score = 0
    # For each question:
    for question in test_set.keys():
        # Prompt the player with the question.
        current_question = str(test_set[question][0]) + ' + ' + str(test_set[question][1]) + ' = '
        current_answer = test_set[question][2]
        # Get their answer
        for _ in range(3):
            player_answer = get_int(current_question)
            if player_answer == current_answer:
                score += 1
                answered_correctly = True
                break
            else:
                print('EEE')
                answered_correctly = False
                continue
        if not answered_correctly:
            print(str(current_answer))
    # if the answer is correct, move on to the next questionplayer gets 3 shots, if the answer is co
    return score

if __name__ == "__main__":
    main()
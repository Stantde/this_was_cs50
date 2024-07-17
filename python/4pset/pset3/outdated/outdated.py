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

Outdated
In the United States, dates are typically formatted in month-day-year order (MM/DD/YYYY), otherwise known as middle-endian order, which is arguably bad design. Dates in that format can’t be easily sorted because the date’s year comes last instead of first. Try sorting, for instance, 2/2/1800, 3/3/1900, and 1/1/2000 chronologically in any program (e.g., a spreadsheet). Dates in that format are also ambiguous. Harvard was founded on September 8, 1636, but 9/8/1636 could also be interpreted as August 9, 1636!

Fortunately, computers tend to use ISO 8601, an international standard that prescribes that dates should be formatted in year-month-day (YYYY-MM-DD) order, no matter the country, formatting years with four digits, months with two digits, and days with two digits, “padding” each with leading zeroes as needed.

In a file called outdated.py, implement a program that prompts the user for a date, anno Domini, in month-day-year order, formatted like 9/8/1636 or September 8, 1636, wherein the month in the latter might be any of the values in the list below:

[
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]
Then output that same date in YYYY-MM-DD format. If the user’s input is not a valid date in either format, prompt the user again. Assume that every month has no more than 31 days; no need to validate whether a month has 28, 29, 30, or 31 days.

Hints
Recall that a str comes with quite a few methods, per docs.python.org/3/library/stdtypes.html#string-methods, including split.
Recall that a list comes with quite a few methods, per docs.python.org/3/tutorial/datastructures.html#more-on-lists, among which is index.
Note that you can format an int with leading zeroes with code like
print(f"{n:02}")
wherein, if n is a single digit, it will be prefixed with one 0, per docs.python.org/3/library/string.html#format-string-syntax.

Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir outdated
to make a folder called outdated in your codespace.

Then execute

cd outdated
to change directories into that folder. You should now see your terminal prompt as outdated/ $. You can now execute

code outdated.py
to make a file called outdated.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python outdated.py. Type 9/8/1636 and press Enter. Your program should output:
1636-09-08
Run your program with python outdated.py. Type September 8, 1636 and press Enter. Your program should output:
1636-09-08
Run your program with python outdated.py. Type 23/6/1912 and press Enter. Your program should reprompt the user.
Run your program with python outdated.py. Type December 80, 1980 and press Enter. Your program should reprompt the user.
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/outdated
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/outdated
'''
months_of_the_year = {
    "January" : '01',
    "February" : '02',
    "March" : '03',
    "April" : '04',
    "May" : '05',
    "June" : '06',
    "July" : '07',
    "August" : '08',
    "September" : '09',
    "October" : '10',
    "November" : '11',
    "December" : '12'
}

def main():
    # Prompts the user for a date, formatted like 9/8/1636 or September 8, 1636.
    user_date = get_date()
    # Then output that same date in YYYY-MM-DD format.
    # If the user’s input is not a valid date in either format, prompt the user again.
    # Assume that every month has no more than 31 days; no need to validate whether a month has 28, 29, 30, or 31 days.
    print('-'.join(user_date))
    ...

def get_date():
    # Determine the date type, by finding (case 1)',' or (case 2)'/'
    date = []
    date_is_not_valid = True
    while date_is_not_valid:
        input_date = input('Date: ').lstrip().rstrip()
        splitting_char = determine_char(input_date)
        date.append(get_year(splitting_char, input_date))
        date.append(get_month(splitting_char, input_date))
        date.append(get_day(splitting_char, input_date))
        date_is_not_valid = validate_date(date)
    return date

def determine_char(input_date):
    splitting_char = '/'
    if input_date.find(splitting_char) == -1:
        splitting_char = ' '
    return splitting_char

def get_year(sc, input_date):
    # think 9/8/1636 or September 8, 1636
    year = ''
    a, b, year = input_date.split(sc)
    return year

def get_month(sc, input_date):
    # think 9/8/1636 or September 8, 1636
    month = ''
    if sc == ' ':
        for key in months_of_the_year.keys():
            if key in input_date:
                month = str(months_of_the_year[key])
    else:
        month, a, b = input_date.split(sc)
        if len(month) == 1:
            month = '0' + month
    return month


def get_day(sc, input_date):
    # think 9/8/1636 or September 8, 1636
    a, day, b = input_date.split(sc)
    if sc == ' ':
        if not day.endswith(','):
            day = day + 'Invalid input'
        day = day.rstrip(',')
    if len(day) == 1:
        day = '0' + day
    return day

def validate_date(date):
    # Validate Date
    invalid_date = True
    # Check year, if invalid, return
    # Year must be length of 4
    if len(date[0]) != 4:
        return invalid_date
    # Check month, if invalid, return
    # Month must be between 1 and 12
    try:
        month = int(date[1])
    except  ValueError:
        return invalid_date
    if month < 1:
        return invalid_date
    elif month > 12:
        return invalid_date
    # Check day, if invalid, return
    # day must be 1 or up to 31
    day = date[2]
    if len(day) != 2:
        return invalid_date
    day = int(day)
    if day < 1:
        return invalid_date
    elif day > 31:
        return invalid_date
    invalid_date = False
    # day must be two digits.
    return invalid_date


if __name__ == '__main__':
    main()
'''

Interested in a verified certificate or a professional certificate?

CS50’s Introduction to Programming with Python
OpenCourseWare

Donate

David J. Malan
malan@harvard.edu
Facebook GitHub Instagram LinkedIn Reddit Threads Twitter

Making Faces
Before there were emoji, there were emoticons, whereby text like :) was a happy face and text like :( was a sad face. Nowadays, programs tend to convert emoticons to emoji automatically!

In a file called faces.py, implement a function called convert that accepts a str as input and returns that same input with any :) converted to 🙂 (otherwise known as a slightly smiling face) and any :( converted to 🙁 (otherwise known as a slightly frowning face). All other text should be returned unchanged.

Then, in that same file, implement a function called main that prompts the user for input, calls convert on that input, and prints the result. You’re welcome, but not required, to prompt the user explicitly, as by passing a str of your own as an argument to input. Be sure to call main at the bottom of your file.

Hints
Before You Begin
Execute cd by itself in your terminal window. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir faces
to make a folder called faces in your codespace.

Then execute

cd faces
to change directories into that folder. You should now see your terminal prompt as faces/ $. You can now execute

code faces.py
to make a file called faces.py where you’ll write your program.

Demo

How to Test
Here’s how to test your code manually:

Run your program with python faces.py. Type Hello :) and press Enter. Your program should output:
Hello 🙂
Run your program with python faces.py. Type Goodbye :( and press Enter. Your program should output:
Goodbye 🙁
Run your program with python faces.py. Type Hello :) Goodbye :( and press Enter. Your program should output
Hello 🙂 Goodbye 🙁
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/faces
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/faces
'''
def convert(string_to_convert):
    converted_string = string_to_convert.replace(':)','🙂').replace(':(','🙁')
    return converted_string


def main():
    # prompt for input
    user_input = input()
    # convert to string
    converted_input = convert(user_input)
    # print converted string
    print(converted_input)


main()
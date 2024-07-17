#!/usr/local/bin/python
'''

Hello, Again
Problem to Solve
In a file called hello.py in a folder called sentimental-hello, implement a program that prompts a user for their name, and then prints hello, so-and-so, where so-and-so is their provided name, exactly as you did in Problem Set 1. Except that your program this time should be written in Python!

Hints
Recall that you can get a str from a user with get_string, which is declared in the cs50 library.
Recall that you can print a str with print.
Recall that you can create formatted strings in Python by prepending f to a string itself. For example, f"{name}" will substitute (“interpolate”) the value of the variable name where you’ve written {name}.
Demo

How to Test
While check50 is available for this problem, you’re encouraged to first test your code on your own for each of the following.

Run your program as python hello.py, and wait for a prompt for input. Type in David and press enter. Your program should output hello, David.
Run your program as python hello.py, and wait for a prompt for input. Type in Inno and press enter. Your program should output hello, Inno.
Run your program as python hello.py, and wait for a prompt for input. Type in Kamryn and press enter. Your program should output hello, Kamryn.
Correctness
check50 cs50/problems/2024/x/sentimental/hello
Style
style50 hello.py
How to Submit
submit50 cs50/problems/2024/x/sentimental/hello
Why does my submission pass check50, but shows “No results” in my Gradebook after running submit50?

In some cases, submit50 may not grade the assignment due to inconsistent formatting in your hello.py file. To fix this issue, run black hello.py in the sentimental-hello folder. Address any issues that are revealed. Run check50 again to ensure your submission still functions. Finally, run the submit50 command above again. Your result will appear in your Gradebook within a few minutes.

Please note that if there is a numerical score next to your hello submission in the submissions area of your Gradebook, the procedure discussed above does not apply to you. Likely, you have not fully addressed the requirements of the problem set and should rely upon check50 for clues as to what work remains.
'''
user_name = input("Please tell me your name. ")
print(f'hello, {user_name}.')

#!/usr/local/bin/python
# chmod a+x mario.py
'''
Mario
screenshot of Mario jumping up pyramid

Problem to Solve
In a file called mario.py in a folder called sentimental-mario-less, write a program that recreates a half-pyramid using hashes (#) for blocks, exactly as you did in Problem Set 1. Your program this time should be written in Python!

Demo

Specification
To make things more interesting, first prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive.
If the user fails to provide a positive integer no greater than 8, you should re-prompt for the same again.
Then, generate (with the help of print and one or more loops) the desired half-pyramid.
Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.
How to Test
While check50 is available for this problem, you’re encouraged to first test your code on your own for each of the following.

Run your program as python mario.py and wait for a prompt for input. Type in -1 and press enter. Your program should reject this input as invalid, as by re-prompting the user to type in another number.
Run your program as python mario.py and wait for a prompt for input. Type in 0 and press enter. Your program should reject this input as invalid, as by re-prompting the user to type in another number.
Run your program as python mario.py and wait for a prompt for input. Type in 1 and press enter. Your program should generate the below output. Be sure that the pyramid is aligned to the bottom-left corner of your terminal, and that there are no extra spaces at the end of each line.
#
Run your program as python mario.py and wait for a prompt for input. Type in 2 and press enter. Your program should generate the below output. Be sure that the pyramid is aligned to the bottom-left corner of your terminal, and that there are no extra spaces at the end of each line.
 #
##
Run your program as python mario.py and wait for a prompt for input. Type in 8 and press enter. Your program should generate the below output. Be sure that the pyramid is aligned to the bottom-left corner of your terminal, and that there are no extra spaces at the end of each line.
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
Run your program as python mario.py and wait for a prompt for input. Type in 9 and press enter. Your program should reject this input as invalid, as by re-prompting the user to type in another number. Then, type in 2 and press enter. Your program should generate the below output. Be sure that the pyramid is aligned to the bottom-left corner of your terminal, and that there are no extra spaces at the end of each line.
 #
##
Run your program as python mario.py and wait for a prompt for input. Type in foo and press enter. Your program should reject this input as invalid, as by re-prompting the user to type in another number.
Run your program as python mario.py and wait for a prompt for input. Do not type anything, and press enter. Your program should reject this input as invalid, as by re-prompting the user to type in another number.
Correctness
check50 cs50/problems/2024/x/sentimental/mario/less
Style
style50 mario.py
How to Submit
submit50 cs50/problems/2024/x/sentimental/mario/less
Why does my submission pass check50, but shows “No results” in my Gradebook after running submit50?

In some cases, submit50 may not grade the assignment due to inconsistent formatting in your mario.py file. To fix this issue, run black mario.py in the sentimental-mario-less folder. Address any issues that are revealed. Run check50 again to ensure your submission still functions. Finally, run the submit50 command above again. Your result will appear in your Gradebook within a few minutes.

Please note that if there is a numerical score next to your mario submission in the submissions area of your Gradebook, the procedure discussed above does not apply to you. Likely, you have not fully addressed the requirements of the problem set and should rely upon check50 for clues as to what work remains.
'''
# import statements
from cs50 import get_float, get_int, get_string

# constants
MIN_HEIGHT = 1
MAX_HEIGHT = 8

# prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive.
while True:
    half_pyramid_height = get_int("Input height of pyramid. ")
    if half_pyramid_height >= MIN_HEIGHT and half_pyramid_height <= MAX_HEIGHT:
        break

# Then, generate (with the help of print and one or more loops) the desired half-pyramid.
# Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.
for row in range(half_pyramid_height):
    for column in range(half_pyramid_height):
        if half_pyramid_height - row - 1 >= column+1:
            print(" ", end='')
        else:
            print("#", end='')
    print("")

#!/usr/local/bin/python

'''
C version

Problem to Solve
According to Scholastic, E.B. White’s Charlotte’s Web is between a second- and fourth-grade reading level, and Lois Lowry’s The Giver is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular reading level?

Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. But an algorithm could likely figure that out too!

In a file called readability.c in a folder called readability, you’ll implement a program that calculates the approximate grade level needed to comprehend some text. Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, your program should output “Before Grade 1”.

Demo

Background
So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.

A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

index = 0.0588 * L - 0.296 * S - 15.8
where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

Advice
Write some code that you know will compile
Write some pseudocode before writing more code
Convert the pseudocode to code
Walkthrough

How to Test
Try running your program on the following texts, to ensure you see the specified grade level. Be sure to copy only the text, no extra spaces.

One fish. Two fish. Red fish. Blue fish. (Before Grade 1)
Would you like them here or there? I would not like them here or there. I would not like them anywhere. (Grade 2)
Congratulations! Today is your day. You're off to Great Places! You're off and away! (Grade 3)
Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard. (Grade 5)
In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since. (Grade 7)
Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?" (Grade 8)
When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh. (Grade 8)
There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy. (Grade 9)
It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him. (Grade 10)
A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains. (Grade 16+)
Correctness
In your terminal, execute the below to check your work’s correctness.

check50 cs50/problems/2024/x/readability
Style
Execute the below to evaluate the style of your code using style50.

style50 readability.c
How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2024/x/readability
Python Version
Readability
Problem to Solve
Write, in a file called readability.py in a folder called sentimental-readability, a program that first asks the user to type in some text, and then outputs the grade level for the text, according to the Coleman-Liau formula, exactly as you did in Problem Set 2, except that your program this time should be written in Python.

Demo

Specification
Recall that the Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8, where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
Use get_string from the CS50 Library to get the user’s input, and print to output your answer.
Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".
How to Test
While check50 is available for this problem, you’re encouraged to first test your code on your own for each of the following.

Run your program as python readability.py, and wait for a prompt for input. Type in One fish. Two fish. Red fish. Blue fish. and press enter. Your program should output Before Grade 1.
Run your program as python readability.py, and wait for a prompt for input. Type in Would you like them here or there? I would not like them here or there. I would not like them anywhere. and press enter. Your program should output Grade 2.
Run your program as python readability.py, and wait for a prompt for input. Type in Congratulations! Today is your day. You're off to Great Places! You're off and away! and press enter. Your program should output Grade 3.
Run your program as python readability.py, and wait for a prompt for input. Type in Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard. and press enter. Your program should output Grade 5.
Run your program as python readability.py, and wait for a prompt for input. Type in In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since. and press enter. Your program should output Grade 7.
Run your program as python readability.py, and wait for a prompt for input. Type in Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?" and press enter. Your program should output Grade 8.
Run your program as python readability.py, and wait for a prompt for input. Type in When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh. and press enter. Your program should output Grade 8.
Run your program as python readability.py, and wait for a prompt for input. Type in There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy. and press enter. Your program should output Grade 9.
Run your program as python readability.py, and wait for a prompt for input. Type in It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him. and press enter. Your program should output Grade 10.
Run your program as python readability.py, and wait for a prompt for input. Type in A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains. and press enter. Your program should output Grade 16+.
Correctness
check50 cs50/problems/2024/x/sentimental/readability
Style
style50 readability.py
How to Submit
submit50 cs50/problems/2024/x/sentimental/readability
Why does my submission pass check50, but shows “No results” in my Gradebook after running submit50?

In some cases, submit50 may not grade the assignment due to inconsistent formatting in your readability.py file. To fix this issue, run black readability.py in the sentimental-readability folder. Address any issues that are revealed. Run check50 again to ensure your submission still functions. Finally, run the submit50 command above again. Your result will appear in your Gradebook within a few minutes.

Please note that if there is a numerical score next to your readability submission in the submissions area of your Gradebook, the procedure discussed above does not apply to you. Likely, you have not fully addressed the requirements of the problem set and should rely upon check50 for clues as to what work remains.
'''
from cs50 import get_string


def main():
    text = get_string("Text: ")
    text = convert_to_letters_words_sentences(text)
    readability = Coleman_Liau_index(L(text), S(text))
    print(readability)
    ...

# Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.


def convert_to_letters_words_sentences(text):
    letters, words, sentences = 0, 1, 0
    # count letters
    for character in text:
        if character.isalpha():
            letters += 1
        elif character.isspace():
            words += 1
            # period, exclamation point, or question mark indicates the end of a sentence.
        elif character in ['.', '!', '?']:
            sentences += 1
    return letters, words, sentences


# L is the average number of letters per 100 words in the text.
# reminder text = [letters, words, sentences]
def L(text):
    value = 100 * text[0] / text[1]
    return value

# S is the average number of sentences per 100 words in the text.


def S(text):
    value = 100 * text[2] / text[1]
    return value


def Coleman_Liau_index(L=1, S=1):
    index = 0.0588 * L - 0.296 * S - 15.8
    if index > 16:
        read = "Grade 16+"
    elif index < 1.0:
        read = "Before Grade 1"
    else:
        read = "Grade " + str(round(index))
    return read


if __name__ == '__main__':
    main()

I forget all of the syntax for md...
(Video)[https://www.youtube.com/watch?v=PaPN51Mm5qQ&t=25865s]: https://www.youtube.com/watch?v=PaPN51Mm5qQ&t=25865s
# From Python to C?
* cc_02.01.c
* cc_02.02.c
To compile to a specific file name:
gcc -o cc_02.02 cc_02.02.c

# A Tutorial Introduction
* This is an accurate 
[Video](https://www.youtube.com/watch?v=PaPN51Mm5qQ&t=6379s)

Don't forget to push changes at the end of a session!

## Character Sets
* The C char type is just a number. A = 65. Character arrays need to allocate an extra byte to store the line-end chracter.
* Complete Exercise 1-17 in K&R (Where is it?) found it.
* The body of a while can be one or more statements enclosed in braces, as in the temperature converter, or a single statement without braces, as in
` while (i<2) 
    i = 2*i;
    `


* 2:20:00 in
# K&R Chapter 1
## 1.3 The For Statement
## 1.4 Symbolic Constants
* 2:29:20 "#define" without ";"
## 1.5 A Collection of Useful Programs
Exercise 1-6. Write a program to count blanks, tabs, and newlines.

Exercise 1-7. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

Exercise 1-8. Write a program to replace each tab by the three-character sequence >, backspace, -, which prints as >, and each backspace by the similar sequence <. This makes tabs and backspaces visible.
* 2:51:15  0201 11-05-2025
* Exercise 1-9. How would you test the word count program? What are some boundaries?

* Exercise 1-10. Write a program which prints the words in its input, one per line.

* Exercise 1-11. Revise the word count program to use a better definition of "word," for example, a sequence of letters, digits and apostrophes that begins with a letter.

* Admittedly, I used some of my knowledge from cs50x. O wait, && is ok to use!
## 1.6 Arrays
* 3:05:25
* Exercise 1-12. Write a program to print a histogram of the lengths of words in its input. It is easiest to draw the histogram horizontally; a vertical orientation is more challenging.

## 1.7 Functions
* 0807 11-05-2025 3:06:32
* Exercise 1-13. Write a program to convert its input to lower case, using a function lower(c) which returns c if c is not a letter, and the lower case value of c if it is a letter.
## 1.8 Arguments - Call by Value
* 2306 11/5/2025 3:12:07
* Call by value is more of the norm than call by reference. This helps keep data safe from unintentional modifications.
* When the name of an array is used as an argument, the value passed to the function is actually the location or address of the beginning of the array. (There is no copying of array elements.) By subscripting this value, the function can access and alter any element of the array.
## 1.9 Character Arrays
* 2314 11-05-2025 3:17:30
* The copy function is sharp.

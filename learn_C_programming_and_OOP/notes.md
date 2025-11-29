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
## 1.1 Getting Started
* print statements printf("Hello World!\n")
* compiling and running
## 1.2 Variables and Arithmetic
* char, short, long, doubles
## 1.3 The For Statement
* for and while loops (iteration)
## 1.4 Symbolic Constants
* 2:29:20 "#define" without ";"

## 1.5 A Collection of Useful Programs
* The standard library provides functions for reading and writing a character at a time. getchar() fetches the next input character each time it is called, and returns that character as its value. 
* The function putchar(c) is the complement of getchar:

putchar(c)
prints the contents of variable c on some output medium, again usually the terminal. Calls to putchar and printf may be interleaved; the output will appear in the order in which the calls are made.


* Exercise 1-6. Write a program to count blanks, tabs, and newlines.

* Exercise 1-7. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

* Exercise 1-8. Write a program to replace each tab by the three-character sequence >, backspace, -, which prints as >, and each backspace by the similar sequence <. This makes tabs and backspaces visible.
* 2:51:15  0201 11-05-2025
* Exercise 1-9. How would you test the word count program? What are some boundaries?

* Exercise 1-10. Write a program which prints the words in its input, one per line.

* Exercise 1-11. Revise the word count program to use a better definition of "word," for example, a sequence of letters, digits and apostrophes that begins with a letter.
* || and &&, >, <, >=, <=, "\n" vs '\n' int value of char.
* Admittedly, I used some of my knowledge from cs50x. O wait, && is ok to use!
## 1.6 Arrays
* 3:05:25
* Exercise 1-12. Write a program to print a histogram of the lengths of words in its input. It is easiest to draw the histogram horizontally; a vertical orientation is more challenging.
* if/ else if/ else

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
* Exercise 1-14. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.

* Exercise 1-15. Write a program to print all lines that are longer than 80 characters.

* Exercise 1-16. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

* Exercise 1-17. Write a function reverse(s) which reverses the character string s. Use it to write a program which reverses its input a line at a time.

## 1.10 Scope; External Variables
* 2225 11-06-2025
## 1.11 Summary 
* 2044 11-06-2025 3:38:05
* Exercise 1-19. Write a program detab which replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n positions.

* Exercise 1-20. Write the program entab which replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
  
* Exercise 1-21. Write a program to "fold" long input lines after the last non-blank character that occurs before the n-th column of input, where n is a parameter. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

* Exercise 1-22. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly.

* [Exercise 1-23.](./chapter_01/1.23.c) Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, and comments. (This program is hard if you do it in full generality.)

# K&R Chapter 2
* 0010 11-07-2025 4:01:10
## 2.2 Data Types and Sizes
## 2.3 Constants
* 0034 11-07-2025
## 2.4 Declarations
* I have to take a break here. I'm struggling to absorb new information.
* 0051 11-07-2025 4:14:30
* 1359 11-20-2025 It took me a while to notice this, but the entire course is offered on the cc4e website. I think instead of reading from K&R book and performing exercises as they are in it, I will instead work on the exercises from the website. If I need additional practice, I will return to the book.
## 2.5 Arithmetic Operators
## 2.6 Relational and Logical Operators
* [Exercise 2-1.](./chapter_02/2.1.c) Write a loop equivalent to the for loop above without using &&.

## 2.7 Type Conversions
* 1935 11-20-2025 042800
* isdigit = c >= '0' && c <= '9';
sets isdigit to 1 if c is a digit, and to 0 if not. (In the test part of if, while, for, etc., "true" just means "non-zero.")

* Includes rounding rules.
* [Exercise 2-2.](./chapter_02/2.2.c) Write the function htoi(s), which converts a string of hexadecimal digits into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.


## 2.8 Increment and Decrement Operators
* 2054 11-20-2025 04:43:41

* [Exercise 2-3.](./chapter_02/2.3.c) Write an alternate version of squeeze(s1, s2) which deletes each character in s1 which matches any character in the string s2.

* [Exercise 2-4.](./chapter_02/2.4.c) Write the function any(s1, s2) which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.

## 2.9 Bitwise Logical Operators

* [bitwise operations](https://www.geeksforgeeks.org/dsa/complete-reference-for-bitwise-operators-in-programming-coding/)

* sizeof{char}<=sizeof{short}<=sizeof{int}<=sizeof{long}<=sizeof{long long}

* The char type is always 1 byte by definition in C.
* x << 2 shifts x left by two positions, filling vacated bits with 0; this is equivalent to multiplication by 4. 
* I'm struggling here. It may be time to call it a night. 4:46:59
* Exercise 2-5. Modify getbits to number bits from left to right.

* [Exercise 2-6.](./chapter_02/2.6.c) Write a function wordlength() which computes the word length of the host machine, that is, the number of bits in an int. The function should be portable, in the sense that the same source code works on all machines.

* [Exercise 2-7.](./chapter_02/2.7.c) Write the function rightrot(n, b) which rotates the integer n to the right by b bit positions.

* [Exercise 2-8.](./chapter_02/2.8.c) Write the function invert(x, p, n) which inverts (i.e., changes 1 into 0 and vice versa) the n bits of x that begin at position p, leaving the others unchanged.

## 2.10 Assignment Operators and Expressions

As an example, the function bitcount counts the number of 1-bits in its integer argument.
```
bitcount(n) /* count 1 bits in n */
unsigned n;
{
    int b;

    for (b = 0; n != 0; n >>= 1)
        if (n & 01)
            b++;
    return(b);
}
```

* [Exercise 2-9](./chapter_02/2.9.c). In a 2's complement number system, x & ( x-1 ) deletes the rightmost 1-bit in x. (Why?) Use this observation to write a faster version of bitcount.
## 2.11 Conditional Expressions

* The statements
```
if (a > b)
    z = a;
else
    z = b;
```
    
* Compute in z the maximum of a and b.
* The conditional expression, written with the ternary operator "?:", provides an alternate way to write this and similar constructions. In the expression
``` e1 ? e2 : e3 ```
the expression **e1** is evaluated first. If it is non-zero (true), then the expression **e2** is evaluated, and that is the value of the conditional expression. Otherwise **e3** is evaluated, and that is the value. Only one of e2 and e3 is evaluated.
Thus to set z to the maximum of a and b,
``` z = (a > b) ? a : b; /* z = max(a, b) */ ```
* If e2 and e3 are of different types, the type of the result is determined by the conversion rules discussed earlier in this chapter. For example, if f is a float, and n is an int, then the expression ```(n > 0) ? f : n```
is of type double regardless of whether n is positive or not.
* Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.


## 2.12 Precedence and Order of Evaluation
# [CHAPTER 3: CONTROL FLOW](https://www.cc4e.com/book/chap03.md)
## 3.1 Statements and Blocks
* 11:21 11-28-2025 5:16:57
## 3.2 If-Else
* 11:24 11-28-2025 5:20:00
## 3.3 Else-If
* 11:27 11-28-2025
## 3.4 Switch
* 11:34 11-28-2025 5:28:00
* [Example](./chapter_03/switch_example.c)
* Break is necessary to prevent "falling through". Be especially watchful for this.
* [Exercise 3-1.](./chapter_03/3.1.c) Write a function expand(s, t) which converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string s to t. Use a switch.
## 3.5 Loops - While and For
* [Exercise 3-2.](./chapter_03/3.2.c) Write a function expand(s1 , s2) which expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. (A useful convention is that a leading or trailing - is taken literally.)

## 3.6 Loops - Do-while
* [Exercise 3-3.](./chapter_03/3.3.c) In a 2's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine it runs on.

* Exercise 3-4. Write the analogous function itob(n, s) which converts the unsigned integer n into a binary character representation in s. Write itoh, which converts an integer to hexadecimal representation.

* Exercise 3-5. Write a version of itoa which accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.


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

File Extensions
Even though Windows and macOS sometimes hide them, most files have file extensions, a suffix that starts with a period (.) at the end of their name. For instance, file names for GIFs end with .gif, and file names for JPEGs end with .jpg or .jpeg. When you double-click on a file to open it, your computer uses its file extension to determine which program to launch.

Web browsers, by contrast, rely on media types, formerly known as MIME types, to determine how to display files that live on the web. When you download a file from a web server, that server sends an HTTP header, along with the file itself, indicating the file’s media type. For instance, the media type for a GIF is image/gif, and the media type for a JPEG is image/jpeg. To determine the media type for a file, a web server typically looks at the file’s extension, mapping one to the other.

See developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/MIME_types/Common_types for common types.

In a file called extensions.py, implement a program that prompts the user for the name of a file and then outputs that file’s media type if the file’s name ends, case-insensitively, in any of these suffixes:

.gif
.jpg
.jpeg
.png
.pdf
.txt
.zip
If the file’s name ends with some other suffix or has no suffix at all, output application/octet-stream instead, which is a common default.

Hints
Recall that a str comes with quite a few methods, per docs.python.org/3/library/stdtypes.html#string-methods.
Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir extensions
to make a folder called extensions in your codespace.

Then execute

cd extensions
to change directories into that folder. You should now see your terminal prompt as extensions/ $. You can now execute

code extensions.py
to make a file called extensions.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with python extensions.py. Type happy.jpg and press Enter. Your program should output:
image/jpeg
Run your program with python extensions.py. Type document.pdf and press Enter. Your program should output:
application/pdf
Be sure to test each of the other file formats, vary the casing of your input, and “accidentally” add spaces on either side of your input before pressing enter. Your program should behave as expected, case- and space-insensitively.

You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/extensions
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/extensions
'''

'''
def http_error(status):
    match status:
        case 400:
            return "Bad request"
        case 404:
            return "Not found"
        case 418:
            return "I'm a teapot"
        case _:
            return "Something's wrong with the internet"
'''
def main():
    # prompt user for input
    user_input = input('File name: ')
    # pass input to checker
    print(checker(user_input.lower().rstrip()))
    ...

def checker(input):
    # Checks input and returns a string based on case.
    cases = {
        '.gif' : 'image/gif',
        '.jpg' : 'image/jpeg',
        '.jpeg' : 'image/jpeg',
        '.pdf' : 'application/pdf',
        '.png' : 'image/png',
        '.txt' : 'text/plain',
        '.zip' : 'application/zip'
    }

    for key in cases.keys():
        if input.endswith(key):
            return cases[key]
    return "application/octet-stream"
    ...


if __name__ == '__main__':
    main()
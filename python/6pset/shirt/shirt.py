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

Ready Player 50
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

CS50 P-Shirt
CS50 shirt

After finishing CS50 itself, students on campus at Harvard traditionally receive their very own I took CS50 t-shirt. No need to buy one online, but like to try one on virtually?

In a file called shirt.py, implement a program that expects exactly two command-line arguments:

in sys.argv[1], the name (or path) of a JPEG or PNG to read (i.e., open) as input
in sys.argv[2], the name (or path) of a JPEG or PNG to write (i.e., save) as output
The program should then overlay shirt.png (which has a transparent background) on the input after resizing and cropping the input to be the same size, saving the result as its output.

Open the input with Image.open, per pillow.readthedocs.io/en/stable/reference/Image.html#PIL.Image.open, resize and crop the input with ImageOps.fit, per pillow.readthedocs.io/en/stable/reference/ImageOps.html#PIL.ImageOps.fit, using default values for method, bleed, and centering, overlay the shirt with Image.paste, per pillow.readthedocs.io/en/stable/reference/Image.html#PIL.Image.Image.paste, and save the result with Image.save, per pillow.readthedocs.io/en/stable/reference/Image.html#PIL.Image.Image.save.

The program should instead exit via sys.exit:

if the user does not specify exactly two command-line arguments,
if the input’s and output’s names do not end in .jpg, .jpeg, or .png, case-insensitively,
if the input’s name does not have the same extension as the output’s name, or
if the specified input does not exist.
Assume that the input will be a photo of someone posing in just the right way, like these demos, so that, when they’re resized and cropped, the shirt appears to fit perfectly.

If you’d like to run your program on a photo of yourself, first drag the photo over to VS Code’s file explorer, into the same folder as shirt.py. No need to submit any photos with your code. But, if you would like, you’re welcome (but not expected) to share a photo of yourself wearing your virtual shirt in any of CS50’s communities!

Hints
Note that you can determine a file’s extension with os.path.splitext, per docs.python.org/3/library/os.path.html#os.path.splitext.
Note that open can raise a FileNotFoundError, per docs.python.org/3/library/exceptions.html#FileNotFoundError.
Note that the Pillow package comes with quite a few classes and methods, per pypi.org/project/Pillow. You might find its handbook and reference helpful to skim. You can install the package with:
pip install Pillow
You can open an image (e.g., shirt.png) with code like:

shirt = Image.open("shirt.png")
You can get the width and height, respectively, of that image as a tuple with code like:

size = shirt.size
And you can overlay that image on top of another (e.g., photo) with code like

photo.paste(shirt, shirt)
wherein the first shirt represents the image to overlay and the second shirt represents a “mask” indicating which pixels in photo to update.

Note that you can open an image (e.g., shirt.png) in VS Code by running
code shirt.png
or by double-clicking its icon in VS Code’s file explorer.

Demo

Before
before before before

After
after after after

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir shirt
to make a folder called shirt in your codespace.

Then execute

cd shirt
to change directories into that folder. You should now see your terminal prompt as shirt/ $. You can now execute

code shirt.py
to make a file called shirt.py where you’ll write your program. Be sure to run

wget https://cs50.harvard.edu/python/2022/psets/6/shirt/shirt.png
to download shirt.png. Also be sure to run

wget https://cs50.harvard.edu/python/2022/psets/6/shirt/muppets.zip
to download muppets.zip into your folder. You can run

unzip muppets.zip
to extract a collection of muppet photos!

How to Test
Here’s how to test your code manually:

Run your program with python shirt.py. Your program should exit using sys.exit and provide an error message:
Too few command-line arguments
Be sure to download muppets.zip and extract a collection of muppet photos using unzip muppets.zip. Run your program with python shirt.py before1.jpg before2.jpg before3.jpg. Your program should output:
Too many command-line arguments
Run your program with python shirt.py before1.jpg invalid_format.bmp. Your program should exit using sys.exit and provide an error message:
Invalid output
Run your program with python shirt.py before1.jpg after1.png. Your program should exit using sys.exit and provide an error message:
Input and output have different extensions
Run your program with python shirt.py non_existent_image.jpg after1.jpg. Your program should exit using sys.exit and provide an error message:
Input does not exist
Run your program with python shirt.py before1.jpg after1.jpg. Assuming you’ve downloaded and unzipped muppets.zip, your program should create an image like the below:
after
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/shirt
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/shirt
'''
import sys
from PIL import Image
from PIL import ImageOps


EXPECTED_NUMBER_OF_ARGUMENTS = 3
VALID_EXTENSIONS = ('.png','.jpg','.jpeg')
SHIRT = 'shirt.png'

def main():
    error_code = 1
    argc = len(sys.argv)
    # If less than expected number of arguments, exit with message.
    if argc < EXPECTED_NUMBER_OF_ARGUMENTS:
        print("Too few command-line arguments.")
        sys.exit(error_code)
    error_code += 1
    # If more than expected number of arguments, exit with message.
    if argc > EXPECTED_NUMBER_OF_ARGUMENTS:
        print("Too many command-line arguments.")
        sys.exit(error_code)
    error_code += 1
    # Get command-line arguments and store them
    img_input_file_path = sys.argv[1].lower()
    img_output_file_path = sys.argv[2].lower()
    # Verify correct use of command-line args
    if not img_input_file_path.endswith(VALID_EXTENSIONS):
        print('Not a valid input image file.')
        sys.exit(error_code)
    error_code += 1
    extension = get_extension(img_input_file_path)
    if not img_output_file_path.endswith(extension):
        print('Extension of output file does not match input.')
        sys.exit(error_code)
    error_code += 1
    # Try opening image to read.
    try:
        input_img_file_object = Image.open(img_input_file_path, 'r')
    except FileNotFoundError:
        print('File not found. Are you sure about the path?')
        sys.exit(error_code)
    error_code += 1
    shirt_img = Image.open(SHIRT)
    #shirt_img.save('tmp.png')
    # Resize person to fit shirt
    #input_img_file_object.save('tmp.png') To test outputs.
    input_img_file_object = ImageOps.fit(input_img_file_object, shirt_img.size)

    # Copy shirt on to person
    input_img_file_object.paste(shirt_img, mask = shirt_img )

    # Save the image to output
    input_img_file_object.save(img_output_file_path)
    # Close read file
    input_img_file_object.close()
    shirt_img.close()


def get_extension(input):
    # Takes a str and gets the extenstion.
    parts = []
    parts = input.split('.')
    output = parts[len(parts) - 1]
    return output


if __name__ == '__main__':
    main()
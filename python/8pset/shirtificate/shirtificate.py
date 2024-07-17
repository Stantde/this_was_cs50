'''

Interested in a verified certificate or a professional certificate?

CS50’s Introduction to Programming with Python
OpenCourseWare

Donate

David J. Malan
malan@harvard.edu
Facebook GitHub Instagram LinkedIn Reddit Threads Twitter

CS50 Shirtificate
John Harvard's CS50 Shirtificate

Suppose that you’d like to implement a CS50 “shirtificate,” a PDF with an image of an I took CS50 t-shirt, shirtificate.png, customized with a user’s own name.

In a file called shirtificate.py, implement a program that prompts the user for their name and outputs,
using fpdf2, a CS50 shirtificate in a file called shirtificate.pdf similar to this one
for John Harvard, with these specifications:

The orientation of the PDF should be Portrait.
The format of the PDF should be A4, which is 210mm wide by 297mm tall.
The top of the PDF should say “CS50 Shirtificate” as text, centered horizontally.
The shirt’s image should be centered horizontally.
The user’s name should be on top of the shirt, in white text.
All other details we leave to you. You’re even welcome to add borders, colors, and lines. Your shirtificate needn’t match John Harvard’s precisely. And no need to wrap long names across multiple lines.

Before writing any code, do read through fpdf2’s tutorial to learn how to use it. Then skim fpdf2’s API (application programming interface) to see all of its functions and parameters therefor.

No need to submit any PDFs with your code. But, if you would like, you’re welcome (but not expected) to share a shirtificate with your name on it in any of CS50’s communities!

Hints
Note that fpdf2 comes with a class called FPDF, which has quite a few methods, per py-pdf.github.io/fpdf2/fpdf/#fpdf.FPDF. You can install it with:
pip install fpdf2
Note that you can extend FPDF and instantiate your own subclass thereof in order to add a header to every page of a PDF,
per py-pdf.github.io/fpdf2/Tutorial.html#tuto-2-header-footer-page-break-and-image. Or you can add it as text yourself.
Note that you can disable automatic page breaks, which might otherwise cause your PDF to overflow
from one page to two, with set_auto_page_break, per py-pdf.github.io/fpdf2/Margins.html.
Note that a cell’s height can be negative, to move it upward.
You can open shirtificate.pdf, once outputted, by clicking it in VS Code’s file explorer.
Demo

Before You Begin
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

mkdir shirtificate
to make a folder called shirtificate in your codespace.

Then execute

cd shirtificate
to change directories into that folder. You should now see your terminal prompt as shirtificate/ $. Now execute

wget https://cs50.harvard.edu/python/2022/psets/8/shirtificate/shirtificate.png
to get a copy of the shirtificate.png image for your certificate. Finally, execute

code shirtificate.py
to make a file called shirtificate.py where you’ll write your program.

How to Test
Here’s how to test your code manually:

Run your program with shirtificate.py. Make sure your program prompts you for a name. Enter your own name and press Enter. Your program should create a file, shirtificate.pdf, containing the name you entered as input overlaid on a rendering of shirtificate.png.
Try a few other names for good measure, too!
You can execute the below to check your code using check50, a program that CS50 will use to test your code when you submit. But be sure to test it yourself as well!

check50 cs50/problems/2022/python/shirtificate
Green smilies mean your program has passed a test! Red frownies will indicate your program output something unexpected. Visit the URL that check50 outputs to see the input check50 handed to your program, what output it expected, and what output your program actually gave.

How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2022/python/shirtificate
'''
from fpdf import FPDF
from fpdf import Align
from fpdf import YPos

#implement a program that prompts the user for their name
def main():
    name = input("Name: ") + ' took CS50'
    shirt = "shirtificate.png"
    y = 593/2
    pdf = create_pdf()
    pdf = print_label_across_top(pdf)
    pdf = add_shirt_to_pdf(pdf, shirt)
    pdf = print_label_at_pos(pdf, y, name)
    write_pdf_file(pdf)
    ...

def create_pdf():
    pdf = FPDF()
    pdf.add_page()
    return pdf

def print_label_across_top(pdf):
    pdf.set_font("helvetica", "B", 16)
    pdf.cell(text = "CS50 Shirtificate", new_y="NEXT", center = True)
    return pdf

def write_pdf_file(pdf):
    pdf.output("shirtificate.pdf")
    return

def add_shirt_to_pdf(pdf, shirt):
    pdf.image(shirt, x= Align.C) # dim 593, 592
    return pdf


def print_label_at_pos(pdf, loc, name):
    pdf.set_text_color(255,255,255)
    #pdf.cell(text=' ', new_y=YPos.TOP, center = True)
    pdf.text(80,65, name ) #how do I reposition the cell?
    return pdf
    ...

'''
The orientation of the PDF should be Portrait.
The format of the PDF should be A4, which is 210mm wide by 297mm tall.
The top of the PDF should say “CS50 Shirtificate” as text, centered horizontally.
The shirt’s image should be centered horizontally.
The user’s name should be on top of the shirt, in white text.
All other details we leave to you. You’re even welcome to add borders, colors,
and lines. Your shirtificate needn’t match John Harvard’s precisely.
And no need to wrap long names across multiple lines.
'''
if __name__ == '__main__':
    main()

#https://py-pdf.github.io/fpdf2/Tutorial.html
#This is a tutorial program to use fpdf2
from fpdf import FPDF

pdf = FPDF()
pdf.add_page()
pdf.set_font("helvetica", "B", 16)
pdf.cell(40, 10, "Hello World!")
pdf.output("tuto1.pdf")

'''
After including the library file, we create an FPDF object. The FPDF constructor is used here with the default values: pages are in A4 portrait and the measure unit is millimeter. It could have been specified explicitly with:

pdf = FPDF(orientation="P", unit="mm", format="A4")
It is possible to set the PDF in landscape mode (L) or to use other page formats (such as Letter and Legal) and measure units (pt, cm, in).

There is no page for the moment, so we have to add one with add_page. The origin is at the upper-left corner and the current position is by default placed at 1 cm from the borders; the margins can be changed with set_margins.

Before we can print text, it is mandatory to select a font with set_font, otherwise the document would be invalid. We choose Helvetica bold 16:

pdf.set_font('helvetica', 'B', 16)
We could have specified italics with I, underlined with U or a regular font with an empty string (or any combination). Note that the font size is given in points, not millimeters (or another user unit); it is the only exception. The other built-in fonts are Times, Courier, Symbol and ZapfDingbats.

We can now print a cell with cell. A cell is a rectangular area, possibly framed, which contains some text. It is rendered at the current position. We specify its dimensions, its text (centered or aligned), if borders should be drawn, and where the current position moves after it (to the right, below or to the beginning of the next line). To add a frame, we would do this:

pdf.cell(40, 10, 'Hello World!', 1)
To add a new cell next to it with centered text and go to the next line, we would do:

pdf.cell(60, 10, 'Powered by FPDF.', new_x="LMARGIN", new_y="NEXT", align='C')
Remark: the line break can also be done with ln. This method allows to specify in addition the height of the break.

Finally, the document is closed and saved under the provided file path using output. Without any parameter provided, output() returns the PDF bytearray buffer.
'''

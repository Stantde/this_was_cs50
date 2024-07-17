If unfamiliar with Markdown syntax, you might find GitHub’s Basic Writing and Formatting Syntax
helpful. If you are using the CS50 Codespace and are prompted to “Open in CS50 Lab”, you can simply
press cancel to open in the Editor. You can also preview your .md file by clicking the ‘preview’
icon as explained here: Markdown Preview in vscode. Standard software project READMEs can often run
into the thousands or tens of thousands of words in length; yours need not be that long, but should
at least be several hundred words that describe things in detail!

Your README.md file should be minimally multiple paragraphs in length, and should explain what your
project is, what each of the files you wrote for the project contains and does, and if you debated
certain design choices, explaining why you made them. Ensure you allocate sufficient time and
energy to writing a README.md that documents your project thoroughly. Be proud of it! If it is too
short, the system will reject it.

Execute the submit50 command below from within your ~/project directory (or from whichever
directory contains README.md file and your project’s code, which must also be submitted). If your
project does not meet all the requirements above, it may be rejected, so be sure you have satisfied
all of the bullet points atop this specification and written a thorough README:
#>

journal.py
#### Video Demo:  <URL HERE>
#### Description:

This will be my guide through this project.
<code breakdown
decision to splis
class
or classes
jounr
main
args
>

TODO

"A short pencil will outlast a long memory."

My father told me this when I was younger, and it has stuck with me since. Of course, I didn't
think that much about it at the time. I've since written many papers, notes, emails, text messages,
and test results. I have come to the realization that these writings, in all their various forms,
are tangible memories, immune to the effects of mental degradation. I don't write as much as I
would like, but I consider journaling to be like clicking the save button for one's life. It
becomes a sort of timeless manifestation of self which can be passed from one literate being to
another. It allows one to connect not only to one's self, but also to the greater community.

Towards the end of connecting, I have decided to create a program for recording one's thoughts and
life experiences. It will be up to the user to determine if they will share their writings with
others, but I hope to facilitate the process by which their thoughts are made real. My journey into
cs50x began with a desire to learn more about python. I was drawn in by the charismatic lecturer,
David Malan, and I thought it would be wise to follow along with each lesson, beginning from
scratch. As an entrepreneur, I thought I might be able to market these newly acquired computer
science skills, or at least learn how to automate the boring stuff (Shout out to Al Sweigart!).
With this project I wanted to create something simple yet sufficiently complex to fulfill project
requirements. Additionally, I wanted to create something which may be useful to me or others in the
future.

This journal program requires book.py. book.py is a separate module I have written in which I have
distilled the concept of a journal down to its indivisble elements. Wanting not to re-create the
wheel, but instead stand on the shoulders of giants, I searched pypi.org for a data structure I
could use. My search for the sort of data structure I had envisioned led me to ask the question,
"What constitutes a journal?" What seemed like a straight-forward question was anything but. In
someways, a journal resembles a large notepad, a financial ledger, or even a book. It may have a
title, multiple entries or pages. Each page, like each journal, is unique and different from the
many others that are similar to it. A journal is able to keep a record. To me, there's much overlap
underlying the idea of a financial ledger, a journal, and a book. Not one to entertain my own
thoughts for too long, I decided to converse with co-workers and friends about the idea of a
journal.

My partner eventually told me about the idea behind Pablo Picasso's single line drawings. Pablo's
drawings, though simple in appearance, are so distilled that one may gaze upon the drawing and
understand the underlying subject matter. It may appear as though the man accomplished these
amazing feats in a matter of seconds, but his technique was revolutionary for his time. It perhaps
would have taken he and his contemporaries less time create a more detailed painting. However, his
goal was to chip away as much from the subject matter until it could be summed up simply and
elegantly. Thinking this way, a journal seems to be a specialized book. I could write the entire
program in a single module, but it seems that creating separate modules for main.py and book/page
objects would best encapsulate the idea of simplicity, elegance, and community.

<# UNDER CONSTRUCTION #>
book.py contains the outline of a journal. It contains methods for constructing the book-type object,
adding pages to the book, saving books, and loading pages into memory for review. When the book constructor is called, an object with a unique identifier visible to the system only, a name established by the user, the
journal's filepath for data persistence, a size which reflects the number of associated pages, and
a password for securing the data is created.

What does a page look like?


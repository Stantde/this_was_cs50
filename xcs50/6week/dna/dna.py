#!/usr/local/bin/python
'''

This is CS50x 2024. 🎉 Curious how your 2023 work counts toward the 2024 course?
See our FAQs if you started in 2023 or earlier. Interested in a verified certificate,
a professional certificate, or transfer credit and accreditation?

This is CS50
CS50’s Introduction to Computer Science
OpenCourseWare

Donate

David J. Malan
malan@harvard.edu
Facebook GitHub Instagram LinkedIn Reddit Threads Twitter

Ready Player 50
Zoom Meetingsnew
CS50.ai
Ed Discussion for Q&A
Visual Studio Code
CS50 Educator Workshop
CS50x Puzzle Day 2024
Gallery of Final Projects🖼️
What’s new for 2024?
Week 0 Scratch
Week 1 C
Week 2 Arrays
Week 3 Algorithms
Week 4 Memory
Week 5 Data Structures
Week 6 Python
Week 6.5 Artificial Intelligence
Week 7 SQL
Week 8 HTML, CSS, JavaScript
Week 9 Flask
Week 10 Cybersecurity
Additional Practice
Final Project
Gallery of Final Projects🖼️
Seminars
Academic Honesty
CS50 Certificate
FAQs
Gradebook
Staff
Syllabus
Apple TV
edX
Google TV
Harvard Extension School
Harvard Summer School
YouTube
Manual Pages
Style Guide
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
Twitter Account
Twitter Community
YouTube
Courses
CS50x
CS50 AI
CS50 Business
CS50 Cybersecurity
CS50 for Lawyers
CS50 Games
CS50 Python
CS50 Scratch
CS50 SQL
CS50 Technology
CS50 Web
Harvard Shop

License

2024-02-27 14:11:30

DNA
Problem to Solve
DNA, the carrier of genetic information in living things, has been used in criminal justice for decades. But how, exactly, does DNA profiling work? Given a sequence of DNA, how can forensic investigators identify to whom it belongs?

In a file called dna.py in a folder called dna, implement a program that identifies to whom a sequence of DNA belongs.

Demo

Distribution Code
For this problem, you’ll extend the functionality of code provided to you by CS50’s staff.

Download the distribution code
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:

$
Next execute

wget https://cdn.cs50.net/2023/fall/psets/6/dna.zip
in order to download a ZIP called dna.zip into your codespace.

Then execute

unzip dna.zip
to create a folder called dna. You no longer need the ZIP file, so you can execute

rm dna.zip
and respond with “y” followed by Enter at the prompt to remove the ZIP file you downloaded.

Now type

cd dna
followed by Enter to move yourself into (i.e., open) that directory. Your prompt should now resemble the below.

dna/ $
Execute ls by itself, and you should see a few files and folders:

databases/ dna.py sequences/
If you run into any trouble, follow these same steps again and see if you can determine where you went wrong!

Background
DNA is really just a sequence of molecules called nucleotides, arranged into a particular shape (a double helix). Every human cell has billions of nucleotides arranged in sequence. Each nucleotide of DNA contains one of four different bases: adenine (A), cytosine (C), guanine (G), or thymine (T). Some portions of this sequence (i.e., genome) are the same, or at least very similar, across almost all humans, but other portions of the sequence have a higher genetic diversity and thus vary more across the population.

One place where DNA tends to have high genetic diversity is in Short Tandem Repeats (STRs). An STR is a short sequence of DNA bases that tends to repeat consecutively numerous times at specific locations inside of a person’s DNA. The number of times any particular STR repeats varies a lot among individuals. In the DNA samples below, for example, Alice has the STR AGAT repeated four times in her DNA, while Bob has the same STR repeated five times.

Sample STRs

Using multiple STRs, rather than just one, can improve the accuracy of DNA profiling. If the probability that two people have the same number of repeats for a single STR is 5%, and the analyst looks at 10 different STRs, then the probability that two DNA samples match purely by chance is about 1 in 1 quadrillion (assuming all STRs are independent of each other). So if two DNA samples match in the number of repeats for each of the STRs, the analyst can be pretty confident they came from the same person. CODIS, the FBI’s DNA database, uses 20 different STRs as part of its DNA profiling process.

What might such a DNA database look like? Well, in its simplest form, you could imagine formatting a DNA database as a CSV file, wherein each row corresponds to an individual, and each column corresponds to a particular STR.

name,AGAT,AATG,TATC
Alice,28,42,14
Bob,17,22,19
Charlie,36,18,25
The data in the above file would suggest that Alice has the sequence AGAT repeated 28 times consecutively somewhere in her DNA, the sequence AATG repeated 42 times, and TATC repeated 14 times. Bob, meanwhile, has those same three STRs repeated 17 times, 22 times, and 19 times, respectively. And Charlie has those same three STRs repeated 36, 18, and 25 times, respectively.

So given a sequence of DNA, how might you identify to whom it belongs? Well, imagine that you looked through the DNA sequence for the longest consecutive sequence of repeated AGATs and found that the longest sequence was 17 repeats long. If you then found that the longest sequence of AATG is 22 repeats long, and the longest sequence of TATC is 19 repeats long, that would provide pretty good evidence that the DNA was Bob’s. Of course, it’s also possible that once you take the counts for each of the STRs, it doesn’t match anyone in your DNA database, in which case you have no match.

In practice, since analysts know on which chromosome and at which location in the DNA an STR will be found, they can localize their search to just a narrow section of DNA. But we’ll ignore that detail for this problem.

Your task is to write a program that will take a sequence of DNA and a CSV file containing STR counts for a list of individuals and then output to whom the DNA (most likely) belongs.

Specification
The program should require as its first command-line argument the name of a CSV file containing the STR counts for a list of individuals and should require as its second command-line argument the name of a text file containing the DNA sequence to identify.
If your program is executed with the incorrect number of command-line arguments, your program should print an error message of your choice (with print). If the correct number of arguments are provided, you may assume that the first argument is indeed the filename of a valid CSV file and that the second argument is the filename of a valid text file.
Your program should open the CSV file and read its contents into memory.
You may assume that the first row of the CSV file will be the column names. The first column will be the word name and the remaining columns will be the STR sequences themselves.
Your program should open the DNA sequence and read its contents into memory.
For each of the STRs (from the first line of the CSV file), your program should compute the longest run of consecutive repeats of the STR in the DNA sequence to identify. Notice that we’ve defined a helper function for you, longest_match, which will do just that!
If the STR counts match exactly with any of the individuals in the CSV file, your program should print out the name of the matching individual.
You may assume that the STR counts will not match more than one individual.
If the STR counts do not match exactly with any of the individuals in the CSV file, your program should print No match.
Hints
You may find Python’s csv module helpful for reading CSV files into memory. Of particular help might be csv.DictReader.
For instance, if a file like foo.csv has a header row, wherein each string is the name of some field, here’s how you might print those fieldnames as a list:
import csv

with open("foo.csv") as file:
    reader = csv.DictReader(file)
    print(reader.fieldnames)
And here’s how you read all of the (other) rows from a CSV into a list, wherein each element is a dict that represents that row:
import csv

rows = []
with open("foo.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        rows.append(row)
The open and read functions might also prove useful for reading text files into memory.
Consider what data structures might be helpful for keeping tracking of information in your program. A list or a dict may prove useful.
Remember we’ve defined a function (longest_match) that, given both a DNA sequence and an STR as inputs, returns the maximum number of times that the STR repeats. You can then use that function in other parts of your program!
Walkthrough

How to Test
While check50 is available for this problem, you’re encouraged to first test your code on your own for each of the following.

Run your program as python dna.py databases/small.csv sequences/1.txt. Your program should output Bob.
Run your program as python dna.py databases/small.csv sequences/2.txt. Your program should output No match.
Run your program as python dna.py databases/small.csv sequences/3.txt. Your program should output No match.
Run your program as python dna.py databases/small.csv sequences/4.txt. Your program should output Alice.
Run your program as python dna.py databases/large.csv sequences/5.txt. Your program should output Lavender.
Run your program as python dna.py databases/large.csv sequences/6.txt. Your program should output Luna.
Run your program as python dna.py databases/large.csv sequences/7.txt. Your program should output Ron.
Run your program as python dna.py databases/large.csv sequences/8.txt. Your program should output Ginny.
Run your program as python dna.py databases/large.csv sequences/9.txt. Your program should output Draco.
Run your program as python dna.py databases/large.csv sequences/10.txt. Your program should output Albus.
Run your program as python dna.py databases/large.csv sequences/11.txt. Your program should output Hermione.
Run your program as python dna.py databases/large.csv sequences/12.txt. Your program should output Lily.
Run your program as python dna.py databases/large.csv sequences/13.txt. Your program should output No match.
Run your program as python dna.py databases/large.csv sequences/14.txt. Your program should output Severus.
Run your program as python dna.py databases/large.csv sequences/15.txt. Your program should output Sirius.
Run your program as python dna.py databases/large.csv sequences/16.txt. Your program should output No match.
Run your program as python dna.py databases/large.csv sequences/17.txt. Your program should output Harry.
Run your program as python dna.py databases/large.csv sequences/18.txt. Your program should output No match.
Run your program as python dna.py databases/large.csv sequences/19.txt. Your program should output Fred.
Run your program as python dna.py databases/large.csv sequences/20.txt. Your program should output No match.
Correctness
check50 cs50/problems/2024/x/dna
Style
style50 dna.py
How to Submit
submit50 cs50/problems/2024/x/dna
Why does my submission pass check50, but shows “No results” in my Gradebook after running submit50?

In some cases, submit50 may not grade the assignment due to inconsistent formatting in your dna.py file. To fix this issue, run black dna.py in the dna folder. Address any issues that are revealed. Run check50 again to ensure your submission still functions. Finally, run the submit50 command above again. Your result will appear in your Gradebook within a few minutes.

Please note that if there is a numerical score next to your dna submission in the submissions area of your Gradebook, the procedure discussed above does not apply to you. Likely, you have not fully addressed the requirements of the problem set and should rely upon check50 for clues as to what work remains.
'''
import csv
import sys


def main():

    # Check for command-line usage
    if check_command_line_usage() in [1, 2, 3]:
        sys.exit(1)
    database_filename = sys.argv[1]
    sequence_filename = sys.argv[2]

    # TODO: Read database file into a variable
    dna_database = []
    dna_database_headers = ''
    with open(database_filename, newline='') as csvfile:
        reader_object = csv.DictReader(csvfile)
        dna_database_headers = reader_object.fieldnames
        short_tandem_repeats = dna_database_headers[1:]
        for row in reader_object:
            dna_database.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sequence_filename, newline='') as file:
        reader_object = csv.reader(file)
        for row in reader_object:
            dna_sequence = str(row)

    # TODO: Find longest match of each STR in DNA sequence
    strs_in_unknown = ["unknown"]
    for subsequence in short_tandem_repeats:
        strs_in_unknown.append(longest_match(dna_sequence, subsequence))

    killer_dna = dict(zip(dna_database[0].keys(), strs_in_unknown))
    # TODO: Check database for matching profiles
    # Who has [unk, 4 1 5], it's bob
    # Go through each person in the database
    match_found = False
    for person in dna_database:

        for entry in short_tandem_repeats:
            if int(person.get(entry)) != killer_dna.get(entry):
                break
            # here's the stopping point. I found all the matches. How do I print the name?
            if entry == short_tandem_repeats[-1]:
                match_found = True
                print(person.get('name'))
    if not match_found:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


def check_command_line_usage():
    # argv[0]: call to program
    # argv[1]: first command-line argument following program name
    # argv[n]: n th command-line argument following program name
    # Check the number of command-line arguments to prevent indexing errors.
    if len(sys.argv) != 3:
        print("Program requires two command line arguments.")
        return 1
    # The first command-line argument is the name of a CSV file containing the STR counts for a list of individuals
    elif not sys.argv[1].endswith(".csv"):
        print(f"First command line argument '{sys.argv[1]}' does not end with .csv")
        return 2
    # The second command-line argument is the name of a text file containing the DNA sequence to identify.
    elif not sys.argv[2].endswith(".txt"):
        print(f"Second command line argument '{sys.argv[2]}' does not end with .txt")
        return 3
    else:
        return 0  # pass


main()

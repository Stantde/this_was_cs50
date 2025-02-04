/*
I'll probably forget all about this code later, so I'll include some notes for myself for later
reference. Try column limit = 100.
020 Background
070  Specification
146 Libraries
154 Structs
157 Prototypes











Background
In anticipation of this problem, we spent the past several days taking photos around campus, all of
which were saved on a digital camera as JPEGs on a memory card. Unfortunately, we somehow deleted
them all! Thankfully, in the computer world, “deleted” tends not to mean “deleted” so much as
“forgotten.” Even though the camera insists that the card is now blank, we’re pretty sure that’s
not quite true. Indeed, we’re hoping (er, expecting!) you can write a program that recovers the
photos for us!

Even though JPEGs are more complicated than BMPs, JPEGs have “signatures,” patterns of bytes that
can distinguish them from other file formats. Specifically, the first three bytes of JPEGs are

0xff 0xd8 0xff

from first byte to third byte, left to right. The fourth byte, meanwhile, is either 0xe0, 0xe1,
0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, or 0xef. Put another
way, the fourth byte’s first four bits are 1110.

Odds are, if you find this pattern of four bytes on media known to store photos (e.g., my memory
card), they demarcate the start of a JPEG. To be fair, you might encounter these patterns on some
disk purely by chance, so data recovery isn’t an exact science.

Fortunately, digital cameras tend to store photographs contiguously on memory cards, whereby each
photo is stored immediately after the previously taken photo. Accordingly, the start of a JPEG
usually demarks the end of another. However, digital cameras often initialize cards with a FAT
file system whose “block size” is 512 bytes (B). The implication is that these cameras only write
to those cards in units of 512 B. A photo that’s 1 MB (i.e., 1,048,576 B) thus takes up
1048576 ÷ 512 = 2048 “blocks” on a memory card. But so does a photo that’s, say, one byte smaller
(i.e., 1,048,575 B)! The wasted space on disk is called “slack space.” Forensic investigators often
look at slack space for remnants of suspicious data.

The implication of all these details is that you, the investigator, can probably write a program
that iterates over a copy of my memory card, looking for JPEGs’ signatures. Each time you find a
signature, you can open a new file for writing and start filling that file with bytes from my
memory card, closing that file only once you encounter another signature. Moreover, rather than
read my memory card’s bytes one at a time, you can read 512 of them at a time into a buffer for
efficiency’s sake. Thanks to FAT, you can trust that JPEGs’ signatures will be “block-aligned.”
That is, you need only look for those signatures in a block’s first four bytes.

Realize, of course, that JPEGs can span contiguous blocks. Otherwise, no JPEG could be larger
than 512 B. But the last byte of a JPEG might not fall at the very end of a block. Recall the
possibility of slack space. But not to worry. Because this memory card was brand-new when I
started snapping photos, odds are it’d been “zeroed” (i.e., filled with 0s) by the manufacturer,
in which case any slack space will be filled with 0s. It’s okay if those trailing 0s end up in the
JPEGs you recover; they should still be viewable.

Now, I only have one memory card, but there are a lot of you! And so I’ve gone ahead and created a
“forensic image” of the card, storing its contents, byte after byte, in a file called card.raw. So
that you don’t waste time iterating over millions of 0s unnecessarily, I’ve only imaged the first
few megabytes of the memory card. But you should ultimately find that the image contains 50 JPEGs.

Specification
Status: DONE 09/09/2023 02:56
*Implement a program called recover that recovers JPEGs from a forensic image.

Status: DONE 09/07/2023 09:46
*Implement your program in a file called recover.c in a directory called recover.

Status: DONE 09/07/2023 10:17
*Your program should accept exactly one command-line argument, the name of a forensic image from
which to recover JPEGs.

Status: DONE 09/07/2023 10:17
*If your program is not executed with exactly one command-line argument, it should remind the user
of correct usage, and main should return 1.

Status: DONE 09/08/2023 22:37
*If the forensic image cannot be opened for reading, your program should inform the user as much,
and main should return 1.

Status: DONE 09/09/2023 02:57
*The files you generate should each be named ###.jpg, where ### is a three-digit decimal number,
starting with 000 for the first image and counting up.

Status: DONE 09/09/2023 03:31
*Your program, if it uses malloc, must not leak any memory.

Hints
Keep in mind that you can open card.raw programmatically with fopen, as with the below, provided
argv[1] exists.

FILE *file = fopen(argv[1], "r");
When executed, your program should recover every one of the JPEGs from card.raw, storing each as a
separate file in your current working directory. Your program should number the files it outputs by
naming each ###.jpg, where ### is three-digit decimal number from 000 on up. Befriend sprintf and
note that sprintf stores a formatted string at a location in memory. Given the prescribed ###.jpg
format for a JPEG’s filename, how many bytes should you allocate for that string? (Don’t forget
the NUL character!)

You need not try to recover the JPEGs’ original names. To check whether the JPEGs your program spit
out are correct, simply double-click and take a look! If each photo appears intact, your operation
was likely a success!

Odds are, though, the JPEGs that the first draft of your code spits out won’t be correct. (If you
open them up and don’t see anything, they’re probably not correct!) Execute the command below to
delete all JPEGs in your current working directory.

$ rm *.jpg
If you’d rather not be prompted to confirm each deletion, execute the command below instead.

$ rm -f *.jpg
Just be careful with that -f switch, as it “forces” deletion without prompting you.
Keep in mind, too, that you can read data from a file using fread, which will read data from a
file into a location in memory. Per its manual page, fread returns the number of bytes that it has
read, in which case it should either return 512 or 0, given that card.raw contains some number of
512-byte blocks. In order to read every block from card.raw, after opening it with fopen, it should
suffice to use a loop like:

while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
{


}
Testing
Execute the below to evaluate the correctness of your code using check50. But be sure to compile
and test it yourself as well!

check50 cs50/problems/2023/x/recover
Execute the below to evaluate the style of your code using style50.

style50 recover.c
How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2023/x/recover

submit50 --log-level=debug cs50/problems/2023/x/recover
*/
// Library (or libraries)
#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 512

// Structs and the like
typedef uint8_t BYTE;

// Prototypes
char *create_new_filename(int counter, char *of);
bool header_search(BYTE *buffer);

// Global variables
BYTE jpg_header[3] = {0xFF, 0xD8, 0xFF};

// Implement a program called recover that recovers JPEGs from a forensic image.
int main(int argc, char *argv[])
{
    // If your program is not executed with exactly one command-line argument, it should remind
    // the user of correct usage, and main should return 1.
    if (argc != 2)
    {
        printf("USAGE: %s file.extension\n", argv[0]);
        return 1;
    }
    // Store name of file being opened.
    char *infile = argv[1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    // If the forensic image cannot be opened for reading, your program should inform the user as
    // much, and main should return 1.
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    int counter = 0;
    char *output_filename = malloc(20 * sizeof(char));
    BYTE *buffer = malloc(BLOCK_SIZE * sizeof(BYTE));
    // Read four bytes at a time until the header is found.
    while (fread(buffer, 1, 4, inptr) == 4)
    {
        if (header_search(buffer))
        {
            // Once the header is found
            // The first time, write the first four bytes to a new file "000.jpg"
            char *outfile = create_new_filename(counter, output_filename);
            counter++;
            // Open output file
            FILE *outptr = fopen(outfile, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                free(buffer);
                printf("Could not create %s.\n", outfile);
                return 1;
            }
            fwrite(buffer, 1, 4, outptr);

            // Read the remaining bytes of the initial block, then write them to the first open file.
            fread(buffer, 1, (BLOCK_SIZE - 4), inptr);
            fwrite(buffer, 1, (BLOCK_SIZE - 4), outptr);

            // Read a block at a time. If the block contains a jpeg header, close the file, create a new file and continue writing
            while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
            {
                if (header_search(buffer))
                {
                    fclose(outptr);
                    // create a new file name.
                    outfile = create_new_filename(counter, output_filename);
                    counter++;
                    // Create a new file.
                    outptr = fopen(outfile, "w");
                    if (outptr == NULL)
                    {
                        fclose(inptr);
                        free(buffer);
                        printf("Could not create %s.\n", outfile);
                        return 1;
                    }
                }
                // Continue writing.
                fwrite(buffer, 1, BLOCK_SIZE, outptr);
            }
            fclose(outptr);
        }
    }
    // printf("The total count is: %i\n", counter);
    free(buffer);
    free(output_filename);
    fclose(inptr);
}
// Take the counter and return a "filename" as counter.JPEG
// *The files you generate should each be named ###.jpg, where ### is a three-digit decimal number,
// starting with 000 for the first image and counting up.
char *create_new_filename(int counter, char *of)
{
    char prefix[30] = "";
    if (counter < 10)
    {
        strcat(prefix, "0");
    }
    char number_holder[30] = "";
    char suffix[30] = ".jpg";
    strcat(prefix, "0");
    sprintf(number_holder, "%i", counter);
    strcat(prefix, number_holder);
    strcat(prefix, suffix);
    int i = 0;
    while (prefix[i] != '\0')
    {
        of[i] = prefix[i];
        i++;
    }
    of[i] = '\0';
    return of;
}

// Checks for the existence of a JPEG header.
bool header_search(BYTE *buffer)
{
    bool header_match = true;
    for (int i = 0; i < 3; i++)
    {
        if (buffer[i] != jpg_header[i])
        {
            header_match = false;
        }
    }
    if (buffer[3] < 0xE0 || buffer[3] > 0xEF)
    {
        header_match = false;
    }

    return header_match;
}

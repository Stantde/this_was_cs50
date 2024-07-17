// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Read input's WAVFILEHEADER (44bytes)
    BYTE header[HEADER_SIZE];
    BYTE *head_space = malloc(sizeof(BYTE) * 44);
    if (head_space == NULL)
    {
        printf("Unable to free space\n");
        fclose(input);
        fclose(output);
        return 2;
    }

    fread(head_space, sizeof(BYTE), HEADER_SIZE, input);

    // Write the header to the output file
    fwrite(head_space, sizeof(BYTE), HEADER_SIZE, output);

    // Read input's sample byte
    int16_t buffer;
    // Multiply the sample by the factor
    // Write samples to output
    while ((fread(&buffer, sizeof(int16_t), 1, input) == 1))
    {
        buffer = factor * buffer;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }


    // TODO: Read samples from input file and write updated data to output file

    // Close files
    free(head_space);
    fclose(input);
    fclose(output);
}

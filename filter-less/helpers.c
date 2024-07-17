#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void swap(RGBTRIPLE *a_pixel, RGBTRIPLE *b_pixel);
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // For every row.
    for (int i = 0; i < height; i++)
    {
        // For every jth pixel in the ith row.
        for (int j = 0; j < width; j++)
        {
            // Convert the the pixel to grayscale by taking the original int value of rgb and giving each new rgb the average value.
            // Compute average value.
            float avg_rgb = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            // Assign average value to r, g, and b, of pixel[i][j].
            image[i][j].rgbtBlue = round(avg_rgb * 1.0);
            image[i][j].rgbtGreen = round(avg_rgb * 1.0);
            image[i][j].rgbtRed = round(avg_rgb * 1.0);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // For every row.
    for (int i = 0; i < height; i++)
    {
        // For every jth pixel in the ith row.
        for (int j = 0; j < width; j++)
        {
            // Compute sepia value.
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            // If sepia greater that max, store max as sepia value
            int max_color_value = 255;
            if (sepiaRed > max_color_value)
            {
                sepiaRed = max_color_value;
            }
            if (sepiaGreen > max_color_value)
            {
                sepiaGreen = max_color_value;
            }
            if (sepiaBlue > max_color_value)
            {
                sepiaBlue = max_color_value;
            }

            // Assign sepia value to r, g, and b, of pixel[i][j].
            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtRed = round(sepiaRed);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // For every row.
    for (int i = 0; i < height; i++)
    {
        // For every jth pixel in the ith row.
        for (int j = 0; j < width; j++)
        {
            // Calculate width_index
            int width_index = width - 1;
            swap(&image[i][j], &image[i][width_index-j]);
            // when j = width_index / 2, stop swapping
            if (j == width_index / 2)
            {
                j = width;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Allocate memory for copy of image.
    RGBTRIPLE(*copy_of_image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    // Ensure copy_of_image created.
    if (copy_of_image == NULL)
    {
        printf("Not enough memory to store copy of image.\n");
        return;
    }
    // Copy image into copy of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_of_image[i][j] = image[i][j];
        }
    }
    // Start work
    RGBTRIPLE blur_avg;
    // Initialize to zero.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rgbtBlue = 0, rgbtGreen = 0, rgbtRed = 0;
            int above_coord = i - 1, bottom_coord = i + 1;
            int left_coord = j - 1, right_coord = j + 1;
            int top_avg, side_avg, low_avg; // maybe not needed.
            int count = 0;

            // Check pixels above
            // top left
            if (above_coord > -1 && left_coord > -1)
                // if it exists, increase count and add top to blur avg
            {
                rgbtBlue += copy_of_image[above_coord][left_coord].rgbtBlue;
                rgbtGreen += copy_of_image[above_coord][left_coord].rgbtGreen;
                rgbtRed += copy_of_image[above_coord][left_coord].rgbtRed;
                count++;
            }
            // top
            if (above_coord > -1)
                // if it exists, increase count and add top top average
            {
                rgbtBlue += copy_of_image[above_coord][j].rgbtBlue;
                rgbtGreen += copy_of_image[above_coord][j].rgbtGreen;
                rgbtRed += copy_of_image[above_coord][j].rgbtRed;
                count++;
            }
            // top right
            if (above_coord > -1 && right_coord < width)
                // if it exists, increase count and add top to blur avg
            {
                rgbtBlue += copy_of_image[above_coord][right_coord].rgbtBlue;
                rgbtGreen += copy_of_image[above_coord][right_coord].rgbtGreen;
                rgbtRed += copy_of_image[above_coord][right_coord].rgbtRed;
                count++;
            }
            // check pixels beside
            // left
            if (left_coord > -1)
                // if it exists, increase count and add top to blur avg
            {
                rgbtBlue += copy_of_image[i][left_coord].rgbtBlue;
                rgbtGreen += copy_of_image[i][left_coord].rgbtGreen;
                rgbtRed += copy_of_image[i][left_coord].rgbtRed;
                count++;
            }
            // self
            rgbtBlue += copy_of_image[i][j].rgbtBlue;
            rgbtGreen += copy_of_image[i][j].rgbtGreen;
            rgbtRed += copy_of_image[i][j].rgbtRed;
            count++;

            // right
            if (right_coord < width)
                // if it exists, increase count and add top to blur avg
            {
                rgbtBlue += copy_of_image[i][right_coord].rgbtBlue;
                rgbtGreen += copy_of_image[i][right_coord].rgbtGreen;
                rgbtRed += copy_of_image[i][right_coord].rgbtRed;
                count++;
            }
            // check pixels below
            // bottom left
            if (bottom_coord < height && left_coord > -1)
                // if it exists, increase count and add top to blur avg
            {
                rgbtBlue += copy_of_image[bottom_coord][left_coord].rgbtBlue;
                rgbtGreen += copy_of_image[bottom_coord][left_coord].rgbtGreen;
                rgbtRed += copy_of_image[bottom_coord][left_coord].rgbtRed;
                count++;
            }
            // bottom
            if (bottom_coord < height)
                // if it exists, increase count and add top top average
            {
                rgbtBlue += copy_of_image[bottom_coord][j].rgbtBlue;
                rgbtGreen += copy_of_image[bottom_coord][j].rgbtGreen;
                rgbtRed += copy_of_image[bottom_coord][j].rgbtRed;
                count++;
            }
            // bottom right
            if (bottom_coord < height && right_coord < width)
                // if it exists, increase count and add top to blur avg
            {
                rgbtBlue += copy_of_image[bottom_coord][right_coord].rgbtBlue;
                rgbtGreen += copy_of_image[bottom_coord][right_coord].rgbtGreen;
                rgbtRed += copy_of_image[bottom_coord][right_coord].rgbtRed;
                count++;
            }
            // time to average
            rgbtBlue = rgbtBlue / count * 1.0;
            rgbtGreen = rgbtGreen / count * 1.0;
            rgbtRed = rgbtRed / count * 1.0;

            // then  assignment
            image[i][j].rgbtBlue = round(rgbtBlue);
            image[i][j].rgbtGreen = round(rgbtGreen);
            image[i][j].rgbtRed = round(rgbtRed);

        }
    }
    // Free memory for copy of image
    free(copy_of_image);
    return;
}
void swap(RGBTRIPLE *a_pixel, RGBTRIPLE *b_pixel)
{
    RGBTRIPLE tmp_pixel = *a_pixel;
    *a_pixel = *b_pixel;
    *b_pixel = tmp_pixel;
    return;
}
/*
Be sure to test all of your filters on the sample bitmap files provided!

Execute the below to evaluate the correctness of your code using check50. But be sure to
compile and test it yourself as well!

check50 cs50/problems/2023/x/filter/less
Execute the below to evaluate the style of your code using style50.

style50 helpers.c
How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2023/x/filter/less
*/
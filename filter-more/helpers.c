#include "helpers.h"
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void hu(void);
void swap(RGBTRIPLE *a_pixel, RGBTRIPLE *b_pixel);
int sobel_kernel_gx(int eval_pixel_row, int eval_pixel_column);
int sobel_kernel_gy(int eval_pixel_row, int eval_pixel_column);

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
            swap(&image[i][j], &image[i][width_index - j]);
            // when j = width_index / 2, stop swapping
            if (j == width_index / 2)
            {
                j = width;
            }
        }
    }
    return;
}

// Detect edges
/*
In artificial intelligence algorithms for image processing, it is often useful to detect
edges in an image: lines in the image that create a boundary between one object and
another. One way to achieve this effect is by applying the Sobel operator to the image.

Like image blurring, edge detection also works by taking each pixel, and modifying it
based on the 3x3 grid of pixels that surrounds that pixel. But instead of just taking
the average of the nine pixels, the Sobel operator computes the new value of each pixel
by taking a weighted sum of the values for the surrounding pixels. And since edges
between objects could take place in both a vertical and a horizontal direction, you’ll
actually compute two weighted sums: one for detecting edges in the x direction, and one
for detecting edges in the y direction. In particular, you’ll use the following two
“kernels”:
sobel_kernel_gx();
sobel_kernel_gy();

Sobel kernels

How to interpret these kernels? In short, for each of the three color values for each
pixel, we’ll compute two values Gx and Gy. To compute Gx for the red channel value of a
pixel, for instance, we’ll take the original red values for the nine pixels that form a
3x3 box around the pixel, multiply them each by the corresponding value in the Gx kernel,
and take the sum of the resulting values.

Why these particular values for the kernel? In the Gx direction, for instance, we’re multiplying the pixels to the right of the
target pixel by a positive number, and multiplying the pixels to the left of the target pixel by a negative number. When we take the
sum, if the pixels on the right are a similar color to the pixels on the left, the result will be close to 0 (the numbers cancel
out). But if the pixels on the right are very different from the pixels on the left, then the resulting value will be very positive
or very negative, indicating a change in color that likely is the result of a boundary between objects. And a similar argument holds
true for calculating edges in the y direction.

Using these kernels, we can generate a Gx and Gy value for each of the red, green, and blue channels for a pixel. But each channel
can only take on one value, not two: so we need some way to combine Gx and Gy into a single value. The Sobel filter algorithm
combines Gx and Gy into a final value by calculating the square root of Gx^2 + Gy^2. And since channel values can only take on
integer values from 0 to 255, be sure the resulting value is rounded to the nearest integer and capped at 255!

And what about handling pixels at the edge, or in the corner of the image? There are many ways to handle pixels at the edge, but for
the purposes of this problem, we’ll ask you to treat the image as if there was a 1 pixel solid black border around the edge of the
image: therefore, trying to access a pixel past the edge of the image should be treated as a solid black pixel (values of 0 for each
of red, green, and blue). This will effectively ignore those pixels from our calculations of Gx and Gy.
*/
void edges(int height, int width, RGBTRIPLE image[height][width])
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
    /*
    In short, for each of the three color values for each
    pixel, we’ll compute two values Gx and Gy. To compute Gx for the red channel value of a
    pixel, for instance, we’ll take the original red values for the nine pixels that form a
    3x3 box around the pixel, multiply them each by the corresponding value in the Gx kernel,
    and take the sum of the resulting values.
    */
    // For each row.
    for (int i = 0; i < height; i++)
    {
        // For each pixel in the ith row.
        for (int j = 0; j < width; j++)
        {
            int gx_red = 0, gx_blue = 0, gx_green = 0;
            int gy_red = 0, gy_blue = 0, gy_green = 0;
            int above = i - 1, below = i + 1;
            int left = j - 1, right = j + 1;
            int top_avg, side_avg, low_avg; // maybe not needed.
            int count = 0;
            // Compute Gx (and Gy?)
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    // If the 3x3 kernel is outside the indexes of the image[i][j],
                    // then add zero (or do nothing) to gx/gy.
                    // First evaluate the case of indexes beyond the left and top sides.
                    if (k < 0 || l < 0)
                    {
                        // add zero
                        // printf(" k: %i l: %i width: %i\n", k, l, width);
                        // printf("Added nothing, left and top\n");
                        // hu();
                    }
                    // Next, evaluate the case of indexes beyond the right and bottom sides.
                    else if (k >= height || l >= width)
                    {
                        // add zero
                        // printf(" k: %i l: %i\n", k, l);
                        // printf("Added nothing, right and bottom\n");
                        // hu();
                    }
                    else
                    // else add self
                    {
                        // add gx and add gy
                        // add gx
                        gx_red += sobel_kernel_gx(k - i, l - j) * copy_of_image[k][l].rgbtRed;
                        gx_blue += sobel_kernel_gx(k - i, l - j) * copy_of_image[k][l].rgbtBlue;
                        gx_green += sobel_kernel_gx(k - i, l - j) * copy_of_image[k][l].rgbtGreen;

                        // add gy
                        gy_red += sobel_kernel_gy(k - i, l - j) * copy_of_image[k][l].rgbtRed;
                        gy_blue += sobel_kernel_gy(k - i, l - j) * copy_of_image[k][l].rgbtBlue;
                        gy_green += sobel_kernel_gy(k - i, l - j) * copy_of_image[k][l].rgbtGreen;
                        // printf(" k: %i l: %i\n", k, l);
                        // printf("Added gx and gy\n");
                        // hu();
                    }
                }
            }
            // square each value
            int gxrs = pow(gx_red, 2);
            int gxbs = pow(gx_blue, 2);
            int gxgs = pow(gx_green, 2);

            int gyrs = pow(gy_red, 2);
            int gybs = pow(gy_blue, 2);
            int gygs = pow(gy_green, 2);

            int gr = round(sqrt(gxrs + gyrs));
            int gg = round(sqrt(gxgs + gygs));
            int gb = round(sqrt(gxbs + gybs));

            // if( square gx_red and gy_red, then take sqrt > 255, set to 255 else take val
            if (gr > 255)
            {
                gr = 255;
            }
            if (gb > 255)
            {
                gb = 255;
            }
            if (gg > 255)
            {
                gg = 255;
            }
            // and assign to image at i j
            image[i][j].rgbtRed = gr;
            image[i][j].rgbtGreen = gg;
            image[i][j].rgbtBlue = gb;
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
check50 cs50/problems/2023/x/filter/more
Execute the below to evaluate the style of your code using style50.

style50 helpers.c
How to Submit
In your terminal, execute the below to submit your work.

submit50 cs50/problems/2023/x/filter/more
*/
int sobel_kernel_gx(int eval_pixel_row, int eval_pixel_column)
{
    int k = eval_pixel_row;
    int l = eval_pixel_column;
    int g = 1;
    if (k == -1 && l == -1)
    {
        g = -1;
    }
    else if (k == -1 && l == 0)
    {
        g = 0;
    }
    else if (k == -1 && l == 1)
    {
        g = 1;
    }
    else if (k == 0 && l == -1)
    {
        g = -2;
    }
    else if (k == 0 && l == 0)
    {
        g = 0;
    }
    else if (k == 0 && l == 1)
    {
        g = 2;
    }
    else if (k == 1 && l == -1)
    {
        g = -1;
    }
    else if (k == 1 && l == 0)
    {
        g = 0;
    }

    return g;
}
int sobel_kernel_gy(int eval_pixel_row, int eval_pixel_column)
{
    int k = eval_pixel_row;
    int l = eval_pixel_column;
    int g = 1;
    if (k == -1 && l == -1)
    {
        g = -1;
    }
    else if (k == -1 && l == 0)
    {
        g = -2;
    }
    else if (k == -1 && l == 1)
    {
        g = -1;
    }
    else if (k == 0 && l == -1)
    {
        g = 0;
    }
    else if (k == 0 && l == 0)
    {
        g = 0;
    }
    else if (k == 0 && l == 1)
    {
        g = 0;
    }
    else if (k == 1 && l == -1)
    {
        g = 1;
    }
    else if (k == 1 && l == 0)
    {
        g = 2;
    }
    return g;
}
void hu(void)
{
    char i;
    scanf("%c", &i);
    return;
}
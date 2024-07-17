#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtBlue == 00 && image[i][j].rgbtGreen == 00 && image[i][j].rgbtRed == 00)
            {
                image[i][j].rgbtBlue = 125;
                image[i][j].rgbtGreen = 250;
                image[i][j].rgbtRed = 60;
            }
        }
    }
    return;
}
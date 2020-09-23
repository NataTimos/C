#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int mid = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = mid;
            image[i][j].rgbtGreen = mid;
            image[i][j].rgbtBlue = mid;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepRed = round((float)image[i][j].rgbtRed * 0.393 + (float)image[i][j].rgbtGreen * 0.769 +
                               (float)image[i][j].rgbtBlue * 0.189);
            int sepGreen = round((float)image[i][j].rgbtRed * 0.349 + (float)image[i][j].rgbtGreen * 0.686 +
                                 (float)image[i][j].rgbtBlue * 0.168);
            int sepBlue = round((float)image[i][j].rgbtRed * 0.272 + (float)image[i][j].rgbtGreen * 0.534 +
                                (float)image[i][j].rgbtBlue * 0.131);

            image[i][j].rgbtRed = (sepRed > 255) ? 255 : sepRed;
            image[i][j].rgbtGreen = (sepGreen > 255) ? 255 : sepGreen;
            image[i][j].rgbtBlue = (sepBlue > 255) ? 255 : sepBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, n = floor(width / 2); j < n; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int numPixels = 0;
            int redValue = 0, blueValue = 0, greenValue = 0;

            for (int n = -1; n <= 1; n++)
            {
                for (int m = -1; m <= 1; m++)
                {
                    if (i + n >= 0 && i + n <= height - 1 && j + m >= 0 && j + m <= width - 1)
                    {
                        numPixels++;
                        redValue += image[i + n][j + m].rgbtRed;
                        blueValue += image[i + n][j + m].rgbtBlue;
                        greenValue += image[i + n][j + m].rgbtGreen;
                    }
                }
            }

            temp[i][j].rgbtRed = (int) round((float) redValue / numPixels);
            temp[i][j].rgbtGreen = (int) round((float) greenValue / numPixels);
            temp[i][j].rgbtBlue = (int) round((float) blueValue / numPixels);
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }

    return;
}

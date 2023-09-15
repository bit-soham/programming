#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);// put 3.0 for precise calculations
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray; // for gray color
            image[i][j].rgbtRed = gray;
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
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)// swap  only till till the middle
        {
            RGBTRIPLE k;
            k = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = k;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];// create a copy as the pixels will be changed below in each loop and may be used in the next loops
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float AvgR = 0;// must be float for precise calculations
            float AvgG = 0;
            float AvgB = 0;
            float k = 0;

            for (int x = i - 1; x <= i + 1; x++)//oscilating loop in a loop
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if ((x >= 0) && (y >= 0) && (x < height) && (y < width))// must
                    {
                        AvgR += copy[x][y].rgbtRed;
                        AvgG += copy[x][y].rgbtGreen;
                        AvgB += copy[x][y].rgbtBlue;
                        k++;
                    }
                }
            }
            image[i][j].rgbtRed = round(AvgR / k);
            image[i][j].rgbtGreen = round(AvgG / k);//always round off
            image[i][j].rgbtBlue = round(AvgB / k);
        }
    }
    return;
}

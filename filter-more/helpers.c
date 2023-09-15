#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) /
                             3.0); // put 3.0 for precise calculations
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray; // for gray color
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // swap  only till till the middle
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
    RGBTRIPLE copy[height][width]; // create a copy as the pixels will be changed below in each loop and may be used in the next loops
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
            float AvgR = 0; // must be float for precise calculations
            float AvgG = 0;
            float AvgB = 0;
            float k = 0;

            for (int x = i - 1; x <= i + 1; x++) // oscilating loop in a loop
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if ((x >= 0) && (y >= 0) && (x < height) && (y < width)) // must
                    {
                        AvgR += copy[x][y].rgbtRed;
                        AvgG += copy[x][y].rgbtGreen;
                        AvgB += copy[x][y].rgbtBlue;
                        k++;
                    }
                }
            }
            image[i][j].rgbtRed = round(AvgR / k);
            image[i][j].rgbtGreen = round(AvgG / k); // always round off
            image[i][j].rgbtBlue = round(AvgB / k);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; // create a copy as the pixels will be changed below in each loop and may be used in the next loops
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    int Mx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int My[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxRed = 0;
            int GxBlue = 0;
            int GxGreen = 0;
            int GyRed = 0;
            int GyBlue = 0;
            int GyGreen = 0;

            for (int x = i - 1, r = 0; x < i + 2 && r < 3; x++, r++)
            {
                for (int y = j - 1, c = 0; y < j + 2 && c < 3; y++, c++)
                {
                    if (x > -1 && x < height && y > -1 && y < width)
                    {
                        GxRed += copy[x][y].rgbtRed * Mx[r][c];
                        GxBlue += copy[x][y].rgbtBlue * Mx[r][c];
                        GxGreen += copy[x][y].rgbtGreen * Mx[r][c];
                        GyRed += copy[x][y].rgbtRed * My[r][c];
                        GyBlue += copy[x][y].rgbtBlue * My[r][c];
                        GyGreen += copy[x][y].rgbtGreen * My[r][c];
                    }
                }
            }
            int Red = round((float) sqrt((GxRed * GxRed) + (GyRed * GyRed)));
            int Blue = round((float) sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue)));
            int Green = round((float) sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen)));
            if (Red > 255)
            {
                Red = 255;
            }
            if (Green > 255)
            {
                Green = 255;
            }
            if (Blue > 255)
            {
                Blue = 255;
            }
            image[i][j].rgbtRed = Red;
            image[i][j].rgbtBlue = Blue;
            image[i][j].rgbtGreen = Green;
        }
    }
    return;
}

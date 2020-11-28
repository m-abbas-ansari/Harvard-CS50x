#include "helpers.h"
#include<stdio.h>
#include<math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int k;
    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            k = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3);
            image[i][j].rgbtBlue = k;
            image[i][j].rgbtGreen = k;
            image[i][j].rgbtRed = k;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int s[3];
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            s[0] = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue)); //sepia red
            s[1] = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue)); //sepia green
            s[2] = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue)); //sepia blue
            for (int k = 0; k < 3; k++)
            {
                if (s[k] > 255) //check for if colour value exceeds 255
                {
                    s[k] = 255;
                }
            }
            image[i][j].rgbtRed = s[0];
            image[i][j].rgbtGreen = s[1];
            image[i][j].rgbtBlue = s[2];
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid;
    if(width % 2 == 0)
    {
        mid = width/2;
    }
    else
    {
        mid = (width + 1)/2;
    }

    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j < mid; j++)
        {
            //swapping rgb values of pixels symmetrically in each row
            int tr, tg, tb;

            tr = image[i][j].rgbtRed;
            tg = image[i][j].rgbtGreen;
            tb = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - (j+1)].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - (j+1)].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - (j+1)].rgbtBlue;

            image[i][width - (j+1)].rgbtRed = tr;
            image[i][width - (j+1)].rgbtGreen = tg;
            image[i][width - (j+1)].rgbtBlue = tb;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int count, sumr, sumg, sumb;
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            count = 1;
            sumr = image[i][j].rgbtRed;
            sumg = image[i][j].rgbtGreen;
            sumb = image[i][j].rgbtBlue;
            //top left of centre
            if(((i - 1) >= 0) && ((j - 1) >= 0))
            {
                sumr = sumr + image[i-1][j-1].rgbtRed;
                sumg = sumg + image[i-1][j-1].rgbtGreen;
                sumb = sumb + image[i-1][j-1].rgbtBlue;
                count++;
            }
            //top of centre
            if(((i - 1) >= 0) && ((j >= 0)))
            {
                sumr = sumr + image[i-1][j].rgbtRed;
                sumg = sumg + image[i-1][j].rgbtGreen;
                sumb = sumb + image[i-1][j].rgbtBlue;
                count++;
            }
            //top right of centre
            if(((i - 1) >= 0) && ((j + 1) < width))
            {
                sumr = sumr + image[i-1][j+1].rgbtRed;
                sumg = sumg + image[i-1][j+1].rgbtGreen;
                sumb = sumb + image[i-1][j+1].rgbtBlue;
                count++;
            }
            //left of centre
            if(((i >= 0) && ((j - 1) >= 0)))
            {
                sumr = sumr + image[i][j-1].rgbtRed;
                sumg = sumg + image[i][j-1].rgbtGreen;
                sumb = sumb + image[i][j-1].rgbtBlue;
                count++;
            }
            //right of centre
            if(((i >= 0) && ((j + 1) < width)))
            {
                sumr = sumr + image[i][j+1].rgbtRed;
                sumg = sumg + image[i][j+1].rgbtGreen;
                sumb = sumb + image[i][j+1].rgbtBlue;
                count++;
            }
            //bottom left of centre
            if(((i + 1) < height) && ((j - 1) >= 0))
            {
                sumr = sumr + image[i+1][j-1].rgbtRed;
                sumg = sumg + image[i+1][j-1].rgbtGreen;
                sumb = sumb + image[i+1][j-1].rgbtBlue;
                count++;
            }
            //bottom of centre
            if(((i + 1) < height) && ((j >= 0)))
            {
                sumr = sumr + image[i+1][j].rgbtRed;
                sumg = sumg + image[i+1][j].rgbtGreen;
                sumb = sumb + image[i+1][j].rgbtBlue;
                count++;
            }
            //bottom right of centre
            if(((i + 1) < height) && ((j + 1) < width))
            {
                sumr = sumr + image[i+1][j+1].rgbtRed;
                sumg = sumg + image[i+1][j+1].rgbtGreen;
                sumb = sumb + image[i+1][j+1].rgbtBlue;
                count++;
            }

            image[i][j].rgbtRed = round(sumr/count);
            image[i][j].rgbtGreen = round(sumg/count);
            image[i][j].rgbtBlue = round(sumb/count);
        }
    }
}

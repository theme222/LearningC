#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int invert(int val)
{
    return abs(val-1);
}

int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    // Set required return values
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    // Set required return values

    for (int rowIndex = 0; rowIndex < imageSize; rowIndex++)
    {
        int *row = image[rowIndex];
        int *left = row;
        int *right = row+imageSize-1;
        while (left < right)
        {
            int tempVal = invert(*left);
            *left = invert(*right);
            *right = tempVal;
            left++;
            right--;
        }
        if (imageSize % 2 == 1)
            row[(imageSize-1) / 2 ] = invert(row[(imageSize-1) / 2]);

    }
    return image;
}

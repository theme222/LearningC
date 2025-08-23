#include <iostream>

typedef struct Square {
    int BLX;
    int BLY;
    int TRX;
    int TRY;
} Square; // Technically this is a rectangle but I already coded it to be called square so stfu

Square squares[1000];

int RangeOverlapCount(int start1, int end1, int start2, int end2)
{
    if (start1 <= start2 && end1 >= end2)
        return end2 - start2;
    else if (start2 <= start1 && end2 >= end1)
        return end1 - start1;
    else if (start1 < start2)
        return end1 - start2 > 0 ? end1 - start2 : 0;
    else
        return end2 - start1 > 0 ? end2 - start1 : 0;
}


int SquareOverlapCount(Square a, Square b)
{
    int xOverlap = RangeOverlapCount(a.BLX, a.TRX, b.BLX, b.TRX);
    int yOverlap = RangeOverlapCount(a.BLY, a.TRY, b.BLY, b.TRY);
    return xOverlap * yOverlap;
}

int main()
{
    int squareCount;
    std::cin >> squareCount;

    for (int i = 0; i < squareCount; i++)
    {
        int BLX, BLY, TRX, TRY;
        std::cin >> BLX >> BLY >> TRX >> TRY;

        Square sq;
        sq.BLX = BLX;
        sq.BLY = BLY;
        sq.TRX = TRX;
        sq.TRY = TRY;
        squares[i] = sq;
    }

    int maxArea = -1;
    for (int i = 0; i < squareCount; i++)
    {
        for (int j = i+1; j < squareCount; j++)
        {
            int overlap = SquareOverlapCount(squares[i], squares[j]);
            maxArea = std::max(overlap, maxArea);
        }
    }

    if (maxArea > 0)
        std::cout << "Max overlapping area = " << maxArea << '\n';
    else
    {
        std::cout << "No overlaps\n";
        return 0;
    }

    for (int i = 0; i < squareCount; i++)
    {
        for (int j = i+1; j < squareCount; j++)
        {
            int overlap = SquareOverlapCount(squares[i], squares[j]);
            if (overlap == maxArea)
                std::cout << "rectangles " << i << " and " << j << '\n';
        }
    }
}

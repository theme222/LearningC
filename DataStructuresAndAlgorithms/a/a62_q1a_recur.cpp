#include <iostream>
#include <cassert>
#include <cmath>

class matrix {
public:
    int singleVal;
    bool isBig;
    matrix* mat1;
    matrix* mat2;
    matrix* mat3;
    matrix* mat4;
    
    matrix(): isBig(true), singleVal(0), mat1(nullptr), mat2(nullptr), mat3(nullptr), mat4(nullptr) {}
    
    static matrix* construct(int a, int b) {
        matrix* mat = new matrix();
        
        if (a == 0) 
        {
            mat->singleVal = b;
            mat->isBig = false;
        } 
        else 
        {
            mat->mat1 = construct(a-1, b);
            mat->mat2 = construct(a-1, b-1);
            mat->mat3 = construct(a-1, b+1);
            mat->mat4 = construct(a-1, b);
        }
        return mat;
    }
};

typedef std::pair<int, int> coords; // x, y
int outputArr[1000][1000];

void traverse(matrix* mat, coords topLeft, coords bottomRight) // provide bounding box
{
    int length = bottomRight.first - topLeft.first;
    int height = bottomRight.second - topLeft.second; // I think length and height are the same
    
    coords tl = topLeft, br = bottomRight;
    if (mat->isBig)
    {
        // mat1
        tl = topLeft;
        br = {topLeft.first + (length/2), topLeft.second + (height/2)};
        traverse(mat->mat1, tl, br);
        
        // mat2
        tl = {topLeft.first + (length/2) + 1, topLeft.second};
        br = {bottomRight.first, topLeft.second + (height/2)};
        traverse(mat->mat2, tl, br);
        
        // mat3
        tl = {topLeft.first, topLeft.second + (height/2) + 1};
        br = {topLeft.first + (length/2), bottomRight.second};
        traverse(mat->mat3, tl, br);
        
        // mat4
        tl = {topLeft.first + (length/2) + 1, topLeft.second + (height/2) + 1};
        br = bottomRight;
        traverse(mat->mat4, tl, br);
    }
    else 
    {
        assert(tl == br && "Top left Not equal bottom right");
        outputArr[tl.second][tl.first] = mat->singleVal;
    }
}

int main()
{
    int a,b;
    std::cin >> a >> b;
    matrix* mat = matrix::construct(a,b);
    
    int size = pow(2, a);
    traverse(mat, {0,0}, {size-1, size-1});
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j != 0) std::cout << ' ';
            std::cout << outputArr[i][j];
        }
        std::cout << '\n';
    }
}
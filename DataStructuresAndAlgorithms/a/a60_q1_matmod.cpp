#include <bits/stdc++.h>

typedef long long ll;

ll n, k;

class matrix {
public:
    ll val1;
    ll val2;
    ll val3;
    ll val4;
    matrix(ll a, ll b, ll c, ll d): val1(a), val2(b), val3(c), val4(d) {}
    
    matrix operator*(matrix otherMat)
    {
        matrix a = matrix(
            this->val1 * otherMat.val1 + this->val3 * otherMat.val2,
            this->val1 * otherMat.val2 + this->val2 * otherMat.val4,
            this->val1 * otherMat.val3 + this->val3 * otherMat.val4,
            this->val2 * otherMat.val3 + this->val4 * otherMat.val4
        );
        return a;
    }
    
    matrix operator%(ll a)
    {
        matrix copy = *this;
        copy.val1 %= a;
        copy.val2 %= a;
        copy.val3 %= a;
        copy.val4 %= a;
        return copy;
    }
    
};

matrix rec(matrix currMat, matrix base, ll currPow)
{
    // std::cout << currPow << " adlkjfsljds \n";
    if (currPow == 1) return base;
    
    matrix mat2 = rec(currMat, base, currPow / 2);
    mat2 = mat2 * mat2;
    mat2 = mat2 % k;
    
    if (currPow % 2 == 1)
    {
        mat2 = mat2 * base;
        mat2 = mat2 % k;
    }
    
    return mat2;
}

int main()
{
    std::cin >> n >> k;
    
    ll a,b,c,d;
    std::cin >> a >> b >> c >> d;
    
    matrix base(a,b,c,d);
    matrix currMat(a,b,c,d);
    
    currMat = rec(currMat, base, n);
    
    std::cout << currMat.val1 << ' ';
    std::cout << currMat.val2 << ' ';
    std::cout << currMat.val3 << ' ';
    std::cout << currMat.val4 << '\n';
}
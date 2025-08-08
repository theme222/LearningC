#include <iostream>

int main()
{
    using std::swap;
    int a,b,c,d,e;
    std::cin >> a >> b >> c >> d >> e;
    if (a > b) swap(a,b);
    if (c > d) swap(c,d);
    if (a > c)
    {
        swap(b,d);
        c = a;
    }
    a = e;
    if (a > b) swap(a,b);
    if (c > a)
    {
        swap(b,d);
        a = c;
    }
    printf("%d\n", a > d? d: a);
}

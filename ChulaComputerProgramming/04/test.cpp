#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    int n = a;
    while (n--)
        printf("%d ", n);
    puts("");
    n = a;
    while (--n)
        printf("%d ", n);
}

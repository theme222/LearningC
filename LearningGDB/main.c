#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *px = NULL;

void foo()
{
    puts("foo");
}

int main()
{
    char* name = "Sira";
    int stringLength = strlen(name);


    printf("My name is : %s\n", name);

    foo();
    return 0;
}
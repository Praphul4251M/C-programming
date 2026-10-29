// Write a program with a structure representing a complex number

#include <stdio.h>

struct complex
{

    int real;
    int imag;
};

int main()
{

    struct complex c = {2, 8};

    printf("Complex is %d + i%d", c.real, c.imag);

    return 0;
}
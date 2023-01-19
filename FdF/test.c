#include <stdio.h>
#include <math.h>

int main()
{
    float a = 1.5;
    if (a - (int)a > 0.5)
        printf("%f\n", ceil(a));
    else
        printf("%f\n", floor(a));
}
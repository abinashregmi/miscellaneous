#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define f(x)    x*x*x + x + 1

void main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1;
    printf("\nEnter the value of x0: ");
    scanf("%f", &x0);
    printf("\nEnter the value of x1: ");
    scanf("%f", &x1);
    printf("\nEnter the value of error: ");
    scanf("%f", &e);
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do
    {
        f0 = f(x0);
        f1 = f(x1);
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        step = step + 1;
    } while (fabs(f2) > e);
    printf("\nRoot is: %f", x2);
    getch();
}
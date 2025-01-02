#include <stdio.h>
#include <conio.h>

#define P(x) (a[4] * x * x * x * x + a[3] * x * x * x + a[2] * x * x + a[1] * x + a[0])

float a[100], b[100];

int main() {
    float x;
    int n, i;

    printf("Enter the degree of polynomial: \n");
    scanf("%d", &n);

    printf("Enter coefficients of the polynomial:\n");
    for (i = n; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%f", &a[i]);
    }

    printf("Enter the value at which polynomial is to be evaluated: ");
    scanf("%f", &x);

    float result = P(x);
    printf("Value of polynomial P(x) at x = %f is %f\n", x, result);

    getch();
    return 0;
}
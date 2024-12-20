#include<stdio.h>
#include<math.h>

#define f(x) (3*x - cos(x) - 1)
#define g(x) (3 + sin(x))
int main()
{
    float Xo, X1, root, Er, Erc;
    int iteration = 1;
    printf("Enter the initial guess(Xo):");
    scanf("%f", &Xo);
    printf("Enter the allowed error:");
    scanf("%f", &Er);
    printf("\nIteration\tXo\t\tX1\t\tError\n");
    printf("---------------------------------------------------------\n");
    do {
        X1 = Xo - (f(Xo) / g(Xo));
        Erc = fabs(X1 - Xo);
        printf("%d\t\t%.6f\t%.6f\t%.6f\n", iteration, Xo, X1, Erc);
        Xo = X1 ;
        iteration ++;
    }while(Erc > Er);
    root = X1;
    printf("The root of the equation is %.6f and error is %.6f", root, Erc);
    return 0;
}
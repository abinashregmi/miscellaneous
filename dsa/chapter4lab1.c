//Write a program to calculate the factorial of a given number using recursion
#include<stdio.h>

int factorial(int n, int a)

{

if(n==0)

return a;

else

return factorial(n-1,n*a);

}


int main()

{

int n, a = 1;

printf("Enter value of n:");

scanf("%d",&n);

printf("Factorial = %d",factorial(n,a));

return 0;

}
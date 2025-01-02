#include <stdio.h>
#include <conio.h>
#include <math.h>

// Define the original function f(x)
#define f(x) ((x) - sin(x) - 0.5)

// Define the iteration function g(x) for fixed-point iteration
#define g(x) (sin(x) + 0.5)

int main() {
    int step = 1, N;
    float x0, x1, e;

    // Input initial guess, tolerable error, and maximum iterations
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);

    // Print the header for the iteration table
    printf("\nStep \t x0 \t\t x1 \t\t f(x1)\n");

    // Perform fixed-point iteration
    do {
        x1 = g(x0); // Generate the next guess using g(x)
        printf("%d \t %f \t %f \t %f\n", step, x0, x1, f(x1)); // Print the current step, x0, x1, and f(x1)
        x0 = x1; // Update x0 to the new guess
        step++; // Increment the step counter

        // Check if the number of iterations exceeds the maximum allowed
        if (step > N) {
            printf("Not Convergent.\n");
            break;
        }
    } while (fabs(f(x1)) > e); // Continue until the function value is within the tolerable error

    // If the function value is within the tolerable error, print the root
    if (fabs(f(x1)) <= e) {
        printf("\nRoot is: %f\n", x1);
    }

    getch();
    return 0;
}
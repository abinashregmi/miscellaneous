#include <stdio.h>
#include <math.h>

float a3, a2, a1, a0;

// Function to evaluate the polynomial f(x)
float f(float x) {
    return (a3 * x * x * x + a2 * x * x + a1 * x + a0);
}

int main() {
    float xn, xp, xr, fxn, fxp, fxr, E0, Ea;

    // Input coefficients of the polynomial
    printf("Enter the coefficients (a3, a2, a1, a0): \n");
    scanf("%f %f %f %f", &a3, &a2, &a1, &a0);

    // Input initial guesses
    printf("Enter two initial guesses: \n");
    scanf("%f %f", &xn, &xp);

    // Evaluate function values at the initial guesses
    fxn = f(xn);
    fxp = f(xp);

    // Debugging: Print f(xn) and f(xp)
    printf("f(xn) = %f, f(xp) = %f\n", fxn, fxp);

    // Input the allowed error
    printf("Enter the allowed error: \n");
    scanf("%f", &Ea);

    // Check if the guesses bracket a root
    if (fxn * fxp < 0) {
        do {
            // Calculate the midpoint
            xr = (xn + xp) / 2.0;
            fxr = f(xr);

            // Debugging: Print current values
            printf("xn = %f, xp = %f, xr = %f, f(xr) = %f\n", xn, xp, xr, fxr);

            // Update bounds based on the midpoint value
            if (fxn * fxr < 0) {
                xp = xr;
                fxp = fxr;
            } else {
                xn = xr;
                fxn = fxr;
            }

            // Compute the error
            E0 = fabs(xp - xn);
        } while (E0 > Ea); // Repeat until the error is within the allowed limit

        printf("The root is approximately: %f\n", xr);
    } else {
        printf("Invalid initial guesses. f(xn) and f(xp) must have opposite signs.\n");
    }

    return 0;
}
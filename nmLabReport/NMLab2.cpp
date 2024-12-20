#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * x * x - 6 * x - 4;
}

double f_prime(double x) {
    return 3 * x * x - 6;
}

int main() {
    double x0, x1, tolerance, relative_error;
    int iteration = 0, max_iterations;

    cout << "Enter initial guess (x0): ";
    cin >> x0;
    cout << "Enter error tolerance: ";
    cin >> tolerance;

    cout << "Enter maximum number of iterations: ";
    cin >> max_iterations;

    cout << fixed << setprecision(6);

    cout << "Iteration          Xn                 f(Xn)                f'(Xn)            Xn+1\n";

    do {
        iteration++;
        double f_val = f(x0);
        double f_prime_val = f_prime(x0);

        if (f_prime_val == 0) {
            cout << "Error: Derivative is zero. Cannot proceed.\n";
            return -1;
        }

        x1 = x0 - f_val / f_prime_val;
        relative_error = fabs(x1 - x0);


        cout << setw(5) << iteration 
             << setw(18) << x0 
             << setw(20) << f_val 
             << setw(20) << f_prime_val 
             << setw(18) << x1 << endl;

        if (relative_error < tolerance) {
            cout << "\nThe root of the equation is: " << x1 << " after " << iteration << " iterations.\n";
            return 0;
        }

        x0 = x1;

    } while (iteration < max_iterations);

    cout << "\nSolution did not converge within " << max_iterations << " iterations.\n";
    return 0;
}
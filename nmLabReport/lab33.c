#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define TOL 1e-6

double f(double x, double y, double yp) {
    // Example: y'' = -y (simple harmonic oscillator)
    return -y;
}

double rk4(double x0, double y0, double yp0, double h, double x) {
    double k1, k2, k3, k4, l1, l2, l3, l4;
    double y = y0;
    double yp = yp0;
    
    while (x0 < x) {
        k1 = h * yp;
        l1 = h * f(x0, y, yp);
        
        k2 = h * (yp + 0.5 * l1);
        l2 = h * f(x0 + 0.5 * h, y + 0.5 * k1, yp + 0.5 * l1);
        
        k3 = h * (yp + 0.5 * l2);
        l3 = h * f(x0 + 0.5 * h, y + 0.5 * k2, yp + 0.5 * l2);
        
        k4 = h * (yp + l3);
        l4 = h * f(x0 + h, y + k3, yp + l3);
        
        y += (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        yp += (l1 + 2*l2 + 2*l3 + l4) / 6.0;
        
        x0 += h;
    }
    
    return y;
}

void shooting_method(double a, double b, double alpha, double beta, double h) {
    double t1 = 0.0, t2 = 1.0; // Initial guesses for y'(a)
    double y1, y2, t;
    int iter = 0;
    
    while (iter < MAX_ITER) {
        y1 = rk4(a, alpha, t1, h, b);
        y2 = rk4(a, alpha, t2, h, b);
        
        if (fabs(y1 - beta) < TOL) {
            printf("Solution found: y'(a) = %f\n", t1);
            return;
        }
        
        if (fabs(y2 - beta) < TOL) {
            printf("Solution found: y'(a) = %f\n", t2);
            return;
        }
        
        t = t2 - (y2 - beta) * (t2 - t1) / (y2 - y1);
        
        t1 = t2;
        t2 = t;
        
        iter++;
    }
    
    printf("Solution not found within %d iterations\n", MAX_ITER);
}

int main() {
    double a = 0.0, b = 1.0;
    double alpha = 0.0, beta = 1.0;
    double h = 0.01;
    
    shooting_method(a, b, alpha, beta, h);
    
    return 0;
}
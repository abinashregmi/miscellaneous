#include <graphics.h>
#include <stdio.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 10, label);
}

// Function to scale a point (x, y) by scaling factors Sx, Sy
void scalePoint(int *x, int *y, float Sx, float Sy) {
    // Apply the scaling formula
    int newX = (*x) * Sx;
    int newY = (*y) * Sy;
    
    // Update the original point with the new scaled coordinates
    *x = newX;
    *y = newY;
}

int main() {
    int gd = DETECT, gm;
    
    // Original triangle coordinates
    int x1 = 200, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 250, y3 = 200;
    
    // Scaling factors
    float Sx, Sy;

    // Get the scaling factors from the user
    printf("Enter scaling factors (Sx Sy): ");
    scanf("%f %f", &Sx, &Sy);

    // Initialize graphics mode
    initgraph(&gd, &gm, " ");

    cleardevice();

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Original");

    // Scale the points of the triangle
    scalePoint(&x1, &y1, Sx, Sy);
    scalePoint(&x2, &y2, Sx, Sy);
    scalePoint(&x3, &y3, Sx, Sy);

    // Draw the scaled triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, RED, "Scaled");

    getch(); // Wait for user input
    closegraph(); // Close graphics mode

    return 0;
}
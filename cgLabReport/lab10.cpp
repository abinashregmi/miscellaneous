#include <graphics.h>
#include <stdio.h>
#include <math.h> // For cos(), sin(), and M_PI

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 10, label);
}

// Function to rotate a point (x, y) by angle theta around the origin
void rotatePoint(int *x, int *y, float theta) {
    // Convert angle to radians
    float rad = theta * (M_PI / 180.0);
    
    // Apply the rotation formula
    int newX = (*x) * cos(rad) - (*y) * sin(rad);
    int newY = (*x) * sin(rad) + (*y) * cos(rad);
    
    // Update the original point with the new rotated coordinates
    *x = newX;
    *y = newY;
}

int main() {
    int gd = DETECT, gm;
    
    // Original triangle coordinates
    int x1 = 200, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 250, y3 = 200;
    
    // Angle of rotation
    float theta;

    // Get the angle of rotation from the user
    printf("Enter the angle of rotation (in degrees): ");
    scanf("%f", &theta);

    // Initialize graphics mode
    initgraph(&gd, &gm, " ");

    cleardevice();

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Original");

    // Rotate the points of the triangle
    rotatePoint(&x1, &y1, theta);
    rotatePoint(&x2, &y2, theta);
    rotatePoint(&x3, &y3, theta);

    // Draw the rotated triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, RED, "Rotated");

    getch(); // Wait for user input
    closegraph(); // Close graphics mode

    return 0;
}
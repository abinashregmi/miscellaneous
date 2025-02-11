#include <graphics.h>
#include <stdio.h>

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2, int color, const char* label) {
    setcolor(color);
    rectangle(x1, y1, x2, y2);
    outtextxy((x1 + x2) / 2, y1 - 10, (char*)label);
}

// Function to apply shear transformation along the y-axis
void shearY(int *x, int *y, float shy) {
    *y = *y + shy * (*x);
}

int main() {
    int gd = DETECT, gm;
    float shy;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Original rectangle coordinates
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 200;

    // Get the shear factor from the user
    printf("Enter the shear factor shy along y-axis: ");
    scanf("%f", &shy);

    cleardevice();

    // Draw the original rectangle
    drawRectangle(x1, y1, x2, y2, WHITE, "Original");

    // Apply shear transformation along the y-axis
    int x1_sheared = x1, y1_sheared = y1;
    int x2_sheared = x2, y2_sheared = y2;
    shearY(&x1_sheared, &y1_sheared, shy);
    shearY(&x2_sheared, &y2_sheared, shy);

    // Draw the sheared rectangle
    drawRectangle(x1_sheared, y1_sheared, x2_sheared, y2_sheared, RED, "Sheared");

    getch(); // Wait for user input
    closegraph(); // Close graphics mode

    return 0;
}
#include <graphics.h>
#include <stdio.h>

// Function to draw a 3D bar and label it
void draw3DBar(int a1, int b1, int a2, int b2, int depth, const char* label) {
    // Draw the 3D bar
    bar3d(a1, b1, a2, b2, depth, 1);

    // Label the 3D bar
    outtextxy(a1 + 50, b1 - 15, label);
}

int main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Coordinates and depth for the 3D bar
    int a1 = 100, b1 = 100;
    int a2 = 200, b2 = 200;
    int depth = 50;

    // Draw the 3D bar and label it
    draw3DBar(a1, b1, a2, b2, depth, "3D Bar");

    getch(); // Wait for user input
    closegraph(); // Close graphics mode

    return 0;
}
#include <graphics.h>
#include <stdio.h>

// Function to draw a supercar
void drawSupercar(int x, int y) {
    // Draw the body of the car
    rectangle(x, y, x + 200, y + 50); // Main body
    rectangle(x + 50, y - 30, x + 150, y); // Roof
    line(x + 50, y - 30, x + 30, y); // Front slope
    line(x + 150, y - 30, x + 170, y); // Rear slope

    // Draw the wheels of the car
    circle(x + 50, y + 50, 20); // Front wheel
    circle(x + 150, y + 50, 20); // Rear wheel

    // Draw the windows of the car
    rectangle(x + 60, y - 20, x + 90, y); // Front window
    rectangle(x + 110, y - 20, x + 140, y); // Rear window

    // Draw the spoiler
    line(x + 150, y - 30, x + 180, y - 40); // Spoiler top
    line(x + 180, y - 40, x + 180, y); // Spoiler support

    // Draw the headlights
    circle(x + 20, y + 10, 5); // Left headlight
    circle(x + 180, y + 10, 5); // Right headlight

    // Draw the rear lights
    rectangle(x + 10, y + 40, x + 30, y + 45); // Left rear light
    rectangle(x + 170, y + 40, x + 190, y + 45); // Right rear light
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Coordinates for the car
    int x = 100, y = 200;

    // Draw the supercar
    drawSupercar(x, y);

    getch();
    closegraph();
    return 0;
}
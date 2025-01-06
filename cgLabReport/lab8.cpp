#include <graphics.h>
#include <stdio.h>

// Function to draw a car
void drawCar(int x, int y) {
    // Draw the body of the car
    rectangle(x, y, x + 200, y + 50);
    rectangle(x + 50, y - 30, x + 150, y);

    // Draw the wheels of the car
    circle(x + 50, y + 50, 20);
    circle(x + 150, y + 50, 20);

    // Draw the windows of the car
    rectangle(x + 60, y - 20, x + 90, y);
    rectangle(x + 110, y - 20, x + 140, y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Coordinates for the car
    int x = 100, y = 200;

    // Draw the car
    drawCar(x, y);

    getch();
    closegraph();
    return 0;
}
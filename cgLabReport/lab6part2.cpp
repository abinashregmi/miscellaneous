#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle using the line() function
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// 8-connected boundary fill algorithm
void boundaryFill8(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill8(x + 1, y, fillColor, boundaryColor);     // right
        boundaryFill8(x - 1, y, fillColor, boundaryColor);     // left
        boundaryFill8(x, y + 1, fillColor, boundaryColor);     // down
        boundaryFill8(x, y - 1, fillColor, boundaryColor);     // up
        boundaryFill8(x + 1, y + 1, fillColor, boundaryColor); // down-right
        boundaryFill8(x - 1, y - 1, fillColor, boundaryColor); // up-left
        boundaryFill8(x + 1, y - 1, fillColor, boundaryColor); // up-right
        boundaryFill8(x - 1, y + 1, fillColor, boundaryColor); // down-left
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Define the vertices of the triangle
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    // Draw the triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Define fill and boundary colors
    int fillColor = RED;
    int boundaryColor = WHITE; // Assuming WHITE is used for the triangle boundary

    // Fill the triangle starting from a seed point inside the triangle
    boundaryFill8((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}
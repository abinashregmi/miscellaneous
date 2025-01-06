#include <stdio.h>
#include <graphics.h>

void floodFill4(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        floodFill4(x + 1, y, fillColor, boundaryColor); // right
        floodFill4(x - 1, y, fillColor, boundaryColor); // left
        floodFill4(x, y + 1, fillColor, boundaryColor); // down
        floodFill4(x, y - 1, fillColor, boundaryColor); // up
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define vertices of the hexagon
    int x1 = 150, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 225, y3 = 150;
    int x4 = 200, y4 = 200;
    int x5 = 150, y5 = 200;
    int x6 = 125, y6 = 150;

    // Draw hexagon
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x5, y5);
    line(x5, y5, x6, y6);
    line(x6, y6, x1, y1);

    // Define fill and boundary colors
    int fillColor = RED;
    int boundaryColor = WHITE;

    // Fill the hexagon starting from a seed point inside the hexagon
    floodFill4((x1 + x2 + x3 + x4 + x5 + x6) / 6, (y1 + y2 + y3 + y4 + y5 + y6) / 6, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}
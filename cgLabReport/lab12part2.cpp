#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

// Original triangle points
int originalPolygon[3][2] = {{100, 100}, {150, 100}, {150, 200}};
int reflectedPolygon[3][2]; // Store reflected triangle

void drawAxes() {
    line(0, 240, 640, 240);  // X-axis
    line(320, 0, 320, 480);  // Y-axis
}

void drawPolygon(int polygon[3][2], int color) {
    setcolor(color);
    for (int i = 0; i < 3; i++) {
        line(polygon[i][0], polygon[i][1], polygon[(i + 1) % 3][0], polygon[(i + 1) % 3][1]);
    }
}

void reflectAcrossX() {
    for (int i = 0; i < 3; i++) {
        reflectedPolygon[i][0] = originalPolygon[i][0]; // X remains the same
        reflectedPolygon[i][1] = 480 - originalPolygon[i][1]; // Reflect Y
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Translate original triangle to center-based coordinates
    for (int i = 0; i < 3; i++) {
        originalPolygon[i][0] += 320;
        originalPolygon[i][1] = 240 - originalPolygon[i][1];
    }

    reflectAcrossX(); // Compute reflected triangle

    cleardevice();
    drawAxes();
    drawPolygon(originalPolygon, WHITE);  // Original Triangle (White)
    drawPolygon(reflectedPolygon, WHITE); // Reflected Triangle (Green)
    
    getch();
    closegraph();
    return 0;
}
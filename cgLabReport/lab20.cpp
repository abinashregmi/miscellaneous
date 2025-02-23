#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Function to project 3D points to 2D using isometric parallel projection
void parallelProjection(int x, int y, int z, int *x_new, int *y_new)
{
    float angle = 45 * M_PI / 180; // 45 degrees in radians
    *x_new = x + z * cos(angle);
    *y_new = y + z * sin(angle);
}

// Function to draw a 3D cube using parallel projection
void draw3dCube(int x, int y, int z, int size)
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int x5, y5, x6, y6, x7, y7, x8, y8;

    // Front face
    parallelProjection(x, y, z, &x1, &y1);
    parallelProjection(x + size, y, z, &x2, &y2);
    parallelProjection(x + size, y + size, z, &x3, &y3);
    parallelProjection(x, y + size, z, &x4, &y4);

    // Back face
    parallelProjection(x, y, z + size, &x5, &y5);
    parallelProjection(x + size, y, z + size, &x6, &y6);
    parallelProjection(x + size, y + size, z + size, &x7, &y7);
    parallelProjection(x, y + size, z + size, &x8, &y8);

    // Draw front face
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    // Draw back face
    line(x5, y5, x6, y6);
    line(x6, y6, x7, y7);
    line(x7, y7, x8, y8);
    line(x8, y8, x5, y5);

    // Connect front and back faces
    line(x1, y1, x5, y5);
    line(x2, y2, x6, y6);
    line(x3, y3, x7, y7);
    line(x4, y4, x8, y8);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw a cube with parallel projection
    draw3dCube(100, 100, 150, 100);

    getch();
    closegraph();
    return 0;
}


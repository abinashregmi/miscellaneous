#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

double x1, z1, x2, z2, mx, my, depth;

void drawSquare(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy);
void rotateSquare();

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    printf("Enter 1st top coordinates (x1, z1): ");
    scanf("%lf%lf", &x1, &z1);

    printf("Enter right bottom coordinates (x2, z2): ");
    scanf("%lf%lf", &x2, &z2);

    depth = (x2 - x1) / 4.0;
    mx = (x1 + x2) / 2.0;
    my = (z1 + z2) / 2.0;

    rotateSquare();

    closegraph();
    return 0;
}

void drawSquare(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
{
    line(ax, ay, bx, by);
    line(bx, by, cx, cy);
    line(cx, cy, dx, dy);
    line(dx, dy, ax, ay);
}

void rotateSquare()
{
    double angle;
    float t;

    printf("Enter the angle to rotate (in degrees): ");
    scanf("%f", &t);

    // Convert angle to radians
    angle = t * (3.1416 / 180.0);

    // Coordinates for the square
    double ax = x1, ay = z1;
    double bx = x2, by = z1;
    double cx = x2, cy = z2;
    double dx = x1, dy = z2;

    // Rotate the points
    double new_ax = mx + (ax - mx) * cos(angle) - (ay - my) * sin(angle);
    double new_ay = my + (ax - mx) * sin(angle) + (ay - my) * cos(angle);

    double new_bx = mx + (bx - mx) * cos(angle) - (by - my) * sin(angle);
    double new_by = my + (bx - mx) * sin(angle) + (by - my) * cos(angle);

    double new_cx = mx + (cx - mx) * cos(angle) - (cy - my) * sin(angle);
    double new_cy = my + (cx - mx) * sin(angle) + (cy - my) * cos(angle);

    double new_dx = mx + (dx - mx) * cos(angle) - (dy - my) * sin(angle);
    double new_dy = my + (dx - mx) * sin(angle) + (dy - my) * cos(angle);

    cleardevice();

    // Draw rotated square
    drawSquare(new_ax, new_ay, new_bx, new_by, new_cx, new_cy, new_dx, new_dy);
    outtextxy(new_ax + 20, new_ay - 20, "Rotated Rectangle");

    // Draw original square
    drawSquare(ax, ay, bx, by, cx, cy, dx, dy);
    outtextxy(ax + 20, ay - 20, "Original Rectangle");

    getch();
}
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void windowToViewport(float xw, float yw, float xw_min, float xw_max, float yw_min, float yw_max,
                      float xv_min, float xv_max, float yv_min, float yv_max, int *xv, int *yv)
{
    *xv = (int)((xw - xw_min) * (xv_max - xv_min) / (xw_max - xw_min) + xv_min);
    *yv = (int)((yw - yw_min) * (yv_max - yv_min) / (yw_max - yw_min) + yv_min);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Define window and viewport coordinates
    float xw_min = 10, xw_max = 100;
    float yw_min = 10, yw_max = 100;
    float xv_min = 200, xv_max = 400;
    float yv_min = 200, yv_max = 400;

    int xv1, yv1, xv2, yv2;

    float xw1 = 20, yw1 = 30;
    float xw2 = 90, yw2 = 80;

    // Draw window
    rectangle(xw_min, yw_min, xw_max, yw_max);
    outtextxy(xw_min + 10, yw_min - 10, "Window");

    // Convert window coordinates to viewport coordinates
    windowToViewport(xw1, yw1, xw_min, xw_max, yw_min, yw_max, xv_min, xv_max, yv_min, yv_max, &xv1, &yv1);
    windowToViewport(xw2, yw2, xw_min, xw_max, yw_min, yw_max, xv_min, xv_max, yv_min, yv_max, &xv2, &yv2);

    // Draw line in the viewport
    line(xv1, yv1, xv2, yv2);

    // Draw viewport rectangle
    rectangle(xv_min, yv_min, xv_max, yv_max);
    outtextxy(xv_min + 10, yv_min - 10, "Viewport");

    getch();
    closegraph();

    return 0;
}
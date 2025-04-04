#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int mousePosX, mousePosY;
int xnew, ynew;

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x)
    {
        drawCircle(xc, yc, x, y);
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
    }
}

void bezierCurve(int x[], int y[])
{
    double xu = 0.0, yu = 0.0, u = 0.0;
    int i = 0;
    for (u = 0.0; u <= 1.0; u += 0.0001)
    {
        xu = pow(1 - u, 3) * x[0] + 3 * u * pow(1 - u, 2) * x[1] + 3 * pow(u, 2) * (1 - u) * x[2] + pow(u, 3) * x[3];
        yu = pow(1 - u, 3) * y[0] + 3 * u * pow(1 - u, 2) * y[1] + 3 * pow(u, 2) * (1 - u) * y[2] + pow(u, 3) * y[3];
        putpixel((int)xu, (int)yu, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int i = 0;
    int x[4], y[4], flagDrawn = 0;

    while (1)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int mouseX = mousex();
            int mouseY = mousey();

            if (i < 4)
            {
                printf("Control Point(P%d):(%d,%d)\n", i, mouseX, mouseY);
                x[i] = mouseX;
                y[i] = mouseY;
                i++;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if (i == 4)
        {
            if (flagDrawn == 0)
            {
                bezierCurve(x, y);
                flagDrawn = 1;
            }

            // Draw circles at control points
            for (int j = 0; j < 4; j++)
            {
                circleBres(x[j], y[j], 8);
            }

            // Draw lines between control points
            for (int j = 0; j < 3; j++)
            {
                setcolor(RED);
                line(x[j], y[j], x[j + 1], y[j + 1]);
            }
        }

        delay(10); // Small delay to allow for drawing
    }

    closegraph();
    return 0;
}


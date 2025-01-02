#include <graphics.h>

void drawCircle(int xc, int yc, int r) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    for (int i = 0; i < 3; i++) { // Draw 3 circles with slightly different radii
        int radius = r + i;
        int x = 0;
        int y = radius;
        int p = 1 - radius; // Initial decision parameter

        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc + x, yc - y, WHITE);

        while (x < y) {
            x++;
            if (p < 0)
                p += 2 * x + 1;
            else {
                y--;
                p += 2 * (x - y) + 1;
            }
            putpixel(xc + x, yc + y, WHITE);
            putpixel(xc + y, yc + x, WHITE);
            putpixel(xc - y, yc + x, WHITE);
            putpixel(xc - x, yc + y, WHITE);
            putpixel(xc - x, yc - y, WHITE);
            putpixel(xc - y, yc - x, WHITE);
            putpixel(xc + y, yc - x, WHITE);
            putpixel(xc + x, yc - y, WHITE);
        }
    }

    getch();
    closegraph();
}

int main() 
{
    int xc, yc, r;
    printf("Enter the center coordinates (xc, yc) and radius (r) of the circle:\n");
    printf("xc: ");
    scanf("%d", &xc);
    printf("yc: ");
    scanf("%d", &yc);
    printf("Radius (r): ");
    scanf("%d", &r);
    drawCircle(xc, yc, r);
    return 0;
}
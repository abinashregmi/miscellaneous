#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <direct.h>

int main() {
    int i, gd = DETECT, gm;
    int x1, y1, x2, y2, xmin, xmax, ymin, ymax, xx1, xx2, yy1, yy2, dx, dy;
    float t1, t2, p[4], q[4], temp;

    // Input coordinates for the line
    x1 = 150;
    y1 = 150;
    x2 = 400;
    y2 = 400;

    // Input coordinates for the clipping window
    xmin = 200;
    ymin = 200;
    xmax = 350;
    ymax = 350;

    initgraph(&gd, &gm, (char*)"");

    // Draw the clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Draw the original line
    line(x1, y1, x2, y2);
    delay(2000);

    dx = x2 - x1;
    dy = y2 - y1;

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    t1 = 0;
    t2 = 1;

    for (i = 0; i < 4; i++) {
        temp = q[i] / p[i];
        if (p[i] < 0) {
            if (t1 < temp)
                t1 = temp;
        } else {
            if (t2 > temp)
                t2 = temp;
        }
    }

    if (t1 < t2) {
        xx1 = x1 + t1 * dx;
        xx2 = x1 + t2 * dx;
        yy1 = y1 + t1 * dy;
        yy2 = y1 + t2 * dy;

        // Wait for user input before drawing the clipped line
        printf("Press any key to see the clipped line...\n");
        getch();

        // Clear the screen and redraw the clipping window
        cleardevice();
        rectangle(xmin, ymin, xmax, ymax);

        // Draw the clipped line
        line(xx1, yy1, xx2, yy2);
    }

    delay(60000); // Delay for 1 minute (60,000 milliseconds)
    closegraph();
    return 0;
}
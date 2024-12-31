#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TDM-GCC-32\\BGI"); // Replace with the correct path to BGI files

    // Your graphics code here
    line(100, 100, 200, 200); // Example graphics function

    getch(); // Wait for user input
    closegraph();
    return 0;
}

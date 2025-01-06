#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle using the line() function
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}

// 8-connected boundary fill algorithm
void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
	if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
		putpixel(x, y, fillColor);
		boundaryFill(x + 1, y, fillColor, boundaryColor); // right
		boundaryFill(x - 1, y, fillColor, boundaryColor); // left
		boundaryFill(x, y + 1, fillColor, boundaryColor); // down
		boundaryFill(x, y - 1, fillColor, boundaryColor); // up
		boundaryFill(x + 1, y + 1, fillColor, boundaryColor); // down-right
		boundaryFill(x - 1, y - 1, fillColor, boundaryColor); // up-left
		boundaryFill(x + 1, y - 1, fillColor, boundaryColor); // up-right
		boundaryFill(x - 1, y + 1, fillColor, boundaryColor); // down-left
}


// void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
// 	if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
// 		putpixel(x, y, fillColor);
// 		boundaryFill(x + 1, y, fillColor, boundaryColor); // right
// 		boundaryFill(x - 1, y, fillColor, boundaryColor); // left
// 		boundaryFill(x, y + 1, fillColor, boundaryColor); // down
// 		boundaryFill(x, y - 1, fillColor, boundaryColor); // up
// 		boundaryFill(x + 1, y + 1, fillColor, boundaryColor); // down-right
// 		boundaryFill(x - 1, y - 1, fillColor, boundaryColor); // up-left
// 		boundaryFill(x + 1, y - 1, fillColor, boundaryColor); // up-right
// 		boundaryFill(x - 1, y + 1, fillColor, boundaryColor); // down-left
// 	}


}

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm,(char*)"");

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
	boundaryFill((x1 + x2 + x3 + x4 + x5 + x6) / 6, (y1 + y2 + y3 + y4 + y5 + y6) / 6, fillColor, boundaryColor);

	getch();
	closegraph();
	return 0;
}
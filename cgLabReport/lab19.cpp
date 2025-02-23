#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

// Define the clipping window boundaries
#define LEFT_EDGE 220
#define RIGHT_EDGE 420
#define BOTTOM_EDGE 340
#define TOP_EDGE 140

// Function to check if a point is inside the clipping window edge
int isInside(int edge, int x, int y) {
    switch (edge) {
        case 0: return x >= LEFT_EDGE;   // Left edge
        case 1: return x <= RIGHT_EDGE;  // Right edge
        case 2: return y <= BOTTOM_EDGE; // Bottom edge
        case 3: return y >= TOP_EDGE;    // Top edge
        default: return 0;
    }
}

// Function to compute intersection with the clipping window edge
void computeIntersection(int edge, int x1, int y1, int x2, int y2, int *x, int *y) {
    float m = (float)(y2 - y1) / (x2 - x1); // Slope of the line

    switch (edge) {
        case 0: // Left edge
            *x = LEFT_EDGE;
            *y = y1 + m * (LEFT_EDGE - x1);
            break;
        case 1: // Right edge
            *x = RIGHT_EDGE;
            *y = y1 + m * (RIGHT_EDGE - x1);
            break;
        case 2: // Bottom edge
            *y = BOTTOM_EDGE;
            *x = x1 + (BOTTOM_EDGE - y1) / m;
            break;
        case 3: // Top edge
            *y = TOP_EDGE;
            *x = x1 + (TOP_EDGE - y1) / m;
            break;
    }
}

// Function to clip the polygon against a single edge
void clipAgainstEdge(int edge, int *inputPolygon, int inputCount, int *outputPolygon, int *outputCount) {
    *outputCount = 0;
    int prevX = inputPolygon[(inputCount - 1) * 2];
    int prevY = inputPolygon[(inputCount - 1) * 2 + 1];

    for (int i = 0; i < inputCount; i++) {
        int currX = inputPolygon[i * 2];
        int currY = inputPolygon[i * 2 + 1];

        // Check if the current vertex is inside the edge
        if (isInside(edge, currX, currY)) {
            if (!isInside(edge, prevX, prevY)) {
                // Add intersection point
                computeIntersection(edge, prevX, prevY, currX, currY,
                                    &outputPolygon[(*outputCount) * 2],
                                    &outputPolygon[(*outputCount) * 2 + 1]);
                (*outputCount)++;
            }
            // Add current vertex
            outputPolygon[(*outputCount) * 2] = currX;
            outputPolygon[(*outputCount) * 2 + 1] = currY;
            (*outputCount)++;
        } else if (isInside(edge, prevX, prevY)) {
            // Add intersection point
            computeIntersection(edge, prevX, prevY, currX, currY,
                               &outputPolygon[(*outputCount) * 2],
                               &outputPolygon[(*outputCount) * 2 + 1]);
            (*outputCount)++;
        }

        prevX = currX;
        prevY = currY;
    }
}

// Function to clip the polygon against all edges
void clipPolygon(int *polygon, int n, int *clippedPolygon, int *clippedCount) {
    int intermediatePolygon[100]; // Temporary storage
    int intermediateCount;

    // Clip against left, right, bottom, and top edges
    clipAgainstEdge(0, polygon, n, intermediatePolygon, &intermediateCount);
    clipAgainstEdge(1, intermediatePolygon, intermediateCount, clippedPolygon, clippedCount);
    clipAgainstEdge(2, clippedPolygon, *clippedCount, intermediatePolygon, &intermediateCount);
    clipAgainstEdge(3, intermediatePolygon, intermediateCount, clippedPolygon, clippedCount);
}

int main() {
    int gd = DETECT, gm;
    int n, *x, i, k = 0;

    // Window coordinates
    int w[] = {LEFT_EDGE, TOP_EDGE, RIGHT_EDGE, TOP_EDGE, RIGHT_EDGE, BOTTOM_EDGE, LEFT_EDGE, BOTTOM_EDGE, LEFT_EDGE, TOP_EDGE}; // Array for drawing window

    // Initialize graphics
    initgraph(&gd, &gm, "");

    // Draw the window
    printf("Window:-");
    setcolor(LIGHTGRAY); // Red colored window
    drawpoly(5, w); // Window drawn

    // Input number of vertices
    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &n);

    // Allocate memory for polygon vertices
    x = (int *)malloc((n * 2 + 2) * sizeof(int)); // +2 for closing the polygon
    if (x == NULL) {
        printf("Memory allocation failed!");
        closegraph();
        return 1;
    }

    // Input polygon vertices
    printf("Enter the coordinates of points:\n");
    for (i = 0; i < n * 2; i += 2) {
        printf("(x%d, y%d): ", k, k);
        scanf("%d %d", &x[i], &x[i + 1]);
        k++;
    }

    // Close the polygon by assigning the first vertex to the last
    x[n * 2] = x[0];
    x[n * 2 + 1] = x[1];

    // Draw the original polygon
    setcolor(WHITE);
    drawpoly(n + 1, x);

    // Wait for user input
    printf("\nPress any key to clip the polygon...");
    getch();

    // Clip the polygon
    int clippedPolygon[100];
    int clippedCount;
    clipPolygon(x, n + 1, clippedPolygon, &clippedCount);

    // Clear the screen and redraw the window
    cleardevice();
    setcolor(WHITE);
    drawpoly(5, w);

    // Draw the clipped polygon
    setcolor(WHITE);
    drawpoly(clippedCount, clippedPolygon);

    // Display message
    printf("\nThis is the clipped polygon...");
    getch();

    // Free allocated memory
    free(x);

    // Close graphics
    closegraph();
    return 0;
}
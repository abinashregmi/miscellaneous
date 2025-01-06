#include <graphics.h>
#include <stdio.h>
void scanlinePolygonFill(int polygon[][2], int n)
{
int y, x, i, j;
    int x_intersect[20];
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    for (y = 0; y < getmaxy(); y++)
    {
        int k = 0;
        for (i = 0; i < n; i++)
        {
            j = (i + 1) % n;
            if ((polygon[i][1] <= y && polygon[j][1] > y) ||
                (polygon[j][1] <= y && polygon[i][1] > y))
            {
                x_intersect[k++] = (y - polygon[i][1]) *
                                   (polygon[j][0] - polygon[i][0]) /
                                   (polygon[j][1] - polygon[i][1]) +
                                   polygon[i][0];
            }
        }
        // Sorting the x-intersection points
        for (i = 0; i < k - 1; i++)
        {
            for (j = i + 1; j < k; j++)
            {
                if (x_intersect[i] > x_intersect[j])
                {
                    int temp = x_intersect[i];
                    x_intersect[i] = x_intersect[j];
                    x_intersect[j] = temp;
                }
            }
                for (i = 0; i < k; i += 2)
                {
                    line(x_intersect[i], y, x_intersect[i + 1], y);
                }
            }
        }
        getch();
        closegraph();
    }
    
    int main()
    {
        int n, i;
        printf("Enter the number of vertices of the polygon: ");
        scanf("%d", &n);
        int polygon[n][2];
        for (i = 0; i < n; i++)
        {
            printf("Enter x and y coordinates of vertex %d: ", i + 1);
            scanf("%d %d", &polygon[i][0], &polygon[i][1]);
        }
        scanlinePolygonFill(polygon, n);
        return 0;
        scanlinePolygonFill(polygon, n);
        return 0;
    }
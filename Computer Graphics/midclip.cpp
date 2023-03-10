#include <iostream>
#include <graphics.h>

using namespace std;

// Function to perform Mid-Point Subdivision Line Clipping
void MidPointSubdivision(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    // Calculate the position of both endpoints of the line
    int code1 = 0, code2 = 0;
    if (x1 < xmin) code1 |= 1;
    if (x1 > xmax) code1 |= 2;
    if (y1 < ymin) code1 |= 4;
    if (y1 > ymax) code1 |= 8;
    if (x2 < xmin) code2 |= 1;
    if (x2 > xmax) code2 |= 2;
    if (y2 < ymin) code2 |= 4;
    if (y2 > ymax) code2 |= 8;

    while ((code1 | code2) != 0) {
        // If the OR operation gives 0000, then the line is guaranteed to be visible
        if ((code1 & code2) != 0) return;

        // Perform AND operation on both endpoints
        int code = code1;
        if (code1 == 0) code = code2;

        double xm = 0, ym = 0;
        // Find midpoint of the line
        xm = (x1 + x2) / 2.0;
        ym = (y1 + y2) / 2.0;

        // Check each midpoint and calculate the code
        int codem = 0;
        if (xm < xmin) codem |= 1;
        if (xm > xmax) codem |= 2;
        if (ym < ymin) codem |= 4;
        if (ym > ymax) codem |= 8;

        // If the midpoint is inside the window, draw the line
        if (codem == 0) {
            line(x1, y1, x2, y2);
            return;
        }

        // Check which endpoint to replace with the midpoint
        if ((code & codem) != 0) {
            code1 = codem;
            x1 = xm;
            y1 = ym;
        } else {
            code2 = codem;
            x2 = xm;
            y2 = ym;
        }
    }

    // Draw the clipped line
    line(x1, y1, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Window coordinates
    int xmin = 100, ymin = 100, xmax = 300, ymax = 300;
    rectangle(xmin, ymin, xmax, ymax);

    // Line coordinates
    int x1 = 50, y1 = 150, x2 = 250, y2 = 350;

    // Draw the original line
    line(x1, y1, x2, y2);

    // Perform Mid-Point Subdivision Line Clipping
    MidPointSubdivision(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}


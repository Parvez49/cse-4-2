#include <iostream>
#include <graphics.h>

using namespace std;

int xmin, ymin, xmax, ymax;

const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int getcode(int x, int y)
{
    int code = 0;

    if (x < xmin)
    {
        code |= LEFT;
    }
    else if (x > xmax)
    {
        code |= RIGHT;
    }

    if (y < ymin)
    {
        code |= BOTTOM;
    }
    else if (y > ymax)
    {
        code |= TOP;
    }

    return code;
}

void midpoint_subdivision(int x1, int y1, int x2, int y2)
{
    int code1 = getcode(x1, y1);
    int code2 = getcode(x2, y2);
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int x, y;
            int codeout = (code1 != 0) ? code1 : code2;

            if (codeout & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeout & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeout & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (codeout & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeout == code1)
            {
                x1 = x;
                y1 = y;
                code1 = getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = getcode(x2, y2);
            }
        }
    }

    if (accept)
    {
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Rectangle to clip against
    int xmin = 100, ymin = 100, xmax = 300, ymax = 300;
    rectangle(xmin, ymin, xmax, ymax);

    // Line to clip
    int x1 = 50, y1 = 200, x2 = 400, y2 = 50;
    //line(x1, y1, x2, y2);

    // Clip the line against the rectangle
    midpoint_subdivision(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}


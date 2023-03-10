
#include <iostream>
#include <graphics.h>

using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int X_MIN = 100;
const int X_MAX = 500;
const int Y_MIN = 100;	
const int Y_MAX = 500;

int computeCode(double x, double y)
{
    int code = INSIDE;

    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;

    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;

    return code;
}

void clipLine(double x1, double y1, double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    while (true)
    {
        if (!(code1 | code2)) // line is completely inside the window
        {
            line(x1, y1, x2, y2);
            break;
        }
        else if (code1 & code2) // line is completely outside the window
            break;
        else
        {
            int code = code1 ? code1 : code2;

            double x, y;

            if (code & TOP)
            {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            }
            else if (code & BOTTOM)
            {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            }
            else if (code & RIGHT)
            {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            }
            else // code & LEFT
            {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            if (code == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
}

int main()
{
    initwindow(800,800);
    
    outtextxy(280,50,"ID: 174049");

    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
    //clipLine(50, 150, 200, 350);
    //clipLine(300, 100, 600,  500);
    //clipLine(400, 400, 700, 200);
    
    /*
    outtextxy(280,70,"Before clipping");
    line(150, 150, 400, 400);
    line(50, 400, 200, 50);
    line(300, 250, 550, 250);
	line(550, 400, 400, 550); 
	*/
	
	outtextxy(280,80,"After clipping");
	clipLine(150, 150, 400, 400);
    clipLine(50, 400, 200, 50);
    clipLine(300, 250, 550, 250);
	clipLine(550, 400, 400, 550); 
	
	
	
    while(!kbhit()){
    	delay(100);
	}
}



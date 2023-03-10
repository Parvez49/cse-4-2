

#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h> 

using namespace std;


int x_max=120,x_min=40,y_max=150,y_min=90;
int INSIDE = 0;int LEFT = 1;int RIGHT = 2;int BOTTOM = 4;int TOP = 8;

int digitcal(int x,int y){
	
	int code = 0;

	if (x < x_min)
		code |= LEFT;
	else if (x > x_max)
		code |= RIGHT;
	if (y < y_min)
		code |= BOTTOM;
	else if (y > y_max)
		code |= TOP;

	return code;	
}

void csl(int x1, int y1,int x2, int y2)
{
	int code1 = digitcal(x1, y1);
	int code2 = digitcal(x2, y2);
	
	bool accept = false;

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
			accept = true;
			break;
		}
		else if (code1 & code2) {
			break;
		}
		
		else {
			int code_out;
			double x, y;
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;
			if (code_out & TOP) {
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code_out & RIGHT) {
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code_out & LEFT) {
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = digitcal(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = digitcal(x2, y2);
			}
		}
	}
	if (accept) {
		cout << x1 << ", "<< y1 << " - " << x2 << ", " << y2 << endl;
	}
	else
		cout << "Line rejected" << endl;
}

int main(){
	
	initwindow(800,800);
	
	int x=4,y=9,x2=12,y2=15;
	rectangle(x*10,y*10,x2*10,y2*10);
	
	//AC
	line((x+2)*10,(y+5)*10,(x-3)*10,(y+2)*10);
	//BD
	line((x+10)*10,(y-1)*10,(x+4)*10,(y+8)*10);
	

	csl((x+2)*10,(y+5)*10,(x-3)*10,(y+2)*10);
	
	
	
	
	
	 
	
	while (!kbhit()){
		delay(100);
	}
}

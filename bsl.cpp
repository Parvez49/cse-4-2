#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std;


void bsl(int x1,int y1,int x2, int y2){
	int dx,dy,d,inc1,inc2;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if (abs(dy)<=abs(dx)){
		cout<<"Up\n";
		d=2*dy-dx;
		inc1=2*dy;
		inc2=2*(dy-dx);
		while (x1<=x2){
			putpixel(x1,y1,7);
			delay(30);
			if (d<=0){
				d=d+inc1;
			}
			else{
				d=d+inc2;
				y1++;
			}
			x1++;
		}
	}
	else{
		cout<<"Down\n";
		d=2*dx-dy;
		inc1=2*dx;
		inc2=2*(dx-dy);
		while (y1<=y2){
			putpixel(x1,y1,7);
			delay(30);
			if (d<=0){
				d=d+inc1;
			}
			else{
				d=d+inc2;
				x1++;
			}
			y1++;
		}
	}
}

int main(){
	initwindow(600,600);
	bsl(100,100,10,10);
	while(!kbhit()){
		delay(100);
	}
}

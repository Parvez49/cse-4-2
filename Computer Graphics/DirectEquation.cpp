
#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std;

int main(){
	int Xmin,Ymin,Xmax,Ymax;
	initwindow(600,600);
	Xmin=20;
	Xmax=600-20;
	Ymin=10;
	Ymax=600-10;
	rectangle(Xmin,Ymin,Xmax,Ymax);
	line(Xmax/2,Ymin,Xmax/2,Ymax);
	line(Xmin,Ymax/2,Xmax,Ymax/2);
	
	int x1,x2,y1,y2;
	float m,dx,dy,b;
	x1=10;
	y1=10;
	x2=100;
	y2=100;
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;
	b=y1-m*x1;
	
	int xstart,ystart,xend,yend;
	xstart=x1+Xmax/2;
	ystart=Ymax/2-y1;
	xend=x2+Xmax/2;
	yend=Ymax/2-y2;
	
	int x,y,xter,yter;
	if (m<1){
		if (dx<0){
			x=xend;
			y=yend;
			xter=xstart;
		}
		else{
			x=xstart;
			y=ystart;
			xter=xend;
		}
		while (x<=xend){
			putpixel(x,y,10);
			x+=1;
			y=m*x+b;
			y=floor(y+0.5);
		}
	}
	else{
		if (dy<0){
			x=xend;
			y=yend;
			yter=ystart;
		}
		else{
			x=xstart;
			y=ystart;
			yter=yend;
		}
		while (y<=yend){
			putpixel(x,y,10);
			y+=1;
			x=(y-b)/m;
			x=floor(x+0.5);
		}
	}


	
	while(!kbhit()){
		delay(100);
	}
	
	
}

#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std;


void sline(int x1,int y1,int x2,int y2){
	float m,dx,dy,b;
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;
	cout<<m<<" ";
	
	int xstart,ystart,xend,yend,inc1,inc2;
	
	if (-1*m>1 || m>1){
		if (dy<0){
			xstart=x2;
			ystart=y2;
			yend=y1;
		}
		if (dy>0){
			xstart=x1;
			ystart=y1;
			yend=y2;
		}
		
		inc1=2*dy;
		inc2=2*dy-2*dx;
		
		while(ystart<=yend)
		{
			int d=2*dy-dx;
			if(d>0)
			{
				putpixel(xstart,ystart,10);
				d=d+inc2;
				xstart--;
			}
			else
			{
				putpixel(xstart,ystart,10);
				d=d+ inc1;
			}
			ystart++;
		}
	}
	
	if (m<=1){
		if (dx<0){
			xstart=x2;
			ystart=y2;
			xend=x1;
		}
		if (dx>0){
			xstart=x1;
			ystart=y1;
			xend=x2;
		}
		inc1=2*dy;
		inc2=2*dy-2*dx;
		
		while(xstart<=xend)
		{
			int d=2*dy-dx;
			if(d>0)
			{
				putpixel(xstart,ystart,10);
				d=d+inc2;
				ystart--;
			}
			else
			{
				putpixel(xstart,ystart,10);
				d=d+ inc1;
			}
			xstart++;
		}
	}
	
	
	
}

void scircle(int r){
	int x=0;
	int y=r;
	int d=3-(2*r);
	
	int xc=205;
	int yc=130;
	
	putpixel(xc+x,yc-y,7);
	
	while (x<=y){
		putpixel(xc+x,yc-y,7);
		putpixel(xc-x,yc-y,10);
		putpixel(xc+x,yc+y,12);
		putpixel(xc-x,yc+y,15);
		putpixel(xc+y,yc-x,7);
		putpixel(xc-y,yc-x,10);
		putpixel(xc+y,yc+x,12);
		putpixel(xc-y,yc+x,15);
		x+=1;
		if (d<0){
			d+=(4*x+6);
		}
		else{
			d+=(4*(x-y)+10);
			y--;
		}	
		
	}
}


int main(){
	int Xmin,Ymin,Xmax,Ymax;
	initwindow(600,600);
	Xmax=600;
	Ymax=600;
	
	int x1=10,y1=10;
	int x2=400,y2=11;
	int x3=399,y3=249;
	int x4=9,y4=250;
	
	int r=60;
	int cx=int((400+10)/2),cy=int((10+250)/2);
	
	sline(10,10,400,11);
	sline(9,250,10,10);
	sline(9,250,399,249);
	sline(399,249,400,11);
	
	sline(206,10,205,130-60);
	sline(204,249,205,130+60);
	//sline(205,cy-60,205,1)
	scircle(60);
	
	
	while(!kbhit()){
	delay(100);
	}
}

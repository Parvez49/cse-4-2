

// Line Drawing algorithm using DDA

#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>  

using namespace std;

void dda(int x1,int y1,int x2,int y2);
void lineDirectEquaion(int x1,int y1,int x2,int y2);
void bresenhamline(int x1,int y1,int x2,int y2);
void bresenhamcircle(int x,int y,int r);
void bresenhamMidCircle(int xc,int yc,int r);
	
int main(){
	initwindow(600,600);
	int x1,y1,x2,y2;
	cout<<"Enter the two end points: ";
	//cin>>x1>>y1>>x2>>y2;
	
	//lineDirectEquaion(0,0,100,100); //diagonal
	//lineDirectEquaion(50,50,150,50); //horizontal
	//lineDirectEquaion(101,50,100,150); //vertical
	//lineDirectEquaion(200,0,100,100); //diagonal
	//lineDirectEquaion(10,10,200,10); //horizontal
	//lineDirectEquaion(10,10,11,200); //vertical
	
	//dda(0,0,100,100); //diagonal
	//dda(50,50,150,50); //horizontal
	//dda(101,50,100,150); //vertical
	//dda(200,0,100,100); //diagonal
	//dda(10,10,200,10); //horizontal
	//dda(10,10,11,200); //vertical
	
	//bresenhamline(0,0,100,100); //diagonal
	//bresenhamline(50,50,150,50); //horizontal
	//bresenhamline(101,50,100,150); //vertical
	//bresenhamline(200,0,100,100); //diagonal
	//bresenhamline(10,10,200,10); //horizontal
	//bresenhamline(10,10,11,200); //vertical
	
	//bresenhamcircle(300,300,70);
	bresenhamMidCircle(300,300,70);
			
	while (!kbhit()){
		delay(100);
	}	
}

void dda(int x1,int y1,int x2,int y2){
	//x1=200;y1=50;x2=20;y2=400;
	float dx,dy,m,b;
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;
	
	
	int x,y,xend,yend;
	float xsum,ysum;
	cout<<m;
	if (0<=m && m<=1){
		if (dx<0){
			x=x2;ysum=y2;xend=x1;
		}
		else{
			x=x1;ysum=y1;xend=x2;
		}	
		while (x<=xend){
			y=floor(ysum+0.5);
			putpixel(x,y,7);
			x++;
			ysum+=m;
		}
	}
	else {
		if (dy<0){
			xsum=x2;y=y2;yend=y1;
		}
		else{
			xsum=x1;y=y1;yend=y2;
		}	
		while (y<=yend){
			x=floor(xsum+0.5);
			putpixel(x,y,7);
			y++;
			xsum+=(1/m);
		}
	}
}

// Line drawing algorithm using direct equation
void lineDirectEquaion(int x1,int y1,int x2,int y2){
	//x1=200;y1=50;x2=20;y2=400;
	float dx,dy,m,b;
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;
	b=y1-m*x1;
	
	int x,y,xend,yend;
	if (0<=m && m<=1){
		if (dx<0){
			x=x2;y=y2;xend=x1;
		}
		else{
			x=x1;y=y1;xend=x2;
		}	
		while (x<=xend){
			putpixel(x,y,7);
			x++;
			y=floor(m*x+b);
		}
	}
	else {
		if (dy<0){
			x=x2;y=y2;yend=y1;
		}
		else{
			x=x1;y=y1;yend=y2;
		}	
		while (y<=yend){
			putpixel(x,y,7);
			y++;
			x=floor((y-b)/m);
		}
	}	
}
void bresenhamline(int x1,int y1,int x2,int y2){
	//x1=200;y1=50;x2=20;y2=400;
	int dx,dy,d,inc1,inc2;
	float m;
	dx=x2-x1;
	dy=y2-y1;
	m=dy/dx;

	
	int x,y,xend,yend;
	if (0<=m && m<=1){
		if (dx<0){
			x=x2;y=y2;xend=x1;
		}
		else{
			x=x1;y=y1;xend=x2;
		}	
		d=2*dy-dx;
		inc1=2*dy;
		inc2=2*(dy-dx);
		while (x<=xend){
			putpixel(x,y,7);
			if (d<=0){
				d+=inc1;
			}
			else{
				d+=inc2;
				y++;
			}
			x++;
		}
	}
	else {
		if (dy<0){
			x=x2;y=y2;yend=y1;
		}
		else{
			x=x1;y=y1;yend=y2;
		}	
		d=2*dx-dy;
		inc1=2*dx;
		inc2=2*(dx-dy);
		while (y<=yend){
			putpixel(x,y,7);
			if (d<=0){
				d+=inc1;
			}
			else{
				d+=inc2;
				x++;
			}
			y++;
		}
	}	
}
void bresenhamcircle(int xc,int yc,int r){
	int x=0,y=r,d=3-(2*r);
	while (x<=y){
		putpixel(xc+x,yc+y,7);
		putpixel(xc+x,yc-y,10);
		putpixel(xc-x,yc+y,12);
		putpixel(xc-x,yc-y,15);
		putpixel(xc+y,yc+x,7);
		putpixel(xc+y,yc-x,10);
		putpixel(xc-y,yc+x,12);
		putpixel(xc-y,yc-x,15);
		delay(100);
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
void bresenhamMidCircle(int xc,int yc,int r){
	int x=0,y=r,d=1-r;
	while (x<=y){
		putpixel(xc+x,yc+y,7);
		putpixel(xc+x,yc-y,10);
		putpixel(xc-x,yc+y,12);
		putpixel(xc-x,yc-y,15);
		putpixel(xc+y,yc+x,7);
		putpixel(xc+y,yc-x,10);
		putpixel(xc-y,yc+x,12);
		putpixel(xc-y,yc-x,15);
		delay(100);
		x+=1;
		if (d<0){
			d+=(2*x+3);
		}
		else{
			d+=(2*(x-y)+5);
			y--;
		}	
		
	}
}


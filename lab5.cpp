#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std;

void translation(int x11,int y11,int x22,int y22,int x33,int y33,int xc,int yc){
	int tx=80,ty=-50;
	int x1=x11+tx,x2=x22+tx,x3=x33+tx;
	int y1=y11+ty,y2=y22+ty,y3=y33+ty;
	
	line(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x3,yc+y3);
	line(xc+x2,yc+y2,xc+x3,yc+y3);
}

void scaling(int x11,int y11,int x22,int y22,int x33,int y33,int xc,int yc){
	float tx=0.5,ty=0.5;
	int x1=x11*tx,x2=x22*tx,x3=x33*tx;
	int y1=y11*ty,y2=y22*ty,y3=y33*ty;
	
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<< " "<<x3<<" "<<y3;
	line(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x3,yc+y3);
	line(xc+x2,yc+y2,xc+x3,yc+y3);
	
}


void xshear(int x11,int y11,int x22,int y22,int x33,int y33,int xc,int yc){
	float ty=0.5;
	int x1=x11,x2=x22,x3=x33;
	int y1=y11+x11*ty,y2=y22+x22*ty,y3=y33+x33*ty;
	
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<< " "<<x3<<" "<<y3;
	line(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x3,yc+y3);
	line(xc+x2,yc+y2,xc+x3,yc+y3);
	
}

/*
void xshear(int x11,int y11,int x22,int y22,int xc,int yc){
	
	cout<<x11<<" "<<y11<<" "<<x22<<" "<<y22<< " ";
	int ttx=70,tty=-70;
	float ty=0.5;
	int x1=x11+ttx,x2=x22+ttx;
	int y1=y11+x11*ty+tty,y2=y22+x22*ty+tty;
	
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<< " ";
	rectangle(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x3,yc+y3);
	line(xc+x2,yc+y2,xc+x3,yc+y3);
	
	line(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x3,yc+y3);
	line(xc+x2,yc+y2,xc+x3,yc+y3);
	
	
}
*/
void yshear(int x11,int y11,int x22,int y22,int x33,int y33,int xc,int yc){
	float tx=0.5;
	int x1=x11+y11*tx,x2=x22+y22*tx,x3=x33+y33*tx;
	int y1=y11,y2=y22,y3=y33;
	
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<< " "<<x3<<" "<<y3;
	line(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x3,yc+y3);
	line(xc+x2,yc+y2,xc+x3,yc+y3);
	
}

void rotation(int x11,int y11,int x22,int y22,int x33,int y33,int xc,int yc){
	cout<<x11<<" "<<y11<<" "<<x22<<" "<<y22<< " "<<x33<< " "<<y33;
	int tx=50,ty=-50;
	int x1=x11+tx,x2=x22+tx,x3=x33+tx;
	int y1=y11+ty,y2=y22+ty,y3=y33+ty;
	
	//line(xc+x1,yc+y1,xc+x2,yc+y2);
	//line(xc+x1,yc+y1,xc+x3,yc+y3);
	//line(xc+x2,yc+y2,xc+x3,yc+y3);
	
	int angle=180;
	float c = cos(angle *3.14/180);  
    float s = sin(angle *3.14/180);  
    
    x1 = floor(x1 * c - y1 * s);  
    y1 = floor(x1 * s + y1 * c);  
    x2 = floor(x2 * c - y2 * s);  
    y2 = floor(x2 * s + y2 * c); 
    x3 = floor(x3 * c - y3 * s);  
    y3 = floor(x3 * s + y3 * c); 
    
    line(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x3,yc+y3);
	line(xc+x2,yc+y2,xc+x3,yc+y3);
}

int main(){
	//initwindow(600,600);
	int Xmin,Ymin,Xmax,Ymax;
	initwindow(600,600);
	Xmin=20;
	Xmax=600-20;
	Ymin=50;
	Ymax=600-50;
	rectangle(Xmin,Ymin,Xmax,Ymax);
	line(Xmax/2,Ymin,Xmax/2,Ymax);
	line(Xmin,Ymax/2,Xmax,Ymax/2);
	
	int xc=Xmax/2;
	int yc=Ymax/2;
	
	int x1=100,y1=-100,x2=200,y2=-100;
	int x3=150 ,y3= -150;
	line(xc+x1,yc+y1,xc+x2,yc+y2);
	line(xc+x1,yc+y1,xc+x3,yc+y3);
	line(xc+x2,yc+y2,xc+x3,yc+y3);
	
	//translation(x1,y1,x2,y2,x3,y3,xc,yc);
	//scaling(x1,y1,x2,y2,x3,y3,xc,yc);
	//rotation(x1,y1,x2,y2,x3,y3,xc,yc);
	
	//xshear(x1,y1,x2,y2,x3,y3,xc,yc);
	//yshear(x1,y1,x2,y2,x3,y3,xc,yc);
	
	
	
	
	x1=50,y1=-200,x2=100,y2=-100;
	//rectangle(xc+x1,yc+y1,xc+x2,yc+y2);
	//xshear(x1,y1,x2,y2,xc,yc);
	
	//xshear(x1,y1,x2,y2,x3,y3,xc,yc);
	//yshear(x1,y1,x2,y2,x3,y3,xc,yc);
	
	rotation(x1,y1,x2,y2,x3,y3,xc,yc);
	
	
	
	//translations
	
	
	
	
	
	
	
	
	while(!kbhit()){
		delay(100);
	}
}

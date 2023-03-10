
#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std;

int main(){
	int Xmin,Ymin,Xmax,Ymax;
	initwindow(600,600);
	Xmin=20;
	Xmax=600-20;
	Ymin=50;
	Ymax=600-50;
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
	//b=y1-m*x1;
	
	int xstart,ystart,xend,yend,inc1,inc2;
	xstart=x1+Xmax/2;
	ystart=Ymax/2-y1;
	xend=x2+Xmax/2;
	yend=Ymax/2-y2;
	
	char heading[50],h1[20];
	strcpy(heading,"(ID: ");
	strcat(heading,itoa(174049,h1,10));
	strcat(heading,")");
	outtextxy(200,30,heading);
	
	char st[20],st1[20];
	strcpy(st,"(");
	strcat(st,itoa(x1,st1,10));
	strcat(st,",");
	strcat(st,itoa(y1,st1,10));
	strcat(st,")");
	outtextxy(xstart+10,ystart-5,st);
	
	strcpy(st,"(");
	strcat(st,itoa(x2,st1,10));
	strcat(st,",");
	strcat(st,itoa(y2,st1,10));
	strcat(st,")");
	outtextxy(xend+10,yend-5,st);
	
	char topic[100];
	strcpy(topic,"Algorithm: Bresenhams's Line Algorithm");
	outtextxy(150,570,topic);
	
	
	inc1=2*dy;
	inc2=2*dy-2*dx;
	
	while(xstart<=xend)
	{
		int d=2*dy-dx;
		if(d>0)
		{
			putpixel(xstart,ystart,10);
			delay(100);
			d=d+inc2;
			ystart--;
		}
		else
		{
			putpixel(xstart,ystart,10);
			delay(100);
			d=d+ inc1;
		}
		xstart++;
	}
		
	while(!kbhit()){
		delay(100);
	}
	
}



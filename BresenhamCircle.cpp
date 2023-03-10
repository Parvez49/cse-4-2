
#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std;

int main(){
	int Xmin,Ymin,Xmax,Ymax;
	initwindow(600,600);
	Xmin=20;Xmax=600-20;
	Ymin=50;
	Ymax=600-50;
	rectangle(Xmin,Ymin,Xmax,Ymax);
	line(Xmax/2,Ymin,Xmax/2,Ymax);
	line(Xmin,Ymax/2,Xmax,Ymax/2);
	
	
	char topic[100];
	strcpy(topic,"Algorithm: Bresenhams's Circle Algorithm");
	outtextxy(150,570,topic);
	
	//--------------------------------------------------------------
	
	char heading[50],h1[20];
	strcpy(heading,"(ID: ");
	strcat(heading,itoa(174049,h1,10));
	strcat(heading,")");
	outtextxy(200,30,heading);
	
	int x,y,r,h,k;
	float d;
	cout<<"Enter the radius of circle: ";
	//cin>>r;
	r=100;
	cout<<"Enter the center of circle: ";
	//cin>>h>>k;
	h=-150;
	k=-150;
	
	
	
	x=0;
	//r=50;
	y=r;
	
	
	d=3-(2*r);
	
	int xc=Xmax/2+h;
	int yc=Ymax/2-k;
	
	circle(xc,yc,2);
	char st[20],st1[20];
	strcpy(st,"(");
	strcat(st,itoa(h,st1,10));
	strcat(st,",");
	strcat(st,itoa(k,st1,10));
	strcat(st,")");
	outtextxy(xc+10,yc,st);
	
	strcpy(st,"r=");
	strcat(st,itoa(r,st1,10));
	outtextxy(xc+10,yc+50,st);
	
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
	
	while (!kbhit()){
		delay(100);
	}
}
	
	
	

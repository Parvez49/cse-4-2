#include<bits/stdc++.h>
#include<stdio.h>  
#include<graphics.h>  
#include<math.h>  

using namespace std;
int main()  
{  
    int x1,y1,x2,y2,x3,y3;  
    double s,c, angle;  
    
    initwindow(600,600);
    //setbkcolor(WHITE);  
    
    x1=200;y1=300;x2=300;y2=300;
	x3=250,y3=250;
    line(x1,y1,x2,y2);  
    line(x2,y2, x3,y3);  
    line(x3, y3, x1, y1);  
    
    
    angle=180; 
    c = cos(angle *3.1416/180);  
    s = sin(angle *3.1416/180);  
    x1 = floor(x1 * c - y1 * s);  
    y1 = floor(x1 * s + y1 * c);  
    x2 = floor(x2 * c - y2 * s);  
    y2 = floor(x2 * s + y2 * c);  
    x3 = floor(x3 * c - y3 * s);  
    y3 = floor(x3 * s + y3 * c);  
    
    cout<<x1<<" "<<y1<<"  "<<x2<<" "<<y2<<"  "<<x3<<" "<<y3;
    
    //cleardevice();  
    line(x1, y1 ,x2, y2);  
    line(x2,y2, x3,y3);  
    line(x3, y3, x1, y1);  
    
    /*
    //getch();  
    //closegraph();  
    //return 0; 
    
    */
    
	while(!kbhit()){
		delay(100);
	} 
}  

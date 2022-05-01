// Mid Point Cirlce Drawing Algorithm 
// Annie Bhalla
// 19HCS4009

#include<conio.h>
#include<graphics.h>
#include<iostream>

using namespace std;

void circlePoints( int xc, int yc, int x, int y, int val){
	// 1st quadrant
	putpixel( xc+x, yc+y , val);
	putpixel( xc+y, yc+x , val);
	
	// 2nd Quadrant
	putpixel( xc-x, yc+y , val);
	putpixel( xc-y, yc+x , val);
	
	// 3rd Quadrant
	putpixel( xc-x , yc-y , val);
	putpixel( xc-y , yc-x , val);
	
	//4th Quadrant
	putpixel( xc+x , yc-y , val);
	putpixel( xc+y , yc-x, val);
}


void midpointcircle(int xc, int yc, int r){
	int x=0, y=r, pk;
	
	pk=1-r;
	circlePoints(x,y,xc,yc,15);
	
	while(x<y){  // only calculate points in the 90-45 deg octant
		
		if(pk<0){
			pk+= 2*x + 3;
		}else{
			y= y-1;
			pk+= 2*(x-y) + 5;
		}
		x=x+1;
		circlePoints(xc,yc,x,y,15);
	}
}



int main()
{
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "xxx");
	int xc,yc,r;
	cout<<"Enter radius: ";
	cin>>r;
	cout<<"Enter centre of circle (xc,yc): ";
	cin>>xc>>yc;
	
	midpointcircle(xc,yc,r);
	getch();
	closegraph();
}

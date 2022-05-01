// Hermite Curve
// Annie Bhalla
// 19HCS4009

#include<graphics.h>
#include<iostream>

using namespace std;

struct point{
	int x,y;
}P[4];

int main(){
 // 4 control points to construct a cubic polynomial hermite curve
	double put_x,put_y,t;
	double r1, r4;
	
	int gr=DETECT,gm;
	initgraph(&gr,&gm,"xxx");
	
	cout<<"\n Enter x and y coordinates";
	for(int i=0; i<4; i++){
		cout<<"\n x"<<(i+1)<<" and y"<<(i+1)<<" ";
		cin>>P[i].x>>P[i].y;
		putpixel( P[i].x, P[i].y,  9);   // to display the control points
	}
	
	cout<<"\n Enter tangents at P1 and P4 ";
	cin>>r1>>r4;
	
	  // t lies between 0 and 1
	 for(t=0.0;t<=1.0;t+=0.001)
        {
            put_x=(2*t*t*t-3*t*t+1)*P[0].x+(-2*t*t*t+3*t*t)*P[3].x+(t*t*t-2*t*t+t)*r1+(t*t*t-t*t)*r4;
            put_y=(2*t*t*t-3*t*t+1)*P[0].y+(-2*t*t*t+3*t*t)*P[3].y+(t*t*t-2*t*t+1)*r1+(t*t*t-t*t)*r4;
            putpixel(put_x,put_y,YELLOW);
        }	
	
	
	getch();
	closegraph();
	
}

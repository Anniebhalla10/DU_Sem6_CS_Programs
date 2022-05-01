// DDA Line Drawing Algorithm
// Annie Bhalla
// 19HCS4009

#include<graphics.h>  
#include<conio.h>  
#include<stdio.h>  

int main(){
	
	int gd= DETECT, gm, i; // gd- graphicsdriver, gm= graphicsmode
	 //void initgraph(int *graphicsDriver, int *graphicsMode, char *driverDirectoryPath)
	initgraph( &gd, &gm , "");
	
//	The SetBkColor function sets the current background color to the specified color value, 
//   or to the nearest physical color if the device cannot represent the specified color value.
	setbkcolor(WHITE);
	float x,y,dx,dy,steps;
	int x1,y1,x2,y2;
	
	x1= 100, x2= 500, y1= 60, y2= 260;
	
	dx= (float)(x2-x1);
	dy= (float)(y2-y1);
	
	if( dx>= dy){
		steps= dx;
	}else{
		steps=dy;
	}
	dx= dx/steps;
	dy= dy/steps;
	x= x1;
	y=y1;
	i=1;
	while(i<=steps){
		putpixel(x,y, BLUE);
		x += dx;
		y += dy;
		i+=1;
	}
	getch();
	closegraph();	
}

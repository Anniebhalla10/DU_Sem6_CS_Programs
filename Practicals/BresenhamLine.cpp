// Breseham's Line Drawing Algorithm
// Annie BHalla
// 19HCS4009

#include<graphics.h>
#include<iostream>

using namespace std;
void plotPixel( int x1, int y1, int x2,  int y2, int dx, int dy,int decide){

	int pk = 2 * dy - dx;
	
	for (int i=0;i <=dx;i++){
		cout<<x1<<","<<y1<<endl;
		
		if(pk<0){
			if(decide==0){
				putpixel(x1, y1, RED);
				pk = pk + 2 * dy;
				x1 < x2 ? x1++ : x1--;
			}else{
				putpixel(x1,y1, YELLOW);
				pk= pk+ 2*dx;
					y1< y2 ? y1++: y1--;
			}
		}else{	
			if(decide==0){
					putpixel(x1,y1, RED);
					pk = pk- 2*dx + 2*dy;
			}else{
				putpixel(x1,y1, YELLOW);
					pk = pk- 2*dy + 2*dx;
			}
			x1 < x2 ? x1++ : x1--;
			y1 < y2 ? y1++: y1--;
			
		}
	}	
}



int main(){
	
	int gd= DETECT, gm, i;
	initgraph( &gd, &gm, "");
	
	int x1,x2,y1,y2, pk;
	float dx,dy, m;
	
	x1= 200, y1=300;
	x2=100 , y2= 200;
	
	dx= (abs)(x2-x1);
	dy= (abs)( y2-y1);
	 m= dy/dx;
	 pk=( 2* dy)-dx;

	if( m<1){

	plotPixel(x1, y1, x2, y2, dx, dy, 0);
		
	}else{
		
	plotPixel(x1, y1, x2, y2, dx, dy, 1);
}
getch();
closegraph();	
	
}

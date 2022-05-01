// 3D Transfanglermations
// Annie Bhalla
// 19HCS4009

#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<dos.h>
#include<iostream>

using namespace std;

int maxx,maxy,midx,midy;
int tx,ty, sx,sy,sz;
float angle;

void get3d(){
	midx=200;
	midy=200;

    //function to draw 3D rectangular box  
    bar3d(midx+50,midy-100,midx+100,midy-50,20,1);
  	delay(1000);
}



void translate(){
	cout<<"\n Enter the translational factor ";
	cin>>tx>>ty;

	bar3d(midx+tx+50 ,midy-(ty+100), midx+ tx +100, midy-(ty+50),20,1);
}

void rotate(){
	int x1, x2, y1, y2;
	cout<<"\n Enter rotating angle ";
	cin>>angle;
	
	x1 = 50 * cos(angle * 3.14 / 180) - 100 * sin(angle * 3.14 / 180);
  	y1 = 50 * sin(angle * 3.14 / 180) + 100 * cos(angle * 3.14 / 180);

  	x2 = 60 * cos(angle * 3.14 / 180) - 90 * sin(angle * 3.14 / 180);

  	y2 = 60 * sin(angle * 3.14 / 180) + 90 * cos(angle * 3.14 / 180);

	cout<<"\n After rotation  about x axis";
	bar3d(midx + 50, midy - x1, midx + 60, midy - x2, 5, 1);
	 
 	cout<<"\n After rotation about yaxis";
	bar3d(midx + x1, midy - 100, midx + x2, midy - 90, 5, 1);
	
}

void scale(){
	
            midx=200;
            midy=300;
          cout<<"\n Enter scaling factor sx,sy,sz ";
          cin>>sx>>sy>>sz;
            bar3d(midx+(sx*50),midy-(sy*100),midx+(sz*100),midy-(sy*50),20*sz,1);
}


int main(){
		int gd= DETECT, gm;
	int ch;

	initgraph(&gd, &gm, "xxx");
	get3d();
	setcolor(YELLOW);
	delay(500);
	
	cout<<"\n *********** MENU ******** ";
	cout<<"\n 1. Translation ";
	cout<<"\n 2. Rotation ";
	cout<<"\n 3. Scaling ";
	cout<<"\n Enter your choice ";
	cin>>ch;
	

	switch(ch){
		case 1: translate();
				break;
		case 2: rotate();
				break;
		case 3: scale();
				break;				
	}
	getch();
	closegraph();
}

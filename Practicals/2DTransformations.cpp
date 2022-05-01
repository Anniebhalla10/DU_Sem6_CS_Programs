// 2D Transformations
// Annie Bhalla
// 19HCS4009

#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int x[100], y[100], tx, ty, n;
float angle, sx, sy;
double s,c;

void getPolygon(){
	cout<<"\n Enter the number of sides of a polygon ";
	cin>>n;
	
	cout<<"\n Enter the coordinates of each vertex ";
	for(int i=0; i<n;i++){
		cout<<"\n x"<<(i+1)<<" and y"<<(i+1)<<" ";
		cin>>x[i]>>y[i];
	}
}

void draw(){
	for(int i=0; i<n;i++){
		line(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
	}
}

void translate(){
	cout<<"\n Enter the translational factor ";
	cin>>tx>>ty;
	
	for(int i=0; i<n;i++){
		x[i] += tx;
		y[i] += ty;
	}
}

void rotate(){
	cout<<"\n Enter the angle ";
	cin>>angle;
	
	c = cos(angle*3.14/180);
	s = sin(angle*3.14/180);
	
	for(int i=0; i<n;i++){
		x[i] = floor(x[i]*c + y[i]*s);
		y[i] = floor(-x[i]*s + y[i]*c);
	}
}


void scale(){
	cout<<"\n Enter the scaling factor (sx, sy) "<<endl;
	cin>>sx>>sy;
	
	for(int i=0; i<n;i++){
		x[i] = x[0]+(int)((float)(x[i] - x[0])*sx);
//		x[i] = x[i]*sx;
		y[i] = y[0]+(int)((float)(y[i]-y[0])*sy);
//		y[i]= y[i]* sy;
	}
}

void drawInBox(){
	for(int i=0; i<n;i++){
		line(x[i], y[i]+(angle/10)*50, x[(i+1)%n], y[(i+1)%n]+(angle/10)*50);
	}
}

int main(){
	int gd= DETECT, gm;
	int ch;

	initgraph(&gd, &gm, "xxx");
	getPolygon();
	setcolor(RED);
	draw();
	delay(500);
	
	cout<<"\n *********** MENU ******** ";
	cout<<"\n 1. Translation ";
	cout<<"\n 2. Rotation ";
	cout<<"\n 3. Scaling ";
	cout<<"\n Enter your choice ";
	cin>>ch;
	

	switch(ch){
		case 1: translate();
				setcolor(YELLOW);
				draw();
				break;
		case 2: rotate();
				setcolor(CYAN);
				drawInBox();
				break;
		case 3: scale();
				setcolor(BLUE);
				draw();
				break;				
	}
	getch();
	closegraph();
}

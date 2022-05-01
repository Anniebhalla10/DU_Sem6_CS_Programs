#include<bits/stdc++.h>
#include<graphics.h>



using namespace std;

int gd=DETECT, gm;
int n, x[100], y[100], i;
float angle;
double s, c;


void rotate();
void draw();
void drawInBox();

int main(){
	system("cls");
	cout<<"Enter number of sides of polygon: ";
	cin>>n;
	char a = 'y';
	while(a=='y'){
		cout<<"Enter co-ordintes: x, y for each vertex:-\n";
	for(i=0;i<n;i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	printf("Enter rotation angle:");
	scanf("%f", &angle);
	c = cos(angle*3.14/180);
	s = sin(angle*3.14/180);
	initgraph(&gd, &gm, "C:\\turboc3\\BGI\\");
	cleardevice();
	setcolor(CYAN);
	draw();
	rotate();
	setcolor(YELLOW);
	drawInBox();
	getch();
	cout<<'do you wanna continue:-';
	cin>>a;
	}
	
}
void draw(){
	for(i=0; i<n;i++){
		line(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
	}
}
void drawInBox(){
	for(i=0; i<n;i++){
		line(x[i], y[i]+(angle/10)*50, x[(i+1)%n], y[(i+1)%n]+(angle/10)*50);
	}
}

void rotate(){
	for(i=0; i<n;i++){
		x[i] = floor(x[i]*c + y[i]*s);
		y[i] = floor(-x[i]*s + y[i]*c);
	}
}

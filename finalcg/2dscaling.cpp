#include<bits/stdc++.h>
#include<graphics.h>



using namespace std;

int gd=DETECT, gm;
int n, x[100], y[100], i;
float sfx, sfy;

void draw();
void scale();

int main(){
	system("cls");
	cout<<"Enter number of sides of polygon: ";
	cin>>n;
	cout<<"Enter co-ordintes: x, y for each vertex ";
	for(i=0;i<n;i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	printf("Enter scale factors: (sfx, sfy)");
	scanf("%f%f", &sfx, &sfy);
	initgraph(&gd, &gm, "C:\\turboc3\\BGI\\");
	cleardevice();
	setcolor(CYAN);
	draw();
	scale();
	setcolor(YELLOW);
	draw();
	getch();
}
void draw(){
	for(i=0; i<n;i++){
		line(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
	}
}

void scale(){
	for(i=0; i<n;i++){
		x[i] = x[0]+(int)((float)(x[i] - x[0])*sfx);
		y[i] = y[0]+(int)((float)(y[i]-y[0])*sfy);
	}
}

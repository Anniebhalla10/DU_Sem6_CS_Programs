#include<bits/stdc++.h>
#include<graphics.h>



using namespace std;

int gd=DETECT, gm;
int n, xs[100], ys[100], i, ty, tx;

void draw();
void translate();

int main(){
	cout<<"Enter number of sides of polygon: ";
	cin>>n;
	cout<<"Enter co-ordintes: x, y for each vertex ";
	for(i=0;i<n;i++){
		scanf("%d%d", &xs[i], &ys[i]);
	}
	printf("Enter distances for translation (in x and y directions)");
	scanf("%d%d", &tx, &ty);
	initgraph(&gd, &gm, "C:\\turboc3\\BGI\\");
	cleardevice();
	setcolor(RED);
	draw();
	translate();
	setcolor(YELLOW);
	draw();
	getch();
}
void draw(){
	for(i=0; i<n;i++){
		line(xs[i], ys[i], xs[(i+1)%n], ys[(i+1)%n]);
	}
}

void translate(){
	for(i=0; i<n;i++){
		xs[i] += tx;
		ys[i] += ty;
	}
}

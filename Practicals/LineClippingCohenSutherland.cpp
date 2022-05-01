// Line clipping using Cohen Sutherland Line Clipping Algorithm
// Annie Bhalla
// 19HCS4009

#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

typedef struct coordinate
	{
		int x,y;
		char code[4];
	}PT;
	
typedef struct window{
	int xmin,ymin, xmax, ymax;
}CW;

void drawline(PT p1,PT p2)
	{
	line(p1.x,p1.y,p2.x,p2.y);
	}

PT setcode(PT p, CW c){ //for setting the 4 bit code
	PT ptemp;
	
	if(p.y< c.ymin)
		ptemp.code[0]='1'; //Top
		else
			ptemp.code[0]='0';
	
	
	if(p.y> c.ymax)
		ptemp.code[1]='1'; //Bottom
		else
			ptemp.code[1]='0';

	if(p.x> c.xmax)
		ptemp.code[2]='1'; //Right
		else
			ptemp.code[2]='0';
	
	if(p.x< c.xmin)
		ptemp.code[3]='1'; //Left
		else
			ptemp.code[3]='0';
	
	ptemp.x=p.x;
	ptemp.y=p.y;
	
	return(ptemp);
}
	 
int visibility(PT p1,PT p2){
	int i,flag=0;
	
	for(i=0;i<4;i++)
		{
			if((p1.code[i]!='0') || (p2.code[i]!='0'))
				flag=1;
		}
	
	if(flag==0)
		return(0); // flag =0 means that it is inside and we have to draw the whole line itself
				// incase flag==1 then we move ahead and check
	
	// case2: if at any position same bit is 1 then it is outside , so we draw nothing we return 1 in this case
	for(i=0;i<4;i++)
		{
			if((p1.code[i]==p2.code[i]) && (p1.code[i]=='1'))
				flag='0';
		}
	
	if(flag==0)
		return(1);
	
	return(2); // line is clipped we return 2
}

void drawwindow(CW cw){
	line( cw.xmin, cw.ymin, cw.xmax, cw.ymin);
	line(cw.xmin, cw.ymin, cw.xmin, cw.ymax);
	line(cw.xmin, cw.ymax, cw.xmax, cw.ymax);
	line(cw.xmax, cw.ymax, cw.xmax, cw.ymin);
}

PT resetEndPts( PT p1, PT p2, CW cw){
	PT temp;
	int x,y,i;
	float m, x_new, y_new;
	
	// T=0 B=1 R=2 L=3
	if(p1.code[3]=='1')
		x= cw.xmin;
	
	if(p1.code[2]=='1')
		x= cw.xmax;
	

	// for right and left case, x is constant either xmin or xmax , y will change accoridng to formula
	if((p1.code[3]=='1') || (p1.code[2]=='1')){
	
		m=(float)(p2.y-p1.y)/(p2.x-p1.x); // calculating slope
		y_new =(p1.y+(m*(x-p1.x)));
	
		temp.y= y_new;
		temp.x= x;
	
		for(i=0;i<4;i++)
			temp.code[i]=p1.code[i];
	
		if(temp.y<= cw.ymax && temp.y>= cw.ymin)
				return (temp);
		}

	if(p1.code[0]=='1')
		y= cw.ymin;
	
	if(p1.code[1]=='1')
		y= cw.ymax;
	
	// handling top and bottom case
	if((p1.code[0]=='1') || (p1.code[1]=='1')){
	
	m = (float)(p2.y-p1.y)/(p2.x-p1.x);
	x_new = (float)p1.x+(float)(y-p1.y)/m;
	temp.x= x_new;
	temp.y= y;
	
	for(i=0;i<4;i++)
		temp.code[i]=p1.code[i];
	
	return(temp);
	}else
	return(p1);
}


int main(){
	int gd= DETECT, gm;
	double xmin, ymin, xmax, ymax;
	int v;
	PT p1,p2,p3,p4,ptemp;
	CW cw;
	
	cout<<"Enter first line coordinates : ";
	cin>>p1.x>>p1.y;
	
	cout<<"\n Enter second line coordinates: ";
	cin>>p2.x>>p2.y;

//	cout<<"\n Enter the coordinates for clipping window: ";
//	cin>>cw.xmin>>cw.ymin>>cw.xmax>>cw.ymax;
	
	initgraph(&gd, &gm, "xxx");
	cw.xmin= 150;
	cw.ymin=100;
	cw.xmax= 450;
	cw.ymax=350;
	//Drawing the clipping window
	drawwindow(cw);
		
	delay(500);
	drawline(p1,p2);
	delay(500);
	cleardevice();
	delay(500);
	
	
	p1=setcode(p1, cw);
	p2=setcode(p2, cw);
	
	v=visibility(p1,p2);
	
	switch(v){
		case 0: drawwindow(cw);
					delay(500);
					drawline(p1,p2);
					break;
		case 1: drawwindow(cw);
				break;
		case 2: p3 = resetEndPts(p1, p2 , cw);
				p4= resetEndPts(p2, p1, cw);
				drawwindow(cw);
				delay(500);
				drawline(p3,p4);
				break;
	}
	
	delay(5000);
	getch();
	closegraph();

}

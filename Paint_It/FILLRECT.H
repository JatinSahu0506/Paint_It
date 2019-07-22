
#include<graphics.h>
#include<dos.h>

//DECLARATIONS
void fillrectangle(int,int,int,int,int);
void pattern(int,int,int,int,int,int);
void load(int,int,int,int,int);
void exit_bar(int,int,int,int,int);
void fillcircle(int,int,int,int);

//DEFINITIONS
void fillrectangle(int x1,int y1,int x2,int y2,int color)
{
	int i,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	for(i=x1;i<x2;i++)
	{
		setcolor(color);
		rectangle(i,y1,i,y2);
	}
}
void load(int x1,int y1,int x2,int y2,int col)
{

	outtextxy(x1,y1-13,"Loading........");
	rectangle(x1,y1,x2,y2);
	for(int o=x1+2;o<x1-2;o++)
	{
		setcolor(col);
		rectangle(o,y1+2,o,y2-2);
		delay(2);
	}
}
void exit_bar(int x1,int y1,int x2,int y2,int col)
{
	setcolor(col);
	outtextxy(x1,y1-13,"Exiting........");
	rectangle(x1,y1,x2,y2);
	for(int o=x1+2;o<x1-2;o++)
	{
		rectangle(o,y1+2,o,y2-2);
		delay(10);
	}
}
void pattern(int x1,int y1,int x2,int y2,int pat,int col)
{
	setfillstyle(pat,col);
	bar(x1,y1,x2,y2);

}
void fillcircle(int x,int y,int r,int col)
{
	setcolor(col);
	for(int i=0;i<=r;i++)
	{
		circle(x,y,i);
	}
}
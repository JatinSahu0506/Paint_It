/*
************************* A PROGRAM TO PAINT YOUR IMAGINATION **************
******************             	  by JATIN SAHU	        ********************
*****************               USING C/C++ CODES        *********************
******************	       	  IN  TURBO C++        ***********************
**********************    RUN AND ENJOY THE PAINT_BRUSH   *******************
--------------------------************************--------------------------
*/
#include<iostream.h>
#include<process.h>
#include "fillrect.h"
#include<dos.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
union REGS i,o;
int color=BLACK;
class Paint
{
	int j,inc,k;
	public:
	Paint()      //638,474 & 319,237
	{
		setfillstyle(SOLID_FILL,WHITE);
		bar(1,11,550,414);
		message_box();
	}
	void color_selector();
	void getMousePos(int *,int *,int *);
	void tools();
	void tool_selector(int,int,int,int *);
	void draw_circle();
	void message_box();
	void input_box();
	void draw_rectangle();
	void draw_shape(int);
	void savefile();
	void openfile();
};
void Paint::savefile()
{
	ofstream fil;
	char flname[10];
	int temp;
	gotoxy(71,24);gets(flname);
	strcat(flname,".txt");
	fil.open(flname,ios::out);
	for(int i=11;i<=414;i++)
	{
		for(int j=1;j<=550;j++)
		{
		     temp=getpixel(j,i);
		     fil.put(temp);
		}
	}
	input_box();
	message_box();
}
void Paint::openfile()
{
	ifstream fil;
	char flname[10];
	int temp;
	gotoxy(71,24);gets(flname);
	strcat(flname,".txt");
	fil.open(flname,ios::in);
	for(int i=11;i<=414;i++)
	{
		for(int j=1;j<=550;j++)
		{
		    //  a=getpixel(j,i);
		     // fil<<a;
		     temp=fil.get();
		     putpixel(j,i,temp);
		     temp=0;
		}
	}
	input_box();
	message_box();
}
void Paint::draw_circle()
{
	message_box();
	outtextxy(1,425,"MESSAGE BOX : Click anywhere on the white page !!!");
	i.x.ax=3;
	int button1,x1,y1,r;
	while(!kbhit())
	{
		int86(51,&i,&o);
		getMousePos(&button1,&x1,&y1);
		if(button1==1)
		{
			if((x1>=1)&&(x1<=550)&&(y1>=11)&&(y1<=414))
			{
				setcolor(YELLOW);
				outtextxy(1,438,"Enter the radius of the circle : ");
				gotoxy(74,24);cin>>r;
				delay(1000);
				setcolor(color);
				circle(x1,y1,r);
				input_box();
				message_box();
				break;
			}
		}
	}
}
void Paint::draw_shape(int check)
{
	message_box();
	outtextxy(1,425,"MESSAGE BOX : Point to any two points.... ");
	i.x.ax=3;
	int button2,x2,y2,flag=0,inc=0;
	int x_l[2],y_l[2];
	while(!kbhit())
	{
		int86(51,&i,&o);
		button2=o.x.bx;
		x2=o.x.cx;
		y2=o.x.dx;
		if(button2==1)
		{
			if((x2>=1)&&(x2<=550)&&(y2>=11)&&(y2<=414))
			{
				x_l[flag]=x2;
				y_l[flag]=y2;
				flag++;
				outtextxy(1,438,"MESSAGE BOX : Press any key");
				getch();
				message_box();
				outtextxy(1,425,"MESSAGE BOX : Point to second point...");
			}
		}      /*
		if(button2==2)
		{
			if((x2>=1)&&(x2<=550)&&(y2>=11)&&(y2<=414))
			{
				flag++;
				x_l[inc]=x2;
				y_l[inc]=y2;
			}
		}     */
		if(flag==2)
		{
			setcolor(color);
			if(check==1)
			rectangle(x_l[0],y_l[0],x_l[1],y_l[1]);
			else if(check==2)
			line(x_l[0],y_l[0],x_l[1],y_l[1]);
			break;
		}
	}
	message_box();
}

void Paint::input_box()
{
	pattern(553,364,593,391,9,BLACK);
	pattern(595,364,635,391,9,BLACK);
}
void Paint::message_box()
{
	pattern(1,415,550,474,1,BLACK);
	setcolor(YELLOW);
	rectangle(1,416,550,474);
	rectangle(1,418,550,471);
	outtextxy(1,425,"MESSAGE BOX : ");
}
void Paint::getMousePos(int *button,int *x,int *y)
{
	i.x.ax=3;
	int86(51,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}
void Paint::color_selector()        //color shades
{
	j=0,inc=1;
	for(k=0;k<8;k++)
	{
		pattern(553,inc,597,inc+30,1,j);
		j++;
		inc+=30;
	}
	inc=1;
	for(k=0;k<8;k++)
	{
		pattern(597,inc,636,inc+30,1,j);
		j++;
		inc+=30;
	}
}
void Paint::tools()
{
	setcolor(BROWN); rectangle(551,0,638,474);
	rectangle(552,1,637,473);
	setcolor(YELLOW);
	rectangle(552,271,636,301);   //size select
	line(580,271,580,301);
	line(608,271,608,301);
	rectangle(552,302,636,332);   //deflt size
	rectangle(552,333,636,362);   //eraser

	input_box();

	rectangle(552,392,636,417); //clear button
	rectangle(552,418,636,445); //circle tool
	line(594,445,594,473);
	line(602,471,630,449);       //line tool
	rectangle(556,449,590,471); //rectangle tool

	//pen width samples
	setfillstyle(1,WHITE);
	fillellipse(566,286,5,5);
	fillellipse(594,286,9,9);
	fillellipse(622,286,13,13);

	//pen width size
	pattern(552,242,637,271,1,BLUE);
	setcolor(YELLOW);
	outtextxy(565,245,"SET PEN");
	outtextxy(573,260,"WIDTH");
	outtextxy(559,309,"INITIAL");
	outtextxy(564,318,"WIDTH");
	outtextxy(559,345,"ERASER");
	outtextxy(560,400,"CLEAR");
	outtextxy(554,431,"CIRCLE");

	//exit button
	pattern(540,1,551,10,1,RED);
	setcolor(15); line(540,1,551,10);
	line(540,10,551,1);

	pattern(1,1,540,10,SOLID_FILL,BLUE);
	pattern(1,1,40,10,SOLID_FILL,DARKGRAY);
	pattern(35,1,40,10,SOLID_FILL,BLUE);
	pattern(41,1,76,10,SOLID_FILL,DARKGRAY);
	setcolor(YELLOW);
	outtextxy(265,2,"PAINT");
	outtextxy(2,2,"SAVE");
	outtextxy(42,2,"OPEN");
}
void Paint::tool_selector(int button,int x,int y,int *pie_size)
{
	if(button==1)
	{
		if((x>=553)&&(x<=597)&&(y>=1)&&(y<=241))	//left column colours
		{
			message_box();
			if((y>=1)&&(y<=31))        { outtextxy(1,425,"MESSAGE BOX : Current Color is BLACK");color=0;  }
			else if((y>=32)&&(y<=61))  { outtextxy(1,425,"MESSAGE BOX : Current Color is BLUE"); color=1;}
			else if((y>=62)&&(y<=91))  { outtextxy(1,425,"MESSAGE BOX : Current Color is GREEN");color=2;}
			else if((y>=92)&&(y<=121)) { outtextxy(1,425,"MESSAGE BOX : Current Color is CYAN"); color=3;}
			else if((y>=122)&&(y<=151)){ outtextxy(1,425,"MESSAGE BOX : Current Color is RED"); color=4;}
			else if((y>=152)&&(y<=181)){ outtextxy(1,425,"MESSAGE BOX : Current Color is MAGENTA");  color=5;}
			else if((y>=182)&&(y<=211)){ outtextxy(1,425,"MESSAGE BOX : Current Color is BROWN");   color=6;}
			else if((y>=212)&&(y<=241)){ outtextxy(1,425,"MESSAGE BOX : Current Color is LIGHT GRAY");    color=7;}
			setcolor(color);
		}
		if((x>=598)&&(x<=636)&&(y>=1)&&(y<=241))       //right column colours
		{
			message_box();
			if((y>=1)&&(y<=31))        { outtextxy(1,425,"MESSAGE BOX : Current Color is DARK GRAY");      color=8;}
			else if((y>=32)&&(y<=61))  { outtextxy(1,425,"MESSAGE BOX : Current Color is LIGHT BLUE"); color=9;}
			else if((y>=62)&&(y<=91))  { outtextxy(1,425,"MESSAGE BOX : Current Color is LIGHT GREEN"); color=10;}
			else if((y>=92)&&(y<=121)) { outtextxy(1,425,"MESSAGE BOX : Current Color is LIGHT CYAN"); color=11;}
			else if((y>=122)&&(y<=151)){ outtextxy(1,425,"MESSAGE BOX : Current Color is LIGHT RED"); color=12;}
			else if((y>=152)&&(y<=181)){ outtextxy(1,425,"MESSAGE BOX : Current Color is LIGHT MAGENTA");  color=13;}
			else if((y>=182)&&(y<=211)){ outtextxy(1,425,"MESSAGE BOX : Current Color is YELLOW");   color=14;}
			else if((y>=212)&&(y<=241)){ outtextxy(1,425,"MESSAGE BOX : Current Color is WHITE");    color=15;}
			setcolor(color);
		}
		else if((x>=540)&&(x<=551)&&(y>=1)&&(y<=10)) //close button
		{
			for(int a=0;a<=638;a++)
			{
				setcolor(BLACK);
				delay(4);
				rectangle(a,1,a,474);
				rectangle(0,a,638,a);
			}
			exit(0);
		}

		//pen width selector
		if((y>=271)&&(y<=301))
		{
			if((x>=552)&&(x<=580))
			{
				*pie_size=5;
				setfillstyle(1,DARKGRAY);
				fillellipse(566,286,5,5);  // <- size=5
				setfillstyle(1,WHITE);
				fillellipse(594,286,9,9);
				fillellipse(622,286,13,13);
			}
			else if((x>=580)&&(x<=608))
			{
				*pie_size=9;
				setfillstyle(1,DARKGRAY);
				fillellipse(594,286,9,9);  // <- size=9
				setfillstyle(1,WHITE);
				fillellipse(566,286,5,5);
				fillellipse(622,286,13,13);
			}
			else if((x>=608)&&(x<=636))
			{
				*pie_size=13;
				setfillstyle(1,WHITE);
				fillellipse(566,286,5,5);  // <- size=5
				fillellipse(594,286,9,9);
				setfillstyle(1,DARKGRAY);
				fillellipse(622,286,13,13);
			}
		}
		if((x>=552)&&(x<=636)&&(y>=302)&&(y<=332))   //set initial width
		{
			*pie_size=2;
			setfillstyle(1,WHITE);
			fillellipse(566,286,5,5);  // <- size=5
			fillellipse(594,286,9,9);
			fillellipse(622,286,13,13);
		}

		//eraser select
		if((x>=552)&&(x<=636)&&(y>=333)&&(y<=363))
		{
			color=WHITE;
			*pie_size=7;

		}

		//clear button
		if((x>=552)&&(x<=636)&&(y>=387)&&(y<=417))
		{
			setfillstyle(SOLID_FILL,WHITE);
			bar(1,11,550,414);
		} //552,424,636,454

		if((x>=1)&&(x<=550)&&(y>=11)&&(y<=414))      //painting
	     //	for(int len=x;len<=x+5;len++)putpixel(len,y,color);
		fillcircle(x,y,*pie_size,color);
		//for(int rad=0;rad<=*pie_size;rad++) circle(x,y,rad);

		//Opening a file
		if((x>=42)&&(x<=76)&&(y>=1)&&(y<=10))
		{
			message_box();
			outtextxy(1,425,"MESSAGE BOX : Enter File Name (max. 5 characters) : ");
			outtextxy(1,438,"MESSAGE BOX : Press Enter to open the file");
			openfile();
		}

		//Saving a file
		if((x>=2)&&(x<=35)&&(y>=1)&&(y<=10))
		{
			message_box();
			outtextxy(1,425,"MESSAGE BOX : Enter File Name (max. 5 characters) : ");
			outtextxy(1,438,"MESSAGE BOX : Press Enter to save the file");
			savefile();
		}
	}
}
void main()
{
	//graph
	int gd=DETECT,gm;
	register int button,x,y;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	//graph initialization

	Paint p1;
	//setting layout of paint
	p1.color_selector();
	p1.tools();
	//setting layout of paint

	//Getting mouse pointer
	i.x.ax=1;
	int86(51,&i,&o);
	//getting mouse pointer

	label:
	outtextxy(1,425,"MESSAGE BOX : Current Color is BLACK");
	int p_s=2,flag=0;
	while(!kbhit())
	{
		//getting mouse position
		p1.getMousePos(&button,&x,&y);
		p1.tool_selector(button,x,y,&p_s);
		if((button==1)&&((x>=552)&&(x<=636)&&(y>=418)&&(y<=445)))
		{
			setcolor(YELLOW);
			flag=1;
			break;
		}
		else if((button==1)&&((x>=552)&&(x<=594)&&(y>=445)&&(y<=474)))
		{
			flag=2;
			break;
		}
		else if((button==1)&&((x>=594)&&(x<=636)&&(y>=445)&&(y<=474)))
		{
			flag=3;
			break;
		}

	}
	if(flag==1)
	{
		p1.draw_circle();
		goto label;
	}
	else if(flag==2)
	{
		p1.draw_shape(1);
		goto label;
	}
	else if(flag==3)
	{
		p1.draw_shape(2);
		goto label;
	}
	for(int a=0;a<=638;a++)
	{
		setcolor(BLACK);
		delay(4);
		rectangle(a,0,a,480);
		rectangle(0,a,638,a);
	}
}

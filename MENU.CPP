#include<iostream.h>
#include<conio.h>
#include<graphics.h>
int gd=9,gm=2;
void menu()                    				//Menu fn
{
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	setcolor(RED);
	settextstyle(2,0,10);
	outtextxy(140,1,"��� DAVE ���");                //Heading
	setcolor(8);
	setfillstyle(9,8);
	bar(272,152,357,127);
	setcolor(BLUE);
	setfillstyle(9,BLUE);
	bar(270,150,355,125);                          //Box 1 (start)
	setcolor(8);
	setfillstyle(9,8);
	bar(272,252,357,227);
	setcolor(BLUE);
	setfillstyle(9,BLUE);
	bar(270,250,355,225);                          //Box 2 (Exit)
	setcolor(7);
	settextstyle(2,0,5);
	outtextxy(295,130,"1.START");
	outtextxy(300,230,"2.EXIT");
}
void exit()
{
	closegraph();
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	setcolor(RED);
	setfillstyle(9,RED);
	bar(100,350,550,150);
	setcolor(BLUE);
	setfillstyle(9,BLUE);
	bar(150,300,500,200);
	setcolor(WHITE);
	settextstyle(2,0,6);
	outtextxy(183,215,"Are you sure you want to exit?");
	setcolor(RED);
	setfillstyle(9,RED);
	bar(203,275,303,250);
	bar(353,275,453,250);
	setcolor(WHITE);
	outtextxy(233,255,"Yes");
	outtextxy(383,255,"No");
}
void choice()
{
int 	ch;
	cin>>ch;
	switch(ch)
	{
	case 1: closegraph();
		break;
	case 2:
		exit();
		break;
	default: setcolor(WHITE);
		 settextstyle(2,0,6);
		 outtextxy(250,550,"Invalid Option");
		 break;
	}
}
void main()
{
	clrscr();
	menu();
	choice();
	getch();
}

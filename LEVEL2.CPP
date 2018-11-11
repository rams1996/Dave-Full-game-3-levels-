#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<bios.h>
#include<stdlib.h>
#include<stdio.h>
struct hscore
{
long int score;
char	name[25];
int	life;
int	level;
int	key;
	hscore()
	{
		score=0;
		life=3;
		level=1;
		key=0;
	}
}ob;

void life_remove(int x, int y)
{
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	pieslice(x,y,0,360,10);
}

void score_bar()
{
	setcolor(15);
	setfillstyle(1,15);
	pieslice(615,20,0,360,10);
	putpixel(617,16,BLACK);
	putpixel(620,9,BLACK);
	putpixel(620,16,BLACK);
	putpixel(621,20,RED);
	pieslice(590,20,0,360,10);
	putpixel(592,16,BLACK);
	putpixel(595,9,BLACK);
	putpixel(595,16,BLACK);
	putpixel(596,20,RED);
	pieslice(565,20,0,360,10);
	putpixel(567,16,BLACK);
	putpixel(570,9,BLACK);
	putpixel(570,16,BLACK);
	putpixel(571,20,RED);
	if(ob.key==1) key(200,20);
	switch(ob.life)
	{
		case 2: life_remove(615,20);
			break;
		case 1: life_remove(615,20);
			life_remove(590,20);
			break;
		case 0: life_remove(615,20);
			life_remove(590,20);
			life_remove(565,20);
			break;
	}
	settextstyle(2,0,5);
	setcolor(WHITE);
	outtextxy(280,10,"LEVEL 1");
	outtextxy(10,10,"SCORE:");
char	sc[25];
	outtextxy(60,10,itoa(ob.score,sc,10));
}
#include<objects.h>
void stage2()
{
	int	 gd=9,gm=2;
	initgraph(&gd,&gm,"");
	cleardevice();
	score_bar();
	setcolor(RED);
	setfillstyle(4,RED);
	bar(0,350,120,310);
	rectangle(0,350,120,310);
	bar(75,280,100,92);
}
void main()
{
  clrscr();
  stage2();
  getch();
}
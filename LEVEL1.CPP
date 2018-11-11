#include<fstream.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<bios.h>
#include<stdio.h>
int 	x=7,gd=9,gm=2,y=272;
struct hscore
{
long int score;
char	name[3];
int	life;
int	level;
int	key;
int	pt;
	hscore()
	{
		score=0;
		life=3;
		level=1;
		key=0;
		pt=0;
	}
	void file_create();
	void file_disp();
	void file_sort();
	void sort_array(hscore *x,int n);
}ob;
void hscore::file_create()
{
	cout<<"Enter Name (3 chars): ";
	cin>>ob.name;
	ofstream f("HSCORE.TXT",ios::app);
	f<<ob.score<<'\t'<<ob.name<<'\n';
	f.close();
}
void hscore::sort_array(hscore *x, int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(x[j].score>x[j+1].score)
			{
				hscore t = x[j];
				x[j]=x[j+1];
				x[j+1]=x[j];
			}
		}
	}
}
void hscore::file_sort()
{
	ifstream f("HSCORE.TXT");
	hscore a[20];
	int i=0;
	f>>a[i].score>>a[i].name;
	while(f.eof()==0)
	{
		i++;
		if(f.eof()==0)f>>a[i].score>>a[i].name;
	}
	f.close();
	sort_array(a,i);
	ofstream g("TEMP.TXT");
	for(int k=0;k<i;k++)
	{
		g<<a[i].score<<"\t"<<a[i].name<<"\n";
	}
	g.close();
	rename("TEMP.TXT","HSCORE.TXT");
	remove("TEMP.TXT");
}
void hscore::file_disp()
{
	cleardevice();
	cout<<"\t\t\tHIGHSCORES\n";
	ifstream f("HSCORE.TXT");
	int i=0;
	while((f.eof()==0)&&(i<10))
	{
		f>>ob.score>>ob.name;
		if(f.eof()==0) cout<<ob.score<<'\t'<<ob.name<<endl;
		i++;
	}
	f.close();
}
#include<objects.h>
void load()
{
	int x=5,y=221;
	cleardevice();
	setcolor(4);
	setfillstyle(6,4);
	bar(0,210,640,170);     		//upper bar
	bar(0,260,640,300);
	dave(x,y);
int	alt=0;
	while(x<634)
	{
		switch(alt)
		{
			case 1: setcolor(WHITE);
				alt=0;
				break;
			case 0: setcolor(BLACK);
				alt=1;
				break;
		}
		settextstyle(2,0,4);
		outtextxy(250,350,"Loading...Please Wait");
		no_dave(x,y);
		x=x+random(50);
		dave(x,y);
		delay(random(500));
	}
	dave(x,y);
	nosound();
}

void life_draw(int x)
{
	setcolor(15);
	setfillstyle(1,15);
	pieslice(x,20,0,360,10);
	putpixel(x+2,16,BLACK);
	putpixel(x+5,9,BLACK);
	putpixel(x+5,16,BLACK);
	putpixel(x+6,20,RED);

}

void score_bar()
{
	if(ob.key==1) key(200,0);
	switch(ob.life)
	{
		case 3: life_draw(615);
			life_draw(590);
			life_draw(565);
			break;
		case 2: life_draw(590);
			life_draw(565);
			break;
		case 1: life_draw(565);
			break;
	}
	settextstyle(2,0,5);
	setcolor(WHITE);
	outtextxy(280,10,"LEVEL 1");
	outtextxy(10,10,"SCORE:");
char	sc[25];
	outtextxy(60,10,itoa(ob.score,sc,10));
}
void remove_sb()
{
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	bar(0,0,640,34);
}
void stage1()
{
	cleardevice();
	score_bar();
	setcolor(RED);
	setfillstyle(4,RED);
	bar(0,350,120,310);		       	   //brick left
	rectangle(0,350,120,310);                  //outline left
	bar(300,480,340,158);                      //wall center
	rectangle(300,480,340,158);		   //wall outline
	bar(640,459,520,424);                      //brick right
	rectangle(640,459,520,424);                //outline right
	bar(170,274,250,234);                      //brick left 2
	rectangle(170,274,250,234);                //outline left 2
	bar(390,272,470,312);                      //brick right 2
	rectangle(390,272,470,312);                //outline right 2
	bar(640,158,520,198);                      //brick up(right)
	rectangle(640,158,520,198);		   //outline up(right)
	setcolor(WHITE);
	line(0,35,640,35);
	points(125,174);
	points(430,212);
	points(227,98);
	points(341,386);
	key(610,125);
	door(607,382);
	setcolor(LIGHTGRAY);
	setfillstyle(6,LIGHTGRAY);
	for(int i=0;i<300;i+=10)                         //spike set 1
	{
		line(i,480,i+5,460);
		line(i+5,460,i+10,480);
		floodfill(i+5,475,LIGHTGRAY);
	}
	for(i=340;i<640;i+=10)
	{
		line(i,480,i+5,460);
		line(i+5,460,i+10,480);
		floodfill(i+5,475,LIGHTGRAY);
	}
}

void level1()
{
int	p1=0,p2=0,p3=0,p4=0;
	clrscr();
int	esc;
	stage1();
//	if(bioskey(1)==0) esc=bioskey(0);
	do
	{
	dave(x,y);
	int	keystr,c;
		if(bioskey(1)==0)
		{
			keystr=bioskey(0);
			switch(keystr)
			{
				case 19712: if((getpixel(x-4,y+38)==4)||(getpixel(x+5,y+38)==4))
						right(x,y);
						else fall_right(x,y);
						if((x>=427)&&(x<=447)&&(y-8==226)&&(p4==0))
						{
							ptremove(430,212);
							ob.score+=100;
							remove_sb();
							score_bar();
							p4=1;
						}
						if((x+3==610)&&(y+38==158))
						{
							key_remove(610,125);
							ob.key=1;
							remove_sb();
							score_bar();
						}
						if((x==387)&&(y+38==462)&&(p3==0))
						{
							ptremove(341,386);
							ob.score+=100;
							remove_sb();
							score_bar();
							p3=0;
						}
						break;
				case 19200: if((getpixel(x-4,y+38)==4)||(getpixel(x+5,y+38)==4))
						left(x,y);
						else fall_left(x,y);
						break;
				case 18432: if(bioskey(1)==0)
						{
							c=bioskey(0);
							switch(c)
							{
								case 19712:if((x<654)&&(y>86))
									   {
										for(int i=0;i<4;i++)
										{
											no_dave(x,y);
											x+=20;
											y-=38;
											dave(x,y);
											if((x>=125)&&(x<=140)&&(y-8==188)&&(p1==0))
											{
												ptremove(125,174);
												ob.score+=100;
												remove_sb();
												score_bar();
												p1=1;
											}
											if((x>=227)&&(x<=242)&&(y-8==112)&&(p2==0))
											{
												ptremove(227,98);
												ob.score+=100;
												remove_sb();
												score_bar();
												p2=1;
											}
											delay(50);
										}
										do
										{
											no_dave(x,y);
											x+=20;
											y+=38;
											dave(x,y);
											if((x>=125)&&(x<=140)&&(y-8==188)&&(p1==0))
											{
												ptremove(125,174);
												ob.score+=100;
												remove_sb();
												score_bar();
												p1=1;
											}
											if((x>=227)&&(x<=242)&&(y-8==112)&&(p2==0))
											{
												ptremove(227,98);
												ob.score+=100;
												remove_sb();
												score_bar();
												p2=1;
											}
											delay(50);
										}while(((getpixel(x-2,y+38)!=4)||(getpixel(x+3,y+38)!=4))&&((y+38)<451));
									   }
									   break;
								case 18432: for(int i=0;i<4;i++)
									    {
										no_dave(x,y);
										if(y>36) y-=38;
										dave(x,y);
										if((x>=227)&&(x<=242)&&(y-8==112)&&(p2==0))
										{
											ptremove(227,98);
											ob.score+=100;
											remove_sb();
											score_bar();
											p2=1;
										}
										delay(50);
									    }
									    for(i=0;i<4;i++)
									    {
										no_dave(x,y);
										y+=38;
										dave(x,y);
										if((x>=227)&&(x<=242)&&(y-8==112)&&(p2==0))
										{
											ptremove(227,98);
											ob.score+=100;
											remove_sb();
											score_bar();
											p2=1;
										}
										delay(50);
									    }

									    break;
								case 19200: up_left(x,y);
										break;
							}
						}
	//			case 283: menu();
			}
		}
		flushall();
		if(y+38==462)
		{
			for(int i=0;i<3;i++)
			{
				dead_dave(x,y);
				delay(100);
				dave(x,y);
				delay(100);
			}
			no_dave(x,y);
			ob.life--;
			x=7;
			y=272;
			remove_sb();
			score_bar();
		}
	}while((check_door(x,y)!=1)&&(ob.life!=0));
	if(ob.life!=0)	load();
	else
	{
		cleardevice();
		setcolor(WHITE);
		outtextxy(100,100,"Thanks for playing");
		for(int td=0;td<5;td++)
			delay(100);
		cleardevice();
		ob.file_create();
		ob.file_sort();
		ob.file_disp();
	}
	getch();
}


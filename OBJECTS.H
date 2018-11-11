int	m,n;
void points(int x,int y)
{
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	bar(x,y,x+14,y+14);
}
void ptremove(int x, int y)
{
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	bar(x,y,x+14,y+14);
}
void get_pt(int	dx,int dy,int px,int py)
{
	if(((dx+3==px-10)||(dx-2==px+10))&&((dy-8==py+10)||(dy+38==py-10)||(getpixel(dx,dy)==4)))
		ptremove(px,py);
		ob.score+=100;
}
void key(int x,int y)
{
	setfillstyle(1,YELLOW);
	bar(x,y,x+4,y+20);                             //key(vertical)
	bar(x,y,x+10,y+4);                             //key(top horiz)
	bar(x+4,y+10,x+7,y+14);                        //key(mid horiz)
	setcolor(YELLOW);
	pieslice(x+2,y+26,0,360,6);                   //key circle 1
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	pieslice(x+2,y+26,0,360,3);                   //key hole
}
void key_remove(int x, int y)
{
	setfillstyle(1,BLACK);
	bar(x,y,x+4,y+20);                             //key(vertical)
	bar(x,y,x+10,y+4);                             //key(top horiz)
	bar(x+4,y+10,x+7,y+14);                        //key(mid horiz)
	pieslice(x+2,y+26,0,360,6);                   //key circle 1
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	pieslice(x+2,y+26,0,360,3);                   //key hole
}
void door(int x,int y)
{
  setcolor(BROWN);
  setfillstyle(1,BROWN);
  bar(x,y,x+30,y+40);
  setcolor(BLACK);
  rectangle(x+5,y+5,x+25,y+15);
  rectangle(x+5,y+35,x+25,y+25);
  setcolor(YELLOW);
  setfillstyle(1,YELLOW);
  pieslice(x+25,y+20,0,360,3);
}
int check_door(int x,int y)
{
	if((ob.key==1)&&(x==607)&&(y+38==424)) return 1;
	else return 0;
}
void dave(int x,int y)
{
	int ERRORCODE =flushall();
	setcolor(15);
	setfillstyle(1,15);
	pieslice(x,y,0,360,8);
	putpixel(x+2,y-4,BLACK);
	ERRORCODE=flushall();
	putpixel(x+5,y+4,BLACK);
	putpixel(x+5,y-4,BLACK);
	putpixel(x+6,y,RED);
	setcolor(11);
	setfillstyle(1,11);
	bar(x-3,y+11,x+4,y+25);
	setcolor(12);
	setfillstyle(1,12);
	bar(x-3,y+26,x-1,y+35);
	bar(x+2,y+26,x+4,y+35);
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	pieslice(x+3,y+35,180,360,2);
	ERRORCODE =flushall();
	pieslice(x-2,y+35,180,360,2);
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	bar(x,y+28,x-1,y+36);
	setcolor(WHITE);
	ERRORCODE=flushall();
	setfillstyle(1,WHITE);
	bar(x,y+10,x+2,y+18);
	bar(x,y+16,x+6,y+18);
	setcolor(6);
	setfillstyle(1,6);
	bar(x,y+10,x+2,y+14);
}
void no_dave(int x, int y)
{
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	pieslice(x,y,0,360,8);
	bar(x-3,y+11,x+4,y+25);
	bar(x-3,y+26,x-1,y+35);
	bar(x+2,y+26,x+4,y+35);
	pieslice(x+3,y+35,180,360,2);
	pieslice(x-2,y+35,180,360,2);
	bar(x,y+28,x-1,y+36);
	bar(x,y+10,x+2,y+18);
	bar(x,y+16,x+6,y+18);
	bar(x,y+10,x+2,y+14);
}
void dead_dave(int x, int y)
{
	setcolor(RED);
	setfillstyle(1,RED);
	pieslice(x,y,0,360,8);
	bar(x-3,y+11,x+4,y+25);
	bar(x-3,y+26,x-1,y+35);
	bar(x+2,y+26,x+4,y+35);
	pieslice(x+3,y+35,180,360,2);
	pieslice(x-2,y+35,180,360,2);
	bar(x,y+28,x-1,y+36);
	bar(x,y+10,x+2,y+18);
	bar(x,y+16,x+6,y+18);
	bar(x,y+10,x+2,y+14);
}
int check_dave(int &x, int &y)
{
	if(y==421)
		{
		       for(int i=0;i<3;i++)
		       {
				dead_dave(x,y);
				no_dave(x,y);
				delay(50);
		       }
		       no_dave(x,y);
		       return 1;
		}
	else return 0;
}
void right(int &x,int &y)
{
	no_dave(x,y);
	if(x<654) x+=20;
	dave(x,y);
}
void left(int &x, int &y)
{
	no_dave(x,y);
	if(x>6) x=x-20;
	dave(x,y);
}
void up(int &x, int &y)
{
	for(int i=0;i<4;i++)
	{
		no_dave(x,y);
		if(y>36) y-=38;
		dave(x,y);
		delay(50);
	}
	for(i=0;i<4;i++)
	{
		no_dave(x,y);
		y+=38;
		dave(x,y);
		delay(50);
	}
}
void up_right(int &x, int &y)
{
	if((x<654)&&(y>86))
	{
		for(int i=0;i<4;i++)
		{
//			no_dave(x,y);
			x+=20;
			y-=38;
			dave(x,y);
			delay(50);
		}
		do
		{
			no_dave(x,y);
			x+=20;
			y+=38;
			dave(x,y);
			delay(50);
		}while(((getpixel(x-2,y+38)!=4)||(getpixel(x+3,y+38)!=4))&&((y+38)<451));
	}
}
void up_left(int &x, int &y)
{
	if((x>0)&&(y>86))
	{
		for(int i=0;i<4;i++)
		{
			no_dave(x,y);
			x-=20;
			y-=38;
			dave(x,y);
			delay(50);
		}
		do
		{
			no_dave(x,y);
			x-=20;
			y+=38;
			dave(x,y);
			delay(50);
		}while(((getpixel(x-2,y+38)!=4)||(getpixel(x+3,y+38)!=4))&&((y+38)<459));
	}
}

void fall_right(int &x, int &y)
{
	do
	{
		no_dave(x,y);
		x+=20;
		y+=38;
		dave(x,y);
		delay(50);
	}while(((getpixel(x-2,y+38)!=4)||(getpixel(x+3,y+38)!=4))&&((y+38)<459));
}
void fall_left(int &x, int &y)
{
	do
	{
		no_dave(x,y);
		x-=20;
		y+=38;
		dave(x,y);
		delay(50);
	}while(((getpixel(x-2,y+38)!=4)||(getpixel(x+3,y+38)!=4))&&((y+38)<459));
}

/*void move(int &x,int &y, int lvl)
{
	dave(x,y);
int	key,c;
	if(bioskey(1)==0)
	{
		key=bioskey(0);
		switch(key)
		{
			case 19712: if((getpixel(x-4,y+38)==4)||(getpixel(x+5,y+38)==4))
					right(x,y);
				    else fall_right(x,y);
				    if(lvl==1) check_key(x,y,600,125);
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
						case 19712: up_right(x,y);
							    break;
						case 18432: up(x,y);
							    break;
						case 19200: up_left(x,y);
							    break;
					}
				    }
//			case 283: menu();
		}
	}
}
*/

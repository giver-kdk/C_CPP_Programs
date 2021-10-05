#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <direct.h>
#include <process.h>
#include <windows.h>

struct time
{
	int wSecond;
	int wMinute;
	int wHour;
};

void frame();
void draw_Numbers(int, int, int);
void line_at_angle(int, float, int);
void beep(int, int);
void clear(int, int, int, int, int);

int main(void)
{
	SYSTEMTIME t;
	int gd = DETECT, gm, errorcode;
	char data[] = "C:\\MINGw\\lib\\libbgi.a";
	struct time i;
	int key, k = 0, x, y, midx, midy, t_sec, t_min, t_hour;
	char tim[5];
	float hour, ang_sec, ang_min, ang_hour;

	initgraph(&gd, &gm, data);
	GetSystemTime(&t);
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	frame();
	while(1)
	{
		if(kbhit())
		{
			key = getch();
			if(key == 27)
			{
				break;
			}
		}
		GetSystemTime(&t);
		if(t.wHour >= 12)
		{
			hour = t.wHour - 12;
		}
		else
		{
			hour = t.wHour;
		}
		ang_sec = t.wSecond * 6;
		ang_min = (t.wMinute * 6) + (ang_sec / 60);
		ang_hour = (hour * 30) + (ang_min / 12);
		setcolor(4);setfillstyle(1, 9);
		circle(midx, midy, 6);
		line_at_angle(150, ang_min, 2);				//Minute
		setcolor(12);
		setfillstyle(1, 4);
		line_at_angle(130, ang_hour, 3);			//Hour
		setcolor(14);
		line_at_angle(170, ang_sec, 1);				//Second
		line_at_angle(20, 180 + ang_sec, 1);		//Second
		setfillstyle(1, 4);
		setcolor(13);
		x = 520, y = 460;
		GetSystemTime(&t);
		if(t.wHour > 12)
		{
			char p[] = "PM";
			outtextxy(x + 80, y, p);
			sprintf(tim, "%d", t.wHour - 12);
		}
		else
		{
			char a[] = "AM";
			outtextxy(x + 80, y, a);
			sprintf(tim, "%d", t.wHour);
		}
		char dash[] = ":";
		outtextxy(x, y, tim);
		outtextxy(x + 16, y, dash);
		outtextxy(x + 42, y, dash);
		sprintf(tim, "%d", t.wMinute);
		outtextxy(x + 26, y, tim);
		sprintf(tim, "%d", t.wSecond);
		outtextxy(x + 50, y, tim);
		k++;
		if(k == 10)
		{
			k = 0;
			beep(100, 50);
		}
		else
		{
			delay(100);
		}
		t_sec = t.wSecond;
		t_min = t.wMinute;
		clear(x + 50, y, x + 70, y + 8, 0);
		if(t_sec > 59)
		{
			clear(x + 26, y, x + 46, y + 8, 0);
		}
		if(t_min > 59)
		{
			clear(x , y, x + 20, y + 8, 0);
		}
		setcolor(0);
		setfillstyle(1, 0);
		line_at_angle(130, ang_hour - 6, 1);
		line_at_angle(150, ang_min - 4, 1);
		line_at_angle(170, ang_sec, 1);
		line_at_angle(20, ang_sec + 180, 1);
		ang_sec++;
	}
	closegraph(0);
	return 0;
  } 
void frame()
{
	int midx, midy, i;
	float angle = 0, x, y;
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	setlinestyle(1, 1, 3);
	setcolor(2);
	circle(midx, midy, 223);
	setcolor(15);
	circle(midx, midy, 220);
	setcolor(12);
	circle(midx, midy, 217);
	setlinestyle(1, 1, 3);
	setfillstyle(1, 2);
	setcolor(4);
	for(i = 0; i <= 60; i++)
	{
		x = cos((angle / 180) * M_PI) * 190;
		y = sin((angle / 180) * M_PI) * 190;
		if((int)angle % 30 != 0)
		{
			circle(midx + x, midy + y, 2);
			angle += 6;
		}
	}
	angle = 0;
	setfillstyle(1, 4);
	setlinestyle(0, 1, 2);
	for(i = 0; i < 12; i++)
	{
		setcolor(13);
		x = cos((angle / 180) * M_PI) *190;
		y = sin((angle / 180) * M_PI) *190;
		setcolor(10);
		draw_Numbers(midx + x, midy + y, i);
		angle += 30;
	}
} 
void line_at_angle(int radius, float angle, int flag)
{
	float x, y, x1, y1, x2, y2, x3, y3;
	int midx, midy;
	int poly1[10];
	angle -= 90;
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	x = cos((angle / 180) * M_PI) * radius;
	y = sin((angle / 180) * M_PI) * radius;
	setlinestyle(0, 1, 3);
	if(flag == 1)
	{
		line(midx, midy, midx + x, midy + y);
	}
	if(flag == 2)
	{
		setlinestyle(0, 1, 1);
		x2 = cos(((angle + 3) / 180) * M_PI) * (radius - 25);
		y2 = sin(((angle + 3) / 180) * M_PI) * (radius - 25);
		x3 = cos(((angle - 3) / 180) * M_PI) * (radius - 25);
		y3 = sin(((angle - 3) / 180) * M_PI) * (radius - 25);

		poly1[0] = midx;
		poly1[0] = midy;
		poly1[0] = midx + x2;
		poly1[0] = midy + y2;
		poly1[0] = midx + x;
		poly1[0] = midy + y;
		poly1[0] = midx + x3;
		poly1[0] = midy + y3;
		poly1[0] = midx;
		poly1[0] = midy;

		fillpoly(5, poly1);
		setcolor(0);
		x2 = cos(((angle) / 180) * M_PI) * (radius + 1);
		y2 = sin(((angle) / 180) * M_PI) * (radius + 1);
		x3 = cos(((angle - 4) / 180) * M_PI) * (radius - 25);
		y3 = sin(((angle - 4) / 180) * M_PI) * (radius - 25);
		line(midx + x2, midy + y2, midx + x3, midy + y3);
		line(midx + x, midy + y, midx + x3, midy + y3);
	}
	else if(flag == 3)
	{
		setlinestyle(0, 1, 1);
		x2 = cos(((angle + 5) / 180) * M_PI) * (radius - 30);
		y2 = sin(((angle + 5) / 180) * M_PI) * (radius - 30);
		x3 = cos(((angle - 5) / 180) * M_PI) * (radius - 30);
		y3 = sin(((angle - 5) / 180) * M_PI) * (radius - 30);

		poly1[0] = midx;
		poly1[0] = midy;
		poly1[0] = midx + x2;
		poly1[0] = midy + y2;
		poly1[0] = midx + x;
		poly1[0] = midy + y;
		poly1[0] = midx + x3;
		poly1[0] = midy + y3;
		poly1[0] = midx;
		poly1[0] = midy;

		fillpoly(5, poly1);
		setcolor(0);
		x2 = cos(((angle) / 180) * M_PI) * (radius + 1);
		y2 = sin(((angle) / 180) * M_PI) * (radius + 1);
		x3 = cos(((angle - 6) / 180) * M_PI) * (radius - 30);
		y3 = sin(((angle - 6) / 180) * M_PI) * (radius - 30);
		line(midx + x2, midy + y2, midx + x3, midy + y3);
		line(midx + x, midy + y, midx + x3, midy + y3);
	}
}
void beep(int fre, int wait)
{
	// sound(fre);
	delay(wait);
	// nosound();
}
void draw_Numbers(int x, int y, int position)
{
	char stpos[5] = " ";
	position += 3;
	if(position > 12)
	{
		position = position % 12;
	}
	itoa(position, stpos, 10);
	outtextxy(x, y, stpos);
}
void clear(int x1, int y1, int x2, int y2, int col)
{
	int x, y;
	for(x = x1; x <= x2; x++)
	{
		for(y =y1; y <= y2; y++)
		{
			putpixel(x, y, col);
		}
	}
}
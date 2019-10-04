# include "graphics.h"
# include "iostream.h"
# include "conio.h"
# include "dos.h"

void evil1();
void evil1clear();
void evil1copy();
void evil2();
void gun();

int x=600,y=200;
int xx=100,yy=200;
int xxx=350,yyy=200;
int ch;
int main()
{	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();
	gun();

	setbkcolor(0);
	while(x!=500)
	{ //      ch=getch();
		evil1();
		delay(50);
		evil1clear();
		x--;
	}

	getch();
	return 0;
}
void gun()
{       setcolor(BLUE);
	setfillstyle(1,BLUE);
	arc(xx,yy,35,325,40);
	line(xx+34,yy-22,xx+74,yy-22);
	line(xx+33,yy+23,xx+74,yy+23);
//	arc(xx-2,yy,-16,16,80);
	floodfill(xx,yy,BLUE);
	setcolor(BROWN);
	circle(xx,yy+40,31);
	circle(xx,yy+40,30);
 /*	arc(xx+30,yy+40,120,240,30);
	arc(xx-30,yy+40,-60,60,30);
	arc(xx,yy+10,210,330,30);
	arc(xx,yy+70,30,150,30);
	arc(xx+15,yy+15,180,240,30);
	arc(xx-15,yy+15,300,360,30);
	arc(xx+15,yy+65,120,180,30);
	arc(xx-15,yy+65,0,60,30);
	putpixel(  */
	setlinestyle(0,0,3);
	line(xx,yy+10,xx,yy+70);
	line(xx+15,yy+15,xx-15,yy+65);
	line(xx-15,yy+15,xx+15,yy+65);
	line(xx+25,yy+24,xx-25,yy+56);
	line(xx-25,yy+24,xx+25,yy+56);
	line(xx-30,yy+40,xx+30,yy+40);
	setlinestyle(0,0,1);
}
void evil2()
{       setcolor(WHITE);
	setfillstyle(1,WHITE);
	arc(xxx,yyy,-28,200,40);
	arc(xxx+60,yyy+33,135,250,30);
	arc(xxx+22,yyy+5,180,295,60);
	floodfill(xxx,yyy,WHITE);
	setcolor(RED);
	setfillstyle(1,BLACK);
	fillellipse(xxx-20,yyy-10,8,14);
	fillellipse(xxx+20,yyy-10,8,14);
	setcolor(WHITE);
	fillellipse(xxx,yyy+20,8,14);
}

void evil1()
{       setcolor(WHITE);
	setfillstyle(1,WHITE);
	ellipse(x,y,-28,210,40,60);
	arc(x-27,y+28,200,330,8);
	arc(x-14,y+36,30,150,8);
	arc(x-1,y+28,200,330,8);
	arc(x+12,y+36,30,150,8);
	arc(x+25,y+28,200,330,8);
	arc(x+38,y+36,110,150,8);
	floodfill(x,y,WHITE);
	setcolor(RED);
	setfillstyle(1,0);
	fillellipse(x-20,y-30,8,13);
	fillellipse(x+20,y-30,8,13);
	setcolor(WHITE);
	fillellipse(x,y,8,13);


}

void evil1clear()
{       setcolor(1);
	setfillstyle(1,1);
	fillellipse(x,y,40,60);
/*	arc(x-27,y+28,200,330,8);
	arc(x-14,y+36,30,150,8);
	arc(x-1,y+28,200,330,8);
	arc(x+12,y+36,30,150,8);
	arc(x+25,y+28,200,330,8);
	arc(x+38,y+36,110,150,8);
	floodfill(x,y,0);
	setcolor(0);
	setfillstyle(1,0);
	fillellipse(x-20,y-30,8,13);
	fillellipse(x+20,y-30,8,13);
	setcolor(0);
	fillellipse(x,y,8,13);
*/

}

void evil1copy()
{       setcolor(WHITE);
	setfillstyle(1,WHITE);
	ellipse(xx,yy,-28,210,40,60);
	arc(xx-27,yy+28,200,330,8);
	arc(xx-14,yy+36,30,150,8);
	arc(xx-1,yy+28,200,330,8);
	arc(xx+12,yy+36,30,150,8);
	arc(xx+25,yy+28,200,330,8);
	arc(xx+38,yy+36,110,150,8);
	floodfill(xx,yy,WHITE);
	setcolor(RED);
	setfillstyle(1,BLACK);
	fillellipse(xx-20,yy-30,8,13);
	fillellipse(xx+20,yy-30,8,13);
	setcolor(WHITE);
	fillellipse(xx,yy,8,13);

	setcolor(RED);
	setfillstyle(1,RED);
	line(xx,yy-45,xx-10,yy-60);
	line(xx,yy-45,xx+10,yy-60);
	line(xx-10,yy-60,xx,yy-100);
	line(xx+10,yy-60,xx,yy-100);
	floodfill(xx,yy-70,RED);
	line(xx-30,yy-40,xx-33,yy-60);
	line(xx-24,yy-50,xx-33,yy-60);
	line(xx-30,yy-40,xx-24,yy-50);
	floodfill(xx-31,yy-52,RED);
	line(xx+30,yy-40,xx+33,yy-60);
	line(xx+24,yy-50,xx+33,yy-60);
	line(xx+30,yy-40,xx+24,yy-50);
	floodfill(xx+31,yy-52,RED);


}
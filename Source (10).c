#include <windows.h>
#include "graphics.h"

void initgraph(); // Graphics' initialization.

void gotoxy(int x, int y);// -move your cursor in position x, y.x and y are in pixels.

void putpixel(int x, int y);// -put pixel with coordinates x and y.

void rectangle(int x1, int y1, int x2, int y2);// -draw rectangle with coordinates(x1, y1) of left top corner and (x2, y2) of right down corner.
//Rectangle will be painted with color.

void circle(int x, int y, int radius);// -draw circle with coordinates of center(x, y) and radius(radius).Circle will be painted with color.

void line(int x1, int y1, int x2, int y2);// -draw line from dote A(x1, y1) to dote B(x2, y2).

void clrscr();// -clear graphics window.

void setcolorRGB(int r, int g, int b);// -change painting color with using RGB palette.

void setcolor(int color);// -change painting color with using default palette(0..15)

void setfontcolor(int color);// -change font color with using default palette(0..15)

void outtextxy(int x, int y, char * text);// -write text(text) with coordinates(x, y), which are in pixels.

int getmaxx();// -return max resolution by width.

int getmaxy();// -return max resolution by height.

void changex(int value);// -move left top corner to right.Can be used to moving left if value < 0. Default value is 0.

void changey(int value);// -move left top corner to down.Can be used to moving top if value < 0. Default value is 30.

int main()
{
	int gd = 0, gm;//gd=graphics driver,gm=graphics mode
	initgraph(&gd, &gm, "");
	//to draw circle
	circle(100, 80, 20);
	getch();
	closegraph();
}









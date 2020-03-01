#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);
void move();

int main()
{
	move();
	getch();
	return 0;
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void move()
{
	int x = 30, y = 10;
	char ch;
	gotoxy(x, y);
	printf("X");
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 27:
			exit(0);
		}
		system("cls");
		gotoxy(x, y);
		printf("X");
	}
}


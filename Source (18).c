#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#define row 17
#define col 33
int x, y;
int a, b;
int X[4] = { 4, 12, 20, 28 };
int Y[4] = { 2, 6, 10, 14 };
void wumpus();
void gotoxy(int x, int y);
void move();
int main()
{

	srand(time(NULL));
	int i, j;
	char grid[row][col];
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {


			if ((i % 4 == 0 && j % 8 == 0))
			{
				grid[i][j] = '+';
			}

			else if (i % 4 == 0)
			{
				grid[i][j] = '-';
			}
			else if (j % 8 == 0)
			{
				grid[i][j] = '|';
			}
			else if (i % 2 == 0 && j % 4 == 0)
			{
				grid[i][j] = '?';
			}
			else
			{
				grid[i][j] = ' ';
			}
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
	wumpus();
	move();
	getch();
	return 0;
}
void wumpus()
{

	do {
		a = rand() % 4;
		b = rand() % 4;
	} while (a == 0 && b == 3);

	gotoxy(X[a], Y[b]);
	printf("W");
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
	int x = 4, y = 14;
	char ch;
	gotoxy(x, y);
	printf("%c", '^');
	do {
		int counter = 1;
		ch = getch();
		switch (ch) {
		case 75:
			gotoxy(x, y);
			printf("%c", ' ');
			if (x != 4)
				x -= 8;
			gotoxy(x, y);
			printf("%c", '<');
			break;
		case 77:
			gotoxy(x, y);
			printf("%c", ' ');
			if (x != 28)
				x += 8;
			gotoxy(x, y);
			printf("%c", '>');
			break;
		case 72:
			gotoxy(x, y);
			printf("%c", ' ');
			if (y != 2)
				y -= 4;
			gotoxy(x, y);
			printf("%c", '^');
			break;
		case 80:
			gotoxy(x, y);
			printf("%c", ' ');
			if (y != 14)
				y += 4;
			gotoxy(x, y);
			printf("%c", 'v');
			break;
		case 27:
			exit(0);
		}

	} while (!(x == X[a] && y == Y[b]));
	gotoxy(x, y);
	printf("\b\bdead");
}

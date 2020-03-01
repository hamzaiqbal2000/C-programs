#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);
void move();
void box();

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
		box();
		ch = getch();
		box();
		switch (ch)
		{
		case 'a':
			x--;
			break;
		case 's':
			x++;
			break;
		case 'w':
			y--;
			break;
		case 'z':
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
void box()
{
	int NUM_ROWS = 4, NUM_COLS = 4, grid[4][4];
	for (int j = 0; j < NUM_ROWS; j++)
	{
		for (int k = 0; k < NUM_COLS; k++)
			printf("[  ]", grid[j][k]);
		printf("\n");
	}
	getch();
	return 0;
}


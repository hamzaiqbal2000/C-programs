#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
//size and scallilng
#define sizex 80
#define sizey 40
#define row (sizey + 1)
#define col (sizex + 1)
//parameters
int attempts = 0;
int win = 0;
int lose = 0;
int show = 0;
//help- start screen
void help();
//random integers
//wumpus
int a, b;
//gold
int m, n;
//holes
int e, f, g, h, k, l, o, p;
char* grid[col][row];

//sizex 64
//sizey 32
// 8 24 40 56		64 
//28 20 12  4		32 

int X[4] = { (sizex / 8), (3 * sizex / 8), (5 * sizex / 8), (7 * sizex / 8) };
int Y[4] = { (7 * sizey / 8), (5 * sizey / 8), (3 * sizey / 8), (sizey / 8) };
void breeze(int, int, int, int);
void stench(int, int, int, int);
void glitter(int, int, int, int, int);
void wumpus(void);
void gold();
void hole1();
void hole2();
void hole3();
void hole4();
void printgrid();
void gotoxy(int x, int y);
void move(int, int, int, int);
void gridnumber();
int main(void)
{
	//code for full screen display
	{

		keybd_event(VK_MENU,
			0x38,
			0,
			0);
		keybd_event(VK_RETURN,
			0x1c,
			0,
			0);
		keybd_event(VK_RETURN,
			0x1c,
			KEYEVENTF_KEYUP,
			0);
		keybd_event(VK_MENU,
			0x38,
			KEYEVENTF_KEYUP,
			0);

	}

	char loop = 0;
	do {

		attempts++;
		system("cls");
		int teer = 1;
		char want = '0';
		char will = '0';
		int goldgrab = 0;
		help();
		Beep(550, 300);
		printgrid();


		{
			gotoxy(120, 38);
			printf("Attempts: %d, Win: %d, Lose: %d", attempts, win, lose);
		}
		gridnumber();
		gold();
		wumpus();
		hole1();
		hole2();
		hole3();
		hole4();
		move(goldgrab, want, will, teer);
		gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 6));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 115);
		printf("'q' to quit");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

		loop = getch();
		if (loop == 'q' || loop == 'Q')
			Beep(550, 300);
	} while (!(loop == 'q' || loop == 'Q'));
}
void printgrid() {
	system("color F0");
	srand(time(NULL));
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {


			if ((i % (sizey / 4) == 0 && j % (sizex / 4) == 0))
			{

				grid[i][j] = "+";
				printf("%s", grid[i][j]);

			}

			else if (i % (sizey / 4) == 0)
			{
				grid[i][j] = "-";

				printf("%s", grid[i][j]);

			}
			else if (j % (sizex / 4) == 0)
			{

				grid[i][j] = "|";
				printf("%s", grid[i][j]);

			}
			else if (i % (sizey / 8) == 0 && j % (sizex / 8) == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
				grid[i][j] = "?";
				printf("%s", grid[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
				grid[i][j] = " ";
				printf("%s", grid[i][j]);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
			}

		}
		printf("\n");
	}
}
void wumpus()
{
	do {
		a = rand() % 4;
		b = rand() % 4;
	} while ((a == 0 && b == 0) || (a == 0 && b == 1) || (X[a] == X[e] && Y[b] == Y[f]) || (X[a] == X[g] && Y[b] == Y[h]) || (X[a] == X[k] && Y[b] == Y[l]) || (X[a] == X[m] && Y[b] == Y[n]) || (X[a] == X[o] && Y[b] == Y[p]));
	grid[X[a]][Y[b]] = "W";
	gotoxy(X[a], Y[b]);
	if (show == 1)
		printf("%s", grid[X[a]][Y[b]]);;
}
// ef, gh, kl, op
void hole1() {
	do {
		e = rand() % 4;
		f = rand() % 4;
	} while ((X[e] == X[0] && Y[f] == Y[0]) || (X[e] == X[0] && Y[f] == Y[1]) || (X[e] == X[3] && Y[f] == Y[0]) || (X[e] == X[0] && Y[f] == Y[3]) || (X[e] == X[1] && Y[f] == Y[2]) || (X[e] == X[a] && Y[f] == Y[b]) || (X[e] == X[m] && Y[f] == Y[n]));
	grid[X[e]][Y[f]] = "*";
	gotoxy(X[e], Y[f]);
	if (show == 1)
		printf("%s", grid[X[e]][Y[f]]);;

}
void hole2() {
	do {
		g = rand() % 4;
		h = rand() % 4;
	} while (X[g] == X[0] && Y[h] == Y[0] || X[g] == X[0] && Y[h] == Y[1] || X[g] == X[3] && Y[h] == Y[0] || X[g] == X[1] && Y[h] == Y[2] || (X[g] == X[a] && h == b) || (X[g] == X[m] && Y[h] == Y[n]));
	grid[X[g]][Y[h]] = "*";
	gotoxy(X[g], Y[h]);
	if (show == 1)
		printf("%s", grid[X[g]][Y[h]]);
}
void hole3() {
	do {
		k = rand() % 4;
		l = rand() % 4;
	} while ((X[k] == X[0] && Y[l] == Y[0]) || (X[k] == X[1] && Y[l] == Y[0]) || (X[k] == X[3] && Y[l] == Y[0]) || (X[k] == X[1] && Y[l] == Y[2]) || (X[k] == X[0] && Y[l] == Y[1]) || (X[k] == X[a] && Y[l] == Y[b]) || (X[k] == X[m] && Y[l] == Y[n]) || (X[k] == X[a] + 2 * (sizex / 8) && Y[l] == Y[b] + 2 * (sizey / 8)));

	grid[X[k]][Y[l]] = "*";
	gotoxy(X[k], Y[l]);
	if (show == 1)
		printf("%s", grid[X[k]][Y[l]]);
}
void hole4() {
	do {
		o = rand() % 4;
		p = rand() % 4;
	} while ((X[o] == X[0] && Y[p] == Y[0]) || (X[o] == X[0] && Y[p] == Y[1]) || (X[o] == X[3] && Y[p] == Y[0]) || (X[o] == X[1] && Y[p] == Y[0]) || (X[o] == X[1] && Y[p] == Y[2]) || (X[o] == X[a] && Y[p] == Y[b]) || (X[o] == X[k] && Y[p] == Y[l]) || (X[o] == X[m] && Y[p] == Y[n]) || (X[o] == X[e] + 2 * (sizex / 8) && Y[p] == Y[f] + 2 * (sizey / 8)));
	grid[X[o]][Y[p]] = "*";
	gotoxy(X[o], Y[p]);
	if (show == 1)
		printf("%s", grid[X[o]][Y[p]]);

}
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void move(goldgrab, want, will, teer)
{
	int x = (sizex / 8), y = (7 * sizey / 8);
	char ch;
	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
	printf("%c", '^');
	do {
		stench(x, y, a, b);
		glitter(x, y, m, n, goldgrab);
		breeze(x, y, e, f);
		breeze(x, y, g, h);
		breeze(x, y, k, l);
		breeze(x, y, o, p);
		if ((x == X[m] && y == Y[n]) && goldgrab == 0) {
			gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8) - 1);
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 230);
				printf("Do you wanna have gold (g||G): ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
				want = getch();
				if (want == 'g' || want == 'G')
				{
					goldgrab++;
					Beep(550, 300);
					gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8));
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 230);
					printf("You have picked up gold\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
				}

			}
		}
		if ((x == sizex / 8 && y == 7 * sizey / 8) && (want == 'g' || want == 'G')) {

			gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8) + 1);
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
				printf("Do you want to terminate (t||T)?:");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

				will = getch();
				if (will == 't' || will == 'T')
				{
					win++;
					Beep(550, 300);
					gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 + 2));
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 207);
					printf("You have escaped\n");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
				}

			}
		}


		HANDLE hStdout;
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		{
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

			ch = getch();
			switch (ch) {
			case 75:
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				printf("%c", ' ');
				if (x != sizex / 8)
					x -= 2 * sizex / 8;
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				printf("%c", '<');

				break;
			case 77:
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				printf("%c", ' ');
				if (x != 7 * sizex / 8)
					x += 2 * sizex / 8;
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				printf("%c", '>');

				break;
			case 72:
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				printf("%c", ' ');
				if (y != sizey / 8)
					y -= 2 * sizey / 8;
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				printf("%c", '^');

				break;
			case 80:
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				printf("%c", ' ');
				if (y != 7 * sizey / 8)
					y += 2 * sizey / 8;
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				printf("%c", 'v');

				break;
			case 27:
				exit(0);
			}
		}
		if ((ch == 'A' || 'S' || 'D' || 'W' || 'a' || 's' || 'd' || 'w') && (teer == 1))
		{
			{
				gotoxy(11 * (sizex / 8), (3 * sizey / 8 - 8)); {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
					printf("Enter choice:");
					gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 7));
					printf("1. D ( -> ) | 2. W ( ^ ) | 3. ( <- ) A | 4. S ( v )");
					if (teer == 1)
						switch (ch) {

						case 'D':
						case 'd':
							if (x + 2 * sizex / 8 == X[a] || x + 4 * sizex / 8 == X[a] || x + 6 * sizex / 8 == X[a])
							{
								a = 4;
								gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 4));
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
								printf("You have killed Wumpus");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

							}
							gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 6));
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
							printf("You have entered D");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
							teer--;
							break;
						case 'W':
						case 'w':
							if (y - 2 * sizey / 8 == Y[b] || y - 4 * sizey / 8 == Y[b] || y - 6 * sizey / 8 == Y[b])
							{
								a = 4;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
								gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 6));
								printf("You have killed Wumpus");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
							}
							gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 4));
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
							printf("You have entered W");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
							teer--;
							break;
						case 'A':
						case 'a':
							if (x - 2 * sizex / 8 == X[a] || x - 4 * sizex / 8 == X[a] || x + 6 * sizex / 8 == X[a])
							{
								a = 4;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
								printf("You have killed Wumpus");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));


							}
							gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 3));
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
							printf("You have entered A");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
							teer--;
							break;
						case 'S':
						case 's':
							if (y + 2 * sizey / 8 == Y[b] || y + 4 * sizey / 8 == Y[b] || y + 6 * sizey / 8 == Y[b])
							{
								a = 4;
								gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 5));
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
								printf("You have killed Wumpus");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

							}
							gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 2));
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
							printf("You have entered S");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
							teer--;
							break;
						}

				}
			}

		}



		if ((x == X[a] && y == Y[b]) || (x == X[e] && y == Y[f]) || (x == X[g] && y == Y[h]) || x == X[k] && y == Y[l] || x == X[o] && y == Y[p])
		{
			lose++;
			if (x == X[a] && y == Y[b]) {
				gotoxy(X[a], Y[b]);
				Beep(550, 300);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				printf("\b\b\bWumpus");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

			}
			if (x == X[e] && y == Y[f]) {
				gotoxy(X[e], Y[f]);
				Beep(550, 300);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("\b\bHole");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

			}

			if (x == X[g] && y == Y[h]) {
				gotoxy(X[g], Y[h]);
				Beep(550, 300);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("\b\bHole");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

			}

			if (x == X[k] && y == Y[l]) {
				gotoxy(X[k], Y[l]);
				Beep(550, 300);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("\b\bHole");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

			}

			if (x == X[o] && y == Y[p]) {
				gotoxy(X[o], Y[p]);
				Beep(550, 300);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("\b\bHole");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

			}
		}
	} while (!((x == X[a] && y == Y[b]) || (x == X[e] && y == Y[f]) || (x == X[g] && y == Y[h]) || (x == X[k] && y == Y[l]) || (x == X[o] && y == Y[p]) || will == 't' || will == 'T'));
}
void gridnumber() {

	gotoxy(9 * sizex / 8, sizey / 8);
	printf("3");
	gotoxy(9 * sizex / 8, 3 * sizey / 8);
	printf("2");
	gotoxy(9 * sizex / 8, 5 * sizey / 8);
	printf("1");
	gotoxy(9 * sizex / 8, 7 * sizey / 8);
	printf("0");

	gotoxy(sizex / 8, 9 * sizey / 8);
	printf("0");
	gotoxy(3 * sizex / 8, 9 * sizey / 8);
	printf("1");
	gotoxy(5 * sizex / 8, 9 * sizey / 8);
	printf("2");
	gotoxy(7 * sizex / 8, 9 * sizey / 8);
	printf("3");
}
void gold() {
	//priority = 1
	do {
		m = rand() % 4;
		n = rand() % 4;
	} while ((m == 0 && n == 0));
	grid[X[m]][Y[n]] = "G";
	gotoxy(X[m], Y[n]);
	if (show == 1)
		printf("%s", grid[X[m]][Y[n]]);

}
void stench(int x, int y, int A, int B) {
	{
		//lower
		if (x == X[A] && y == Y[B] + 2 * sizey / 8)
		{
			gotoxy(X[A] - 3, Y[B] + sizey / 8 + 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			printf("Stench");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
		}
		//upper
		if (x == X[A] && y == Y[B] - 2 * sizey / 8)
		{
			gotoxy(X[A] - 3, Y[B] - 5 * sizey / 16 - 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			printf("Stench");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
		}
		//right
		if (x == X[A] + 2 * sizex / 8 && y == Y[B])
		{
			gotoxy(X[A] - 3 + 2 * sizex / 8, Y[B] - (sizey / 16) - 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			printf("Stench");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
		}
		//left
		if (x == X[A] - 2 * sizex / 8 && y == Y[B])
		{
			gotoxy(X[A] - 2 * sizex / 8 - 3, Y[B] - (sizey / 16) - 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
			printf("Stench");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
		}
	}
}
void glitter(int x, int y, int A, int B, int C) {
	{
		//lower
		if (x == X[A] && y == Y[B] + 2 * sizey / 8 && C == 0)
		{
			gotoxy(X[A] - 9, Y[B] + sizey / 8 + 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
			printf("Glit");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
		}
		//upper
		if (x == X[A] && y == Y[B] - 2 * sizey / 8 && C == 0)
		{
			gotoxy(X[A] - 9, Y[B] - 5 * sizey / 16 - 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
			printf("Glit");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
		}
		//right
		if (x == X[A] + 2 * sizex / 8 && y == Y[B] && C == 0)
		{
			gotoxy(X[A] - 9 + 2 * sizex / 8, Y[B] - (sizey / 16) - 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
			printf("Glit");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
		}
		//left
		if (x == X[A] - 2 * sizex / 8 && y == Y[B] && C == 0)
		{
			gotoxy(X[A] - 2 * sizex / 8 - 9, Y[B] - (sizey / 16) - 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
			printf("Glit");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
		}
	}
}
void breeze(int x, int y, int A, int B) {
	// lower breeze
	if ((x == X[A] && y == Y[B] + 2 * sizey / 8) && !((x == X[a] && y == Y[b]) || (x == X[e] && y == Y[f]) || (x == X[g] && y == Y[h] || (x == X[k] && y == Y[l]) || (x == X[o] && y == Y[p]))))
	{
		gotoxy(X[A] - 3, Y[B] + 3 * sizey / 8 - 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		printf("Breeze");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
	}
	// upper
	if (x == X[A] && y == Y[B] - 2 * sizey / 8 && !((x == X[a] && y == Y[b]) || (x == X[e] && y == Y[f]) || (x == X[g] && y == Y[h] || (x == X[k] && y == Y[l]) || (x == X[o] && y == Y[p]))))
	{
		gotoxy(X[A] - 3, Y[B] - 2 * sizey / 16 - 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		printf("Breeze");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
	}
	// right
	if (x == X[A] + 2 * sizex / 8 && y == Y[B] && !((x == X[a] && y == Y[b]) || (x == X[e] && y == Y[f]) || (x == X[g] && y == Y[h] || (x == X[k] && y == Y[l]) || (x == X[o] && y == Y[p]))))
	{
		gotoxy(X[A] + 2 * sizex / 8 - 3, Y[B] + sizey / 16 + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		printf("Breeze");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
	}
	// left
	if (x == X[A] - 2 * sizex / 8 && y == Y[B] && !((x == X[a] && y == Y[b]) || (x == X[e] && y == Y[f]) || (x == X[g] && y == Y[h] || (x == X[k] && y == Y[l]) || (x == X[o] && y == Y[p]))))
	{
		gotoxy(X[A] - 2 * sizex / 8 - 3, Y[B] + sizey / 16 + 2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		printf("Breeze");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
	}
}
void help() {
	system("color 01");
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(0, 3);		puts("Muhammad Suleman, Fatima Shafqat, Ali Hamza, Hamza Iqbal");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(0, 4);		puts("The Wumpus World");
	gotoxy(0, 14);		puts("Instructions");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(0, 15);		puts("Welcome to the Wumpus World! Your goal is to grab  the gold ,");
	gotoxy(0, 16);		puts("get back to the lower-left square, and climb  out of the cave. You can move around using");
	gotoxy(0, 17);		puts("the turn left , turn right , and go forward buttons.");
	gotoxy(0, 18);		puts("The evil wumpus  is hiding somewhere");
	gotoxy(0, 19);		puts("in the cave. If you enter its square, the wumpus will eat you. The wumpus gives off a terrible");
	gotoxy(0, 20);		puts("stench  that can be detected in adjacent squares. You can kill the wumpus by");
	gotoxy(0, 21);		puts("shooting  the arrow in its direction.");
	gotoxy(0, 22);		puts("There are also bottomless pits  in the cave. If you");
	gotoxy(0, 23);		puts("enter a square");
	gotoxy(0, 24);		puts("with a pit, you fall in, never to be seen again. A breeze can be felt in");
	gotoxy(0, 25);		puts("squares adjacent to ");
	gotoxy(0, 26);		puts("pits.");
	gotoxy(0, 27);		puts("There is only one gold, one wumpus, one arrow, and zero or more");
	gotoxy(0, 28);		puts("pits. There is always a ");
	gotoxy(0, 29);		puts("way to get the gold.");
	gotoxy(0, 30);		puts("Each move costs 1 point. An arrow shot costs");
	gotoxy(0, 31);		puts("an additional 9 points. If");
	gotoxy(0, 32);		puts("you die, you lose 1000 points. The gold is worth 1000 points,");
	gotoxy(0, 33);		puts("if you carry it out of the cave");
	gotoxy(0, 34);		puts("alive.");
	gotoxy(0, 35);		puts("At any time you can start a new game , replay the");
	gotoxy(0, 36);		puts("current game , change options");
	gotoxy(0, 37);		puts("(including world size), or view this information. Happy spelunking!");
	gotoxy(0, 38);		puts("There is only one gold, one wumpus, one arrow, and zero or more");
	gotoxy(0, 39);		puts("pits. There is always a");
	gotoxy(0, 40);		puts("way to get the gold.");
	gotoxy(0, 41);		puts("Each move costs 1 point.An arrow shot costs");
	gotoxy(0, 42);		puts("an additional 9 points.");
	gotoxy(0, 43);		puts("If you die, you lose 1000 points.The gold is worth 1000 points,");
	gotoxy(0, 44);		puts("if you carry it out of the cave");
	gotoxy(0, 45);		puts("alive.");
	gotoxy(0, 46);		puts("At any time you can start a new game, replay the");
	gotoxy(0, 47); 		puts("current game , change options ");
	gotoxy(0, 48);		puts("(including world size), or view this information.");
	gotoxy(0, 49);		puts("Happy\"spelunking!\"");

	getch();
	system("cls");
}
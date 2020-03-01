#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
#define sizex 80
#define sizey 40
#define row (sizey + 1)
#define col (sizex + 1)


int show = 0;
void textcolor(int attr, int fg, int bg);
void help();
int a, b, e, f, g, h, k, l;
int m, n;
int o, p;
char* grid[col][row];
//sizex 32
//sizey 16 
// 4 12 20 28		32
//14 10  6  2		16

// 8 24 40 56		64 
//28 20 12  4		32 

int X[4] = { (sizex / 8) , (3 * sizex / 8) , (5 * sizex / 8), (7 * sizex / 8) };
int Y[4] = { (7 * sizey / 8), (5 * sizey / 8), (3 * sizey / 8), (sizey / 8) };
void breeze(int, int, int, int);
void stench(int, int, int, int);
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
		system("cls");
		int teer = 1;
		char want = '0';
		char will = '0';
		int goldgrab = 0;
		help();
		Beep(550, 300);
		printgrid();
		gridnumber();
		gold();
		wumpus();
		hole1();
		hole2();
		hole3();
		hole4();
		move(goldgrab, want, will, teer);
		gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 6));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
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
	} while ((X[e] == X[0] && Y[f] == Y[0]) || (X[e] == X[0] && Y[f] == Y[1]) || (X[e] == X[0] && Y[f] == Y[3]) || (X[e] == X[1] && Y[f] == Y[2]) || (X[e] == X[a] && Y[f] == Y[b]) || (X[e] == X[m] && Y[f] == Y[n]));
	grid[X[e]][Y[f]] = "*";
	gotoxy(X[e], Y[f]);
	if (show == 1)
		printf("%s", grid[X[e]][Y[f]]);;

}
void hole2() {
	do {
		g = rand() % 4;
		h = rand() % 4;
	} while (X[g] == X[0] && Y[h] == Y[0] || X[g] == X[0] && Y[h] == Y[1] || X[g] == X[1] && Y[h] == Y[2] || (X[g] == X[a] && h == b) || (X[g] == X[m] && Y[h] == Y[n]));
	grid[X[g]][Y[h]] = "*";
	gotoxy(X[g], Y[h]);
	if (show == 1)
		printf("%s", grid[X[g]][Y[h]]);
}
void hole3() {
	do {
		k = rand() % 4;
		l = rand() % 4;
	} while ((X[k] == X[0] && Y[l] == Y[0]) || (X[k] == X[1] && Y[l] == Y[0]) || (X[k] == X[1] && Y[l] == Y[2]) || (X[k] == X[0] && Y[l] == Y[1]) || (X[k] == X[a] && Y[l] == Y[b]) || (X[k] == X[m] && Y[l] == Y[n]) || (X[k] == X[a] + 2 * (sizex / 8) && Y[l] == Y[b] + 2 * (sizey / 8)));

	grid[X[k]][Y[l]] = "*";
	gotoxy(X[k], Y[l]);
	if (show == 1)
		printf("%s", grid[X[k]][Y[l]]);
}
void hole4() {
	do {
		o = rand() % 4;
		p = rand() % 4;
	} while ((X[o] == X[0] && Y[p] == Y[0]) || (X[o] == X[0] && Y[p] == Y[1]) || (X[o] == X[1] && Y[p] == Y[0]) || (X[o] == X[1] && Y[p] == Y[2]) || (X[o] == X[a] && Y[p] == Y[b]) || (X[o] == X[k] && Y[p] == Y[l]) || (X[o] == X[m] && Y[p] == Y[n]) || (X[o] == X[e] + 2 * (sizex / 8) && Y[p] == Y[f] + 2 * (sizey / 8)));
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
	printf("%c", '^');
	do {
		stench(x, y, a, b);
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
				printf("%c", ' ');
				if (x != sizex / 8)
					x -= 2 * sizex / 8;
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
				printf("%c", '<');

				break;
			case 77:
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
				printf("%c", ' ');
				if (x != 7 * sizex / 8)
					x += 2 * sizex / 8;
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
				printf("%c", '>');

				break;
			case 72:
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
				printf("%c", ' ');
				if (y != sizey / 8)
					y -= 2 * sizey / 8;
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
				printf("%c", '^');

				break;
			case 80:
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
				printf("%c", ' ');
				if (y != 7 * sizey / 8)
					y += 2 * sizey / 8;
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
					printf("Enter choice:");
					gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 7));

					printf("1. D ( -> ) | 2. W ( ^ ) | 3. ( <- ) A | 4. S ( v )");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
					switch (ch) {

					case 'D':
					case 'd':
						if (x + 2 * sizex / 8 == X[a] || x + 4 * sizex / 8 == X[a] || x + 6 * sizex / 8 == X[a])
						{
							a = 4;
							teer--;
							gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 5));
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
							printf("You have killed Wumpus");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

						}
						gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 6));
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
						printf("You have entered D");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
						break;
					case 'W':
					case 'w':
						if (y - 2 * sizey / 8 == Y[b] || y - 4 * sizey / 8 == Y[b] || y - 6 * sizey / 8 == Y[b])
						{
							a = 4;
							teer--;
							gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 6));
							printf("You have killed Wumpus");
						}
						gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 4));
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
						printf("You have entered W");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
						break;
					case 'A':
					case 'a':
						if (x - 2 * sizex / 8 == X[a] || x - 4 * sizex / 8 == X[a] || x + 6 * sizex / 8 == X[a])
						{
							a = 4;
							teer--;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
							printf("You have killed Wumpus");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));


						}
						gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 3));
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
						printf("You have entered A");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
						break;
					case 'S':
					case 's':
						if (y + 2 * sizey / 8 == Y[b] || y + 4 * sizey / 8 == Y[b] || y + 6 * sizey / 8 == Y[b])
						{
							a = 4;
							teer--;
							gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 5));
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
							printf("You have killed Wumpus");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));

						}
						gotoxy(11 * (sizex / 8 - 1), (3 * sizey / 8 - 2));
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
						printf("You have entered S");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 + (15 * 16)));
						break;
					}

				}
			}

		}



		if ((x == X[a] && y == Y[b]) || (x == X[e] && y == Y[f]) || (x == X[g] && y == Y[h]) || x == X[k] && y == Y[l] || x == X[o] && y == Y[p])
		{
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
	printf("4");
	gotoxy(9 * sizex / 8, 3 * sizey / 8);
	printf("3");
	gotoxy(9 * sizex / 8, 5 * sizey / 8);
	printf("2");
	gotoxy(9 * sizex / 8, 7 * sizey / 8);
	printf("1");

	gotoxy(sizex / 8, 9 * sizey / 8);
	printf("1");
	gotoxy(3 * sizex / 8, 9 * sizey / 8);
	printf("2");
	gotoxy(5 * sizex / 8, 9 * sizey / 8);
	printf("3");
	gotoxy(7 * sizex / 8, 9 * sizey / 8);
	printf("4");
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
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, 15);
	printf("\nGameplay");
	SetConsoleTextAttribute(hStdout, 12);
	printf("\nThe original text-based version of Hunt the Wumpus uses a command line text interface. A player of the game enters commands to move through the rooms or to shoot \n\"crooked arrows\" along a tunnel into one of the adjoining rooms. There are twenty rooms, each connecting to three others, arranged like the vertices of a \ndodecahedron or the faces of an icosahedron (which are identical in layout). Hazards include bottomless pits, super bats (which drop the player in a random location, \na feature duplicated in later, commercially published adventure games, such as Zork I, Valley of the Minotaur, and Adventure), and the Wumpus itself. The Wumpus is \ndescribed as having sucker feet (to escape the bottomless pits) and being too heavy for a super bat to lift. When the player has deduced from hints which chamber \nthe Wumpus is in without entering the chamber, the player fires an arrow into the Wumpus's chamber to kill it. The player wins the game if the Wumpus is killed.\nHowever, firing the arrow into the wrong");
	printf("chamber startles the Wumpus, which may cause it to move to an adjacent room. The player loses if he or she is in the same \nroom as the Wumpus \n(which then eats him or her) or a bottomless pit (which he or she then falls into).");
	printf("\n");
	SetConsoleTextAttribute(hStdout, 15);
	printf("\nGame elements");
	SetConsoleTextAttribute(hStdout, 12);
	printf("\nYob's original program had these features, while later programs differ here.");
	printf("\n");
	SetConsoleTextAttribute(hStdout, 15);
	printf("\nObjects:");
	SetConsoleTextAttribute(hStdout, 12);
	printf("\n\tWumpus: your target; a beast that eats you if you ever end up in the same room.");
	printf("\n\tSuper Bats (2): creatures that instantly carry you to a random room.");
	printf("\n\tPits (2): fatal to you if you enter the room.");
	printf("\n\tActions: There are two possible actions:");
	printf("\n\tMove: to one of the three rooms connected to your current one.");
	printf("\n\tShoot: fire a \"crooked arrow\" a distance of 1-5 rooms; you must name each room it will reach.");
	printf("\n\tWarning messages: Give you information about the contents of adjacent rooms.");
	printf("\n\tWumpus: \"I smell a wumpus\"");
	printf("\n\tBat: \"Bats nearby\"");
	printf("\n\tPit: \"I feel a draft\"");


	getch();
	system("cls");
}
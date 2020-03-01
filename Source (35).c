#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void player();
void dealer();

char command;
int hole_card;
int z[3];

int main()
{
	srand((unsigned int)time(0));
	player();
	_getche();
	return 0;
}


void player()
{
		
	do{
		char m ='b';
		int a = 0;
		int y[4];
		printf("Player's Hand: ");
		for (int i = 0; i <= 1; i++)
		{
			int a = 0;
			do {
				a = (rand() % 81) + 1;
			} while (!(a == 65 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 74 || a == 75 || a == 81));

			if (a >= 2 && a <= 9)
			{
				printf("%d ", a);
			}
			else if (a >= 65 && a <= 81)
			{
				printf("%c ", a);

			}
			y[i] = a;
		}
		printf("\n");
		dealer();
		printf("\nEnter command:");
		scanf_s(" %c", &command);
		if (command == 'h')
		{
			for (int j = 0;; j++)
			{

				{
					if ((y[0] >= 2 && y[0] <= 9) && (y[1] >= 65 && y[1] <= 81))
						printf("Player's Hand: %d %c ", y[0], y[1]);
					if ((y[0] >= 65 && y[0] <= 81) && (y[1] >= 2 && y[1] <= 9))
						printf("Player's Hand: %c %d ", y[0], y[1]);
					if ((y[0] >= 2 && y[0] <= 9) && (y[1] >= 2 && y[1] <= 9))
						printf("Player's Hand: %d %d ", y[0], y[1]);
					if ((y[0] >= 65 && y[0] <= 81) && (y[1] >= 65 && y[1] <= 81))
						printf("Player's Hand: %c %c ", y[0], y[1]);
				}
				if (j == 0)
				{
					for (int i = 2; i < 3; i++)
					{
						int c = 0;
						do {
							c = (rand() % 81) + 1;
						} while (!(c == 65 || c == 2 || c == 3 || c == 4 || c == 5 || c == 6 || c == 7 || c == 8 || c == 9 || c == 74 || c == 75 || c == 81));

						if (c >= 2 && c <= 9)
						{
							printf("%d ", c);
						}
						else if (c >= 65 && c <= 81)
						{
							printf("%c ", c);

						}
						y[i] = c;
					}
				}
				if (j == 1)
				{
					{
						if (y[2] >= 2 && y[2] <= 9)
						{
							printf("%d ", y[2]);
						}
						else if (y[2] >= 65 && y[2] <= 81)
						{
							printf("%c ", y[2]);
						}
					}

					for (int i = 3; i < 4; i++)
					{
						int d = 0;
						do {
							d = (rand() % 81) + 1;
						} while (!(d == 65 || d == 2 || d == 3 || d == 4 || d == 5 || d == 6 || d == 7 || d == 8 || d == 9 || d == 74 || d == 75 || d == 81));

						if (d >= 2 && d <= 9)
						{
							printf("%d ", d);
						}
						else if (d >= 65 && d <= 81)
						{
							printf("%c ", d);

						}
						y[i] = d;
					}
				}
				{
					if ((z[0] >= 2 && z[0] <= 9) && (z[1] >= 65 && z[1] <= 81))
						printf("\nDealer's Hand: %d %c", z[0], z[1]);
					if ((z[0] >= 65 && z[0] <= 81) && (z[1] >= 2 && z[1] <= 9))
						printf("\nDealer's Hand: %c %d", z[0], z[1]);
					if ((z[0] >= 2 && z[0] <= 9) && (z[1] >= 2 && z[1] <= 9))
						printf("\nDealer's Hand: %d %d", z[0], z[1]);
					if ((z[0] >= 65 && z[0] <= 81) && (z[1] >= 65 && z[1] <= 81))
						printf("\nDealer's Hand: %c %c", z[0], z[1]);
				}
				{
					if (y[0] == 65)
					{
						y[0] = 11;
					}
					if (y[0] == 74 || y[0] == 75 || y[0] == 81)
					{
						y[0] = 10;
					}
				}
				{
					if (y[1] == 65)
					{
						y[1] = 11;
					}
					if (y[1] == 74 || y[1] == 75 || y[1] == 81)
					{
						y[1] = 10;
					}
				}
				{
					if (y[2] == 65)
					{
						y[2] = 11;
					}
					if (y[2] == 74 || y[2] == 75 || y[2] == 81)
					{
						y[2] = 10;
					}
				}
				if (j == 1)
				{
					if (y[3] == 65)
					{
						y[3] = 11;
					}
					if (y[3] == 74 || y[3] == 75 || y[3] == 81)
					{
						y[3] = 10;
					}
				}
				if (j == 0)
				{
					if ((y[0] + y[1] + y[2]) > 21)
					{
						printf("\nPlayer busts");
						break;
					}
					if ((y[0] + y[1] + y[2]) == 21)
					{
						printf("\nPlayer wins");
						break;
					}
				}
				if (j == 1)
				{
					if ((y[0] + y[1] + y[2] + y[3]) > 21)
					{
						printf("\nPlayer busts");
						break;
					}
					if ((y[0] + y[1] + y[2] + y[3]) == 21)
					{
						printf("\nPlayer wins");
						break;
					}
				}

				printf("\nEnter command:");
				scanf_s(" %c", &command);
				if (!(command == 'h'))
					break;

			}
			//printf("\nEnter ’q’ to quit, anything else to play another hand :");
		}
		if (command == 's')
		{
			{
				if ((y[0] >= 2 && y[0] <= 9) && (y[1] >= 65 && y[1] <= 81))
					printf("Player's Hand: %d %c ", y[0], y[1]);
				if ((y[0] >= 65 && y[0] <= 81) && (y[1] >= 2 && y[1] <= 9))
					printf("Player's Hand: %c %d ", y[0], y[1]);
				if ((y[0] >= 2 && y[0] <= 9) && (y[1] >= 2 && y[1] <= 9))
					printf("Player's Hand: %d %d ", y[0], y[1]);
				if ((y[0] >= 65 && y[0] <= 81) && (y[1] >= 65 && y[1] <= 81))
					printf("Player's Hand: %c %c ", y[0], y[1]);
			}

			{
				if ((z[0] >= 2 && z[0] <= 9) && (z[1] >= 65 && z[1] <= 81))
					printf("\nDealer's Hand: %d %c ", z[0], z[1]);
				if ((z[0] >= 65 && z[0] <= 81) && (z[1] >= 2 && z[1] <= 9))
					printf("\nDealer's Hand: %c %d ", z[0], z[1]);
				if ((z[0] >= 2 && z[0] <= 9) && (z[1] >= 2 && z[1] <= 9))
					printf("\nDealer's Hand: %d %d ", z[0], z[1]);
				if ((z[0] >= 65 && z[0] <= 81) && (z[1] >= 65 && z[1] <= 81))
					printf("\nDealer's Hand: %c %c ", z[0], z[1]);
			}
			for (int i = 2; i < 3; i++)
			{
				int e = 0;
				do {
					e = (rand() % 81) + 1;
				} while (!(e == 65 || e == 2 || e == 3 || e == 4 || e == 5 || e == 6 || e == 7 || e == 8 || e == 9 || e == 74 || e == 75 || e == 81));

				if (e >= 2 && e <= 9)
				{
					printf("%d ", e);
				}
				else if (e >= 65 && e <= 81)
				{
					printf("%c ", e);

				}
				z[i] = e;
			}
			{
				if (z[0] == 65)
				{
					z[0] = 11;
				}
				if (z[0] == 74 || z[0] == 75 || z[0] == 81)
				{
					z[0] = 10;
				}
			}
			{
				if (z[1] == 65)
				{
					z[1] = 11;
				}
				if (z[1] == 74 || z[1] == 75 || z[1] == 81)
				{
					z[1] = 10;
				}
			}
			{
				if (z[2] == 65)
				{
					z[2] = 11;
				}
				if (z[2] == 74 || z[2] == 75 || z[2] == 81)
				{
					z[2] = 10;
				}
			}
			{
				if ((z[0] + z[1] + z[2]) < 17)
				{
					printf("\nDealer busts");
					//break;
				}
				if ((z[0] + z[1] + z[2]) > (y[0] + y[1] + y[2]))
				{
					printf("\nDealer wins");
					//break;
				}
			}
		}
		printf("Enter ’q’ to quit, anything else to play another game:");
		scanf_s(" %c", &m);
	}while (m == 'q');
}

void dealer()
{
	printf("Dealer's Hand: ");
	for (int i = 0; i <= 1; i++)
	{
		int b = 0;
		do {
			b = (rand() % 81) + 1;
		} while (!(b == 65 || b == 2 || b == 3 || b == 4 || b == 5 || b == 6 || b == 7 || b == 8 || b == 9 || b == 74 || b == 75 || b == 81));

		if (i == 0)
		{
			if (b >= 2 && b <= 9)
			{
				printf("%d ", b);
			}
			else if (b >= 65 && b <= 81)
			{
				printf("%c ", b);
			}
			z[i] = b;
		}
		if (i == 1)
		{
			z[i] = b;
			printf("X");
		}
	}
}


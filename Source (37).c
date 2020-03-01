#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void player();
void dealer();

char command;
int hole_card;
char m = 'a';
int z;
int i;

int main()
{
	srand((unsigned int)time(0));
	player();
    _getche();
	return 0;
}

void player()
{
	
	{
		char b[2] = { 'a','a' };
		int y[2] = { 0,0 };
		printf("Player's Hand: ");
		for (int i = 0; i <= 1; i++)
		{
			char x = 'a';
			int a = (rand() % 13) + 1;
			
			{
				if (a == 1 || a == 11)
					x = 'A';//A
				if (a == 10)
					x = 'J';//J
				if (a == 12)
					x = 'Q';//Q
				if (a == 13)
					x = 'K';//K
			}

			{
				if (a >= 2 && a <= 9)
				{
					printf("%d ", a);
					y[i] = a;
				}
				else if ((a == 1 || (a >= 10 && a <= 13)))
				{
					printf("%c ", x);
					b[i] = x;
				}
			}
		}
		printf("\n");
		dealer();
		printf("\nEnter command:");
		scanf_s(" %c", &command);
		printf("\n");
		if (command == 'h')
		{
			if (y[0] > 0 && y[1] > 0)
                printf("Player's Hand: %d %d", y[0], y[1]);
			if (y[0] > 0 && b[0] > 'a')
				printf("Player's Hand: %d %c", y[0], b[0]);
			if(y[0] > 0 && b[1] > 'a')
				printf("Player's Hand: %d %c", y[0], b[1]);
			if (y[1] > 0 && b[0] > 'a')
				printf("Player's Hand: %d %c", y[1], b[0]);
			if (y[1] > 0 && b[1] > 'a')
				printf("Player's Hand: %d %c", y[1], b[1]);
			if (b[0] > 'a' && y[0] > 0)
				printf("Player's Hand: %c %d", b[0], y[0]);
			if (b[0] > 'a' && y[1] > 0)
				printf("Player's Hand: %c %d ", b[0], y[1]);
			if (b[0] > 'a' && b[1] > 'a')
				printf("Player's Hand: %c %c", b[0], b[1]);
			if (b[1] > 'a' && y[0] > 0)
				printf("Player's Hand: %c %d", b[1], y[0]);
			if (b[1] > 'a' && y[1] > 0)
				printf("Player's Hand: %c %d", b[1], y[1]);
			



		}
	}
	
}

void dealer()
{
	printf("Dealer's Hand: ");
	for (int i = 1; i <= 2; i++)
	{
		m = 'a';
		z = (rand() % 13) + 1;
		{
			if (z == 1 || z == 11)
				m = 'A';//A
			if (z == 10)
				m = 'J';//J
			if (z == 12)
				m = 'Q';//Q
			if (z == 13)
				m = 'K';//K
		}
		if (i == 1)
		{
			if (z >= 2 && z <= 9)
			{
				printf("%d ", z);
			}
			else if ((z == 1 || (z >= 10 && z <= 13)))
			{
				printf("%c ", m);
			}
		}
		else 
		{
			printf("X");
			if (z >= 2 && z <= 9)
			{
				hole_card = z;
			}
			else if ((z == 1 || (z >= 10 && z <= 13)))
			{
				hole_card = m;
			}
		}
			
	}
}

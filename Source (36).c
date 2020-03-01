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
		int a=0; 
		int y[2];
		printf("Player's Hand: ");
		for (int i = 0; i <= 1; i++)
		{
			int a = 0;
			do {
				a = (rand() % 81) + 1;
			} while(!(a == 65 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 74 || a == 75 || a == 81));

			{
				if (a >= 2 && a <= 9)
				{
					printf("%d ", a);
					y[i] = a;
				}
				else if (a >= 65 && a <= 81)
				{
					printf("%c ", a);
				}
			}
		}
		printf("\n");
		dealer();
		printf("\nEnter command:");
		scanf_s(" %c", &command);
		printf("\n");
		
	}

}

void dealer()
{
	int a = 0;
	printf("Dealer's Hand: ");
	for (int i = 0; i <= 1; i++)
	{
		int a = 0;
		do {
			a = (rand() % 81) + 1;
		} while (!(a == 65 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 74 || a == 75 || a == 81));

		{
			if (a >= 2 && a <= 9)
			{
				printf("%d ", a);
			}
			else if (a >= 65 && a <= 81)
			{
				printf("%c ", a);
			}
		}
	}
		/*else
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
		}*/

	
}
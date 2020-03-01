#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void player();
void dealer();

int main()
{
	player();
	//dealer();
	getch();
	return 0;
}

void player()
{
	srand(time(NULL));
	char x = 'a';
	int y = 1; //(rand() % 13) + 1;
	int z = 10; //(rand() % 13) + 1;
	{
		if (y == 1 || y == 11 || z == 1 || z == 11)
			x = 'A';//A
		if (y == 10 || z == 10)
			x = 'J';//J
		if (y == 12 || z == 12)
			x = 'Q';//Q
		if (y == 13 || z == 13)
			x = 'K';//K
	}
	
	{
		if ((y >= 2 && y <= 9) && (z >= 2 && z <= 9))
		{
			printf("Player's Hand: %d, %d\n", y, z);
		}
		else if ((y == 1 || (y >= 11 && y <= 13)) && (z >= 2 && z <= 9))
		{
			printf("Player's Hand: %c, %d\n", x, z);
		}
		else if ((y == 1 || (y >= 11 && y <= 13)) && (z == 1 || (z >= 11 && z <= 13)))
		{
			printf("Player's Hand: %c, %c\n", x, x);
		}
		else if ((y >= 2 && y <= 9) && (z == 1 || (z >= 11 && z <= 13)))
		{
			printf("Player's Hand: %d, %c\n", y, x);
		}
	}
}

void dealer()
{
	srand(time(NULL));
	char x = 'a';
	int y = (rand() % 13) + 1;
	int z = (rand() % 13) + 1;
	{
		if (y == 1 || y == 11 || z == 1 || z == 11)
			x = 'A';//A
		if (y == 10 || z == 10)
			x = 'J';//J
		if (y == 12 || z == 12)
			x = 'Q';//Q
		if (y == 13 || z == 13)
			x = 'K';//K
	}

	{
		if ((y >= 2 && y <= 9) && (z >= 2 && z <= 9))
		{
			printf("Dealer's Hand: %d, %d", y, z);
		}
		else if ((y == 1 || (y >= 11 && y <= 13)) && (z >= 2 && z <= 9))
		{
			printf("Dealer's Hand: %c, %d", x, z);
		}
		else if ((y == 1 || (y >= 11 && y <= 13)) && (z == 1 || (z >= 11 && z <= 13)))
		{
			printf("Dealer's Hand: %c, %c", x, x);
		}
		else if ((y >= 2 && y <= 9) && (z == 1 || (z >= 11 && z <= 13)))
		{
			printf("Dealer's Hand: %d, %c", y, x);
		}
	}
}
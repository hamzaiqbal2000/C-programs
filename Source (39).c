#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random();

int main()
{
	srand(time(NULL));
	random();
	getch();
	return 0;
}

void random()
{
	for (int i = 0; i < 10; i++)
	{
		int x = (rand() % 6) + 1;
		printf("%2d", x);
	}
}
#include <stdio.h>

int main()
{
	int i,j, isPrime=1;
	for (i = 1; i < 100; ++i)
	{
		isPrime = 1;
		for (j = 2; j <= i / 2; j++)
		{
			if (i%j == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isPrime == 1)
		{
			printf("%d, ", i);
		}
	}
	getch(); 
	return 0;
}
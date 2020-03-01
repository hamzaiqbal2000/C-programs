#include <stdio.h>

int main()
{
	int i=1,n=1, factorial=1;
	
	for (i = 1; i <= 15; ++i)
	{
		for (n = 1; n > 0; --n)
		{
			factorial = factorial * i;
		
		}
		printf("Factorial of %d: %d\n", i, factorial);
	}
	getch();
	return 0;
}
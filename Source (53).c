#include <stdio.h>
int main()
{
	int i = 0;
	scanf_s("%d", &i);
    while (i <= 100)
	{
		printf("%d ASCII value of %c\n", i, i);
		i++;
	}
	getch();
	return 0;
}
#include <stdio.h>

int main()
{
	int i,n, current_num, next_num;
	printf("Please enter the number:");
	scanf_s("%d", &i);

	for (n = 1; n <= i; n++)
	{
		current_num = n;
		next_num = n;

		printf("%d %d\n", current_num, next_num);
		printf("%d %d", current_num, next_num);

		current_num = current_num + next_num;
		
		printf(" %d\n", current_num);

	}
	getch();
	return 0;
}
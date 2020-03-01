#include <stdio.h>

void reverse();

int main()
{
	reverse();
	getch();
	return 0;
}
void reverse()
{
	int num,A[100],i;
	printf("Enter the Number of value you want to type:");
	scanf_s("%d", &num);
	printf("Enter the Numbers: ");
	for (i = 0; i < num; i++)
		scanf_s("%d", &A[i]);
	printf("The Numbers in reverse order are: ");
	for (i = (num - 1); i >= 0; i--)
		printf("%d ",A[i]);
}
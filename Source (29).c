#include <stdio.h>

int main()
{
	int A[3][3], B[3][3], C[3][3], i, j;

	printf("Enter 9 numbers for First Matrix: ");
	for (i = 0; i <= 2; i++)
		for (j = 0; j <= 2; j++)
		{
			scanf_s("%d", &A[i][j]);
		}

	printf("Enter 9 numbers for Second Matrix: ");
	for (i = 0; i <= 2; i++)
		for (j = 0; j <= 2; j++)
		{
			scanf_s("%d", &B[i][j]);
		}

	printf("Sum of two matrixes is\n ");
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
			printf("%3d", C[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}
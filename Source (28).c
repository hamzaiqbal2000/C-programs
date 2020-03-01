#include <stdio.h>

void matrix();

int main()
{
	matrix();
	getch();
	return 0;
}

void matrix()
{
	int A[3][3], B[3][3], C[3][3],i,j;
	printf("Enter 9 numbers for the first matrix(row wise): ");
	for(i=0;i<=2;i++)
		for (j = 0; j <= 2; j++)
			scanf_s("%d", &A[i][j]);

	printf("Enter 9 numbers for the Second matrix(row wise): ");
	for (i = 0; i <= 2; i++)
		for (j = 0; j <= 2; j++)
			scanf_s("%d", &B[i][j]);

	printf("Multiplication of two Matrixes is:\n");
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			C[i][j] = (A[i][0] * B[0][j]) + (A[i][1] * B[1][j]) + (A[i][2] * B[2][j]);
			printf("%3d ", C[i][j]);
		}
		printf("\n");
	}
}
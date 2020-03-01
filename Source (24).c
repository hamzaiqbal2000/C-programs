#include <stdio.h>

void duplicate();

int main()
{
	duplicate();
	getch();
	return 0;
}

void duplicate()
{
	int num,A[100],i,j,k,B[100],m=0;
	printf("Input how many numbers you want to type:");
	scanf_s("%d", &num);
	printf("Enter the numbers:");
	for (i = 0; i < num; i++)
		scanf_s("%d",&A[i]);

	for (i = 0; i < num; i++)
		B[i] = A[i];

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < i; j++) 
		{
			if (A[i] == B[j])
				m++;
		}
		for(k=i+1;k<num;k++)
		{
			if (A[i] == A[k])
			{
				m++;
			}

		}
		if (m == 0)
			printf("\nUNIQUE ELEMENT:%d", A[i]);
	}
}
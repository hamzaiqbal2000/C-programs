//average
#include <stdio.h>

void average(int *p);
void largest(int *p);

int main()
{
	int a[] = { 1,2,3,4,5 };
	average(a);
	largest(a);
	getch();
	return 0;
}
void average(int *p)
{
	int sum=0,avg;
	for (int i = 0; i < 5; i++) {
		sum = sum + *(p + i);
	}
	avg = sum / 5;
	printf("Average:%d", avg);
}
void largest(int *p)
{
	int max = *p;
	for (int i = 0; i < 5; i++) {
		if (max < *(p + i))
			max = *(p + i);
	}
	printf("\nLargest:%d", max);
}
//recursive function prints an array
#include <stdio.h>

void printArray(int x[], int y,int z);
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	printf("Elements in array are\n");
	printArray(a, 0, 9);
	getch();
	return 0;
}
void printArray(int x[], int y,int z)
{
	//recursion base condition
	if (y >= z)
		return;
	//printing the current array element
	printf("%d", x[y]);
	//recursively cally printarray to print next element
	printArray(x, y + 1, z);
	
}
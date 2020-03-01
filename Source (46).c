//Reversing Digits
#include <stdio.h>

int reverse(int x);

int main()
{
	int num;
	printf("Write down a any number: ");
	scanf_s("%d", &num);
	printf("The reverse is %d",reverse(num));

	getch();
	return 0;
}

int reverse(int x)
{//7631
	int t, u, v, w, y, z,rev;
	y = x / 1000;//7
	z = x % 1000;//631
	w = z / 100;////6
	u = z % 100;//31
	v = u / 10;//3
	t = u % 10;//1

	rev = (t * 1000) + (v * 100) + (w * 10) + (y * 1);
	return rev;
}




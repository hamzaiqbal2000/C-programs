//Rounding Numbers
#include <stdio.h>
#include <math.h>

double floor(double x);



int main()
{
	float num;
	printf("Write the numbers you want to round to nearest:");
	scanf_s("%f", &num);
	printf("%.2f round off to %.2f", num, floor(num));

	getch();
	return 0;

}

/*double floor(double x)
{
	double y;
	y = floor(x + .5);
	return y;
}*/
#include <stdio.h>

float Area(int x);
#define PIE 3.14285
int main()
{
	int radius;
	float area;
	printf("Enter the radius of the circle");
	scanf_s("%d", &radius);
	area = Area(radius);
	printf("Area of circle is %.2f", area);
	getch();
	return 0;

}

float Area(int x)
{
	int A = PIE * x*x;
	return A;
}
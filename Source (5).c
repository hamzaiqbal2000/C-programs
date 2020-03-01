#include <stdio.h>

int main()
{
	int greatest=0,m[6];
	int a[] = { 1,2,-5,4,-3,2 };
	for (int i = 0; i < 6; i++) {
		int s1 = 0,max = 0;
		for (int j = i; j < 6; j++) {
			s1 = s1 + a[j];
			if (s1 > max) {
				max = s1;
			}
		}
		m[i] = max;
		
	}
	for (int i = 0; i < 6; i++) {
		if (m[i] > greatest)
			greatest = m[i];
	}
	printf("%d", greatest);
	getch();
	return 0;
}
/*int main()
{
	int a[] = { 1,2,-5,4,-3,2 };
	int result=max_sum(a, 6);
	printf("%d", result);
	getch();
	return 0;
}
int max_sum(int *vector, int len)
{
	int best = 0, current = 0;
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		current += *(vector + i);
		if (current < 0)
		{
			current = 0;
		}
		best = best > current ? best : current;
	}
	return best;
}*/
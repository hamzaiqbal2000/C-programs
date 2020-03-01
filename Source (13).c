#include <stdio.h>

void printgrid();
#define sizey 40
#define sizex 80
#define row (sizey+1)
#define col (sizex+1)
char *grid[row][col];

int main()
{
	printgrid();
	getch();
	return 0;
}

void printgrid()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i % (sizey / 4) == 0 && j % (sizex / 4) == 0)
				grid[i][j] = '+';
			else if (i % (sizey / 4) == 0)
				grid[i][j] = '-';
			else if (j % (sizex / 4) == 0)
				grid[i][j] = '|';
			else
				grid[i][j] = ' ';
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}
#include <stdio.h>

int main()
{
	int j,curr_num=1, nxt_num=1, pre_num=0;
	
		printf("%d ", pre_num);
		printf("%d ", curr_num);
		for (j = 1; j <= 20; j++)
		{
	        nxt_num = pre_num + curr_num;
			
			printf("%d ", nxt_num);
			pre_num = curr_num;
		    curr_num = nxt_num;
		}
	getch();
	return 0;
}
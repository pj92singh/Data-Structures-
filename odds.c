#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//practise for interview questions
	//print all odd numbers
	//up to 100
	int i, j, count=0; 
	int odd[50];
	for (int i = 1; i < 100; i+=2)
	{

			odd[j] = i;
			printf("%d\t", odd[j]); 
			j++;
			count++;
	
	}
	printf("\n\nThe count\n %d\n", count);
	printf("\n");


	printf("--------------------\n Mod question!\n");
	for (int j = 0; j < 50; ++j)
	{
		if (j % 3==0 && j % 5 ==0)
		{
			printf("\n%d\n",j);
			printf("Coolz AND Great\n");
		}
		else if (j % 3 == 0)
		{
			printf("\n%d\n",j);
			printf("Coolz\n");
		}
		else if (j % 5== 0)
		{
			printf("\n%d\n",j);
			printf("Great\n");
		}
	}

	return 0;
}
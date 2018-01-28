#include<stdio.h>
int main()
{
	int i;
	int h = 1;
	int n = 1;
	int num = 0;
	scanf("%d",&i);
	
	while(i != 0)
	{
		if((i + n) % 2 == 0)
		{
		num = h + num;
		}
	h *= 2;
	i /= 10;
	n++;
	}
	printf("%d",num);
	return 0;
 } 

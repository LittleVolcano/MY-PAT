#include<stdio.h>
int main()
{
	int i;
	int count1 = 0;
	int count2 = 0;
	scanf("%d",&i);
	while(i != -1)
	{
		
		if(i % 2 == 1)
		{count1++;
		}
		else
		{count2++;
		}
		scanf("%d",&i);
	}
	printf("%d %d",count1,count2);
	return 0;
 } 

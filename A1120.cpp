
#include<stdio.h>

int main()
{
	int a[50] = {0};
	int n;
	int temp;
	int friid;
	int sum = 0;
	int flag = 0;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i)
	{
		friid = 0;
		scanf("%d",&temp);
		while(temp != 0)
		{
			friid += temp % 10;
			temp /= 10;
		}
		a[friid]++;
	}
	for(int i = 0;i < 50; ++i)
	{
		if(a[i] != 0 )
			++sum;
	}
	printf("%d\n",sum);
	for(int i = 0;i < 50; ++i)
	{
		
		if(a[i] != 0 )
		{
			if(flag == 1)
				printf(" ");
			printf("%d",i);
			flag = 1;
		}
	}
	return 0;
}


#include<stdio.h>
int isWANSHU(int x);
int main()
{
	int i;
	int m, n;
	int count = 0;
	scanf("%d %d", &n, &m); 
	for(i = n; i <= m; i++)//遍历n到m之间所有数，并把其中的完数输出 
	{
		if(isWANSHU(i) == 1)
		{
			if(count != 0)
			{
				printf(" ");
			}
			printf("%d",i);
			count += 1;
		}

	}
	if(count == 0)//一个都没有的话要输出NIL回车 
	{
		printf("NIL\n");
	}
	
	return 0;
}

int isWANSHU(int x)//判断是否是完数 
{
	int i;
	int j = x;
	int count = 0;
	int ret = 0;
	for(i = 1; i < x; i++)
	{
		if(x % i == 0)
		{
			count += i;
		}
	}
	if(count == j)
	{
		ret = 1;
	}
	return ret;
 } 

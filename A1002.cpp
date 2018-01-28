#include<stdio.h>
int main()
{
	int exp, k, i, max = 0, count = 0;
	double coe, a[1001] = {0};
	for(i = 0; i < 2; i++)//in and calculate
	{
		scanf("%d", &k);
		while(k--)
		{
			scanf("%d%lf", &exp, &coe);//double 必须用lf   float用f   一定注意类型的匹配   这里控制符前有没有空格都可以 
			a[exp] += coe;
			if(exp > max)//maxindex
			{
				max = exp;
			}
		}

	}
	for(i = max ; i >= 0; i--)//calculate number
	{
		if(a[i] != 0)
		{
			++count;
		}
		
	}
	printf("%d", count);
	for(i = max; i >= 0; i--)
	{
		if(a[i] != 0)
		{
			printf(" %d %.1lf", i, a[i]);
		}
	}
	

	return 0;
 } 

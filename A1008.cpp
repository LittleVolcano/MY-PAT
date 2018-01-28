#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,k,i;
	int sum = 0;
	int L[110];
	L[0] = 0;
	scanf("%d",&n);


	for(i = 1; i <= n; ++i)
		{
			scanf("%d",&L[i]);//牢记输入函数赋值在里边，别再在前边加L【i】 = 
	    }
	for(i = 0; i <= n - 1; ++ i)
	{
		if(L[i] > L[i + 1])//下楼
		{
		k = L[i] - L[i + 1];
		sum += 4 * k;
		}
		else if(L[i+1] > L[i])//上楼
		{
		k = L[i + 1] - L[i];
		sum += 6 * k;
		}
		

	}
	sum += 5 * n;
	printf("%d\n", sum);//PAT每个数据用\n换行

}

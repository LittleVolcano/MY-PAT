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
			scanf("%d",&L[i]);//�μ����뺯����ֵ����ߣ�������ǰ�߼�L��i�� = 
	    }
	for(i = 0; i <= n - 1; ++ i)
	{
		if(L[i] > L[i + 1])//��¥
		{
		k = L[i] - L[i + 1];
		sum += 4 * k;
		}
		else if(L[i+1] > L[i])//��¥
		{
		k = L[i + 1] - L[i];
		sum += 6 * k;
		}
		

	}
	sum += 5 * n;
	printf("%d\n", sum);//PATÿ��������\n����

}

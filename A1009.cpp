
#include <stdio.h>
/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5
*/

int main()
{
	int n,m,i,j,exp,num=0;
	double cof;
	double a[1001];
	double b[2001];//����û������
	for(i = 0;i <= 1000; ++i)
		a[i] = 0.0;
	for(i = 0;i <= 2000; ++i)
		b[i] = 0.0;


	scanf("%d",&n);
	for(i = 1 ;i <= n; ++i)//�����һ������ʽ����a��
	{	
		scanf("%d %lf",&exp,&cof);
		a[exp] = cof;
	}
	scanf("%d",&m);
	for(i = 1; i <= m; ++i)//����ڶ�������ʽ��ÿ����һ�����������һ�飬�������b��
	{	
		scanf("%d %lf",&exp,&cof);
		for(j = 0;j <= 1000; ++j)
		{
			b[j + exp] += a[j] * cof;		
		}
	}
	for(i = 0;i <= 2000; ++i)//�����ж�����
		if(b[i] != 0.0)
			++num;
	printf("%d",num);
	for(i = 2000;i >= 0; --i)//���
		if(b[i] != 0.0)
			printf(" %d %.1f",i,b[i]);
	
	return 0;
}


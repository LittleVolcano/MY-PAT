
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
	double b[2001];//这有没有问题
	for(i = 0;i <= 1000; ++i)
		a[i] = 0.0;
	for(i = 0;i <= 2000; ++i)
		b[i] = 0.0;


	scanf("%d",&n);
	for(i = 1 ;i <= n; ++i)//输入第一个多项式存在a中
	{	
		scanf("%d %lf",&exp,&cof);
		a[exp] = cof;
	}
	scanf("%d",&m);
	for(i = 1; i <= m; ++i)//输入第二个多项式，每输入一项，都遍历运算一遍，结果存在b中
	{	
		scanf("%d %lf",&exp,&cof);
		for(j = 0;j <= 1000; ++j)
		{
			b[j + exp] += a[j] * cof;		
		}
	}
	for(i = 0;i <= 2000; ++i)//计算有多少项
		if(b[i] != 0.0)
			++num;
	printf("%d",num);
	for(i = 2000;i >= 0; --i)//输出
		if(b[i] != 0.0)
			printf(" %d %.1f",i,b[i]);
	
	return 0;
}


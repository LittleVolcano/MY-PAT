#include<stdio.h>
int main()
{
	int count = 1;//计数控制在nm中间 
	int num = 0;//素数求和 
	int i;//用来检查的数 
	int x;//正在检查的数 
	int n, m;
	int temp = 1;
	scanf("%d %d",&n,&m);
if(n == 1)
{
	num = 2;
}
for(x = 3;count < m; x++)
{
	for(i = 2;i < x; i++)
	{
		if(x % i == 0)
		{
		temp = 0;
		break;

		}
	}
	if(temp ==1)//是素数 
	{
		count++; //素数个数加一 
		if(count >= n)
		{
			num += x;
		}
	}
	temp = 1;
	
}

	
 printf("%d", num);
	return 0;
}

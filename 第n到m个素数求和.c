#include<stdio.h>
int main()
{
	int count = 1;//����������nm�м� 
	int num = 0;//������� 
	int i;//���������� 
	int x;//���ڼ����� 
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
	if(temp ==1)//������ 
	{
		count++; //����������һ 
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

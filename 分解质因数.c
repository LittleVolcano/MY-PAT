#include<stdio.h>
int isPrime(int x);
int main()
{
	int x;
	scanf("%d",&x); 
	if(isPrime(x) == 1)//������ 
	{
		printf("%d=%d", x, x);
	}
	else//�������� ���ֽ������� 
	{
		int a;
		printf("%d=", x);
		while(isPrime(x) == 0)
		{
		
			for(a = 2;a < x; a++)
			{
				if(x % a == 0)
				{
					printf("%dx", a);
					break;
				}
			}
			x = x / a;
			if(isPrime(x) == 1)
			{
				printf("%d",x);
			}
		}
		
		
		
	}
	
	return 0;
}

int isPrime(int x)
{
	int i;
	int ret = 1;
	for(i = 2; i < x; i++)
	{
		if(x % i == 0)
		{
			ret = 0;
		}
	}
	return ret;
 } 
//������������������������� ���顱�� 
//���ڶ����������������ڵĿ����ӿ����ã����������У����ڿ����кͿ��������ı���ʱ�����ڿ�ִ��ʱ�ñ��������ǣ�ִ�������������ʱ�����ڿ�ĸ��Ǿ���Ч�ˡ� 

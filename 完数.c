#include<stdio.h>
int isWANSHU(int x);
int main()
{
	int i;
	int m, n;
	int count = 0;
	scanf("%d %d", &n, &m); 
	for(i = n; i <= m; i++)//����n��m֮�����������������е�������� 
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
	if(count == 0)//һ����û�еĻ�Ҫ���NIL�س� 
	{
		printf("NIL\n");
	}
	
	return 0;
}

int isWANSHU(int x)//�ж��Ƿ������� 
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

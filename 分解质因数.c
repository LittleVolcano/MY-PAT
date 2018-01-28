#include<stdio.h>
int isPrime(int x);
int main()
{
	int x;
	scanf("%d",&x); 
	if(isPrime(x) == 1)//是素数 
	{
		printf("%d=%d", x, x);
	}
	else//不是素数 ，分解质因数 
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
//变量的生存期是在这个函数的 “块”内 
//块内定义变量，在这个块内的块内扔可以用，反过来不行；块内块中有和块内重名的变量时，块内块执行时该变量被覆盖，执行完出来到块内时，块内块的覆盖就无效了。 

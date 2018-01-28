
#include <stdio.h>
#include <cmath>

//int isprime(int n)
//{
//	if(n <= 1) 
//		return 0;
//	int sqr = (int) sqrt( 1.0 * n );
//	for(int i = 2; i <= sqr; ++i)
//		if( n % i == 0 )
//			return 0;
//	return 1;
//
//}
int isprime(int n)
{
	if(n <= 1)
		return 0;
	int sqr = (int) sqrt(1.0 * n);
	for(int i = 2; i <= sqr; ++i)
		if(n % i == 0)
			return 0;
	return 1;
}
int d[111];
int main()
{
	int n,radix;
	while(scanf("%d",&n) != EOF )
	{
		if(n < 0)
			break;
		scanf("%d",&radix);
		if(isprime(n)==0)
			printf("No\n");
		else
		{
			int len = 0;
			do
			{
				d[len++] = n % radix;
				n /= radix;
			}while(n != 0);
			for(int i = 0;i < len;++i)
			{
				n = n * radix + d[i];
			}
			if(isprime(n) == 0)
				printf("No\n");
			else printf("Yes\n");
		}
	}

/*

	int n, radix;
	while(scanf("%d",&n) != EOF)
	{
		if(n < 0)break;
		scanf("%d",&radix);
		if(isprime(n) == 0)
			printf("No\n");
		else
		{
			int len = 0;
			do
			{
				d[len++] = n % radix;
				n /= radix;

			}while(n != 0);
			for(int i = 0;i < len;++i)
			{
				n = n * radix + d[i];
			}
			if(isprime(n) == 0)
			{
				printf("No\n");
			}
			else
				printf("Yes\n");
		}




	}*/

	return 0;
}


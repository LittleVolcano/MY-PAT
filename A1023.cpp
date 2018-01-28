#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	long long int num;
	int a[21],b[21];
	int len1 = 0;
	scanf("%ld",&num);
	long long int temp = 2 * num;
	long long int temp2 = temp;
	do
	{
		a[len1++] = num % 10;
		num /= 10;
	}while(num != 0);
	int len2 = 0;
	do
	{
		a[len2++] = temp % 10;
		temp /= 10;
	}while(temp != 0);
	if(len1 != len2)
	{
		printf("No\n");
		printf("%ld\n",temp2);
	}
	else
	{
		sort(a,a+len1);
		sort(b,b+len1);
		for(int i = 0;i < len1;++i )
		{
			if(a[i] != b[i])
			{
				printf("No\n");
				printf("%ld\n",temp2);
				return 0;
			}
		}
		printf("Yes\n");
		printf("%ld\n",temp2);
	}

	return 0;
}


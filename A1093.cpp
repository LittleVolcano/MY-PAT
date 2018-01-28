
#include <algorithm>
#include<stdio.h>
#include <cstring>
using namespace std;
char str[100010];

int main()
{
	int countp[100010];
	int len;
	int num=0;
	long long ans = 0;
	gets(str);
	len = strlen(str);
	for(int i = 0;i < len; ++i)
	{
		if(str[i] == 'P')
		{
			countp[i+1] = countp[i]+1;
			num++;
		}
		else countp[i+1] = countp[i];
	}
	num = 0;
	for(int i = len-1;i > 0;--i)
	{
		
		if(str[i] == 'T')
			num++;
		if(str[i] == 'A')
			ans += countp[i] * num;
	}
	printf("%ld",ans%1000000007);
	return 0;
}


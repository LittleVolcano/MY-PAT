
#include <cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct bign
{
	int d[21];
	int len;
	bign()
	{
		memset(d,0,sizeof(d));
		len = 0;
	}
};
bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0;i < a.len; ++i)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}
bign multi(bign a,int b)
{
	bign c;
	int carry = 0;
	for(int i = 0;i < a.len; ++i)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c ;
}
int judge(bign a,bign b)
{
	sort(a.d,a.d + a.len);
	sort(b.d,b.d + b.len);
	if(a.len != b.len)
		return 0;
	else
	{
		for(int i=0;i<a.len;++i)
			if(a.d[i] != b.d[i])
				return 0;
		return 1;
	}
}
void print(bign a)
{
	for(int i = a.len -1;i >= 0;--i)
		printf("%d",a.d[i]);
}

int main()
{
	char str[21];
	gets(str);
	bign a = change(str);
	bign b = multi(a,2);
	if(judge(a,b)==0)
	{
		printf("No\n");
		print(b);
	}
	else
	{
		printf("Yes\n");
		print(b);
	}
	return 0;
}


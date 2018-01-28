
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct Mooncake
{
	double kucun;
	double summoney;
	double price;
}cake[1010];
bool cmp(Mooncake a, Mooncake b)
{
	return a.price > b.price;
}
int main()
{
	int n;
	double d;//把d定义为double后边计算方便
	double sumkucun = 0;
	double ans = 0;
	scanf("%d%lf",&n, &d);
	for(int i = 0;i < n; ++i)
	{
		scanf("%lf",&cake[i].kucun);
	/*	sumkucun += cake[i].kucun;*/
	}
	for(int i = 0;i < n; ++i)
	{
		scanf("%lf",&cake[i].summoney);
		cake[i].price = cake[i].summoney / cake[i].kucun;
	}
	sort(cake,cake + n, cmp);
	for(int i = 0;i < n; ++i)
	{
		if(d > cake[i].kucun)
		{
			d -= cake[i].kucun;
			ans += cake[i].summoney;
		}
		else 
		{
			ans += d * cake[i].price;
			break;
		}
			
	}
	printf("%.2f",ans);
	return 0;
}


#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct Gasstation
{
	double price;
	double dist;
}gas[510];
bool cmp(Gasstation a,Gasstation b)
{
	return a.dist < b.dist;
}
int main()
{
	double cmax,d,davg;
	int n;
	int flag;
	scanf("%lf %lf %lf %d",&cmax,&d,&davg,&n);
	for(int i = 0;i < n;++i)
	{
		scanf("%lf %lf",&gas[i].price,&gas[i].dist);
	}
	gas[n].dist = d;
	gas[n].price = 0;
	sort(gas,gas + n,cmp);
	if(gas[0].dist != 0)
		printf("The maximum travel distance = 0.00");
	else
	{
		int now = 0;
		int min;
		double singledist;
		double traveldist = 0;
		double summoney = 0;
		double shengyou = 0;
		singledist = cmax * davg;
		//printf("单次能跑：%.2f\n",singledist);//
		while( traveldist < d )
		{
			if(gas[now+1].dist - gas[now].dist > singledist)//加满了找不到加油站
			{
				traveldist += singledist;
				printf("The maximum travel distance = %.2f",traveldist);
				break;
			}
			else//能找到加油站
			{
				min = now + 1;
				flag = 0;
				for(int i = now+1; i <= n && (gas[i].dist - gas[now].dist) <= singledist; ++i )//遍历这些里边的找到价格最低的
				{
					
					if(gas[i].price < gas[now].price)//有比自己便宜的停止检测直接去,可能剩的油够多不用加油
					{
						traveldist = gas[i].dist;
						if( (gas[i].dist-gas[now].dist)/davg < shengyou )//剩的油足够，不用加钱
						{
							shengyou = shengyou - (gas[i].dist-gas[now].dist)/davg;
							//summoney不变
						}
						else//剩的油刚好或者不够，要加钱
						{
							
							summoney += ( (gas[i].dist-gas[now].dist)/davg - shengyou ) * gas[now].price;
							shengyou = 0;
						}
						now = i;
						flag = 1;
						break;
					}
					else//能到的点都比自己贵，
					{
						if(gas[i].price < gas[min].price)
							min = i;
					}
				}
				if(flag == 0)//加满到最便宜的点检测
				{
					traveldist = gas[min].dist;
					summoney += (cmax - shengyou) * gas[now].price;
					shengyou = cmax - (gas[min].dist-gas[now].dist)/davg;
					now = min;
				}

			}
			//printf("最小站点：%d 钱：%.2f 还剩下的油：%.2f 最小站距离：%.2f\n",now,summoney,shengyou,gas[now].dist);//
		}
		if(traveldist == d)
			printf("%.2f",summoney);

	}
	return 0;
}


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
		//printf("�������ܣ�%.2f\n",singledist);//
		while( traveldist < d )
		{
			if(gas[now+1].dist - gas[now].dist > singledist)//�������Ҳ�������վ
			{
				traveldist += singledist;
				printf("The maximum travel distance = %.2f",traveldist);
				break;
			}
			else//���ҵ�����վ
			{
				min = now + 1;
				flag = 0;
				for(int i = now+1; i <= n && (gas[i].dist - gas[now].dist) <= singledist; ++i )//������Щ��ߵ��ҵ��۸���͵�
				{
					
					if(gas[i].price < gas[now].price)//�б��Լ����˵�ֹͣ���ֱ��ȥ,����ʣ���͹��಻�ü���
					{
						traveldist = gas[i].dist;
						if( (gas[i].dist-gas[now].dist)/davg < shengyou )//ʣ�����㹻�����ü�Ǯ
						{
							shengyou = shengyou - (gas[i].dist-gas[now].dist)/davg;
							//summoney����
						}
						else//ʣ���͸պû��߲�����Ҫ��Ǯ
						{
							
							summoney += ( (gas[i].dist-gas[now].dist)/davg - shengyou ) * gas[now].price;
							shengyou = 0;
						}
						now = i;
						flag = 1;
						break;
					}
					else//�ܵ��ĵ㶼���Լ���
					{
						if(gas[i].price < gas[min].price)
							min = i;
					}
				}
				if(flag == 0)//����������˵ĵ���
				{
					traveldist = gas[min].dist;
					summoney += (cmax - shengyou) * gas[now].price;
					shengyou = cmax - (gas[min].dist-gas[now].dist)/davg;
					now = min;
				}

			}
			//printf("��Сվ�㣺%d Ǯ��%.2f ��ʣ�µ��ͣ�%.2f ��Сվ���룺%.2f\n",now,summoney,shengyou,gas[now].dist);//
		}
		if(traveldist == d)
			printf("%.2f",summoney);

	}
	return 0;
}


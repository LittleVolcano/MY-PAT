
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
struct Car
{
	char id[8];
	int time;
	char status[4];
}all[10010],valid[10010];
map<string,int> parktime;
int secords(int hh,int mm,int ss)
{
	return hh * 3600 + mm * 60 + ss;
}
bool cmpid(Car a,Car b)
{
	if(strcmp(a.id,b.id) != 0) return strcmp(a.id,b.id) < 0;
	else return a.time < b.time;
}
bool cmptime(Car a,Car b)
{
	return a.time < b.time;
}

int main()
{
	int n,k,hh,mm,ss;
	int num = 0;//匹配的记录数
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s %d:%d:%d %s",all[i].id,&hh,&mm,&ss,all[i].status);
		all[i].time = secords(hh,mm,ss);
	}
	sort(all,all + n,cmpid);
	int maxtime = -1;
	for(int i = 1;i < n; ++i)
	{
		//printf("\n测试点%s %d\n",all[i].id,all[i].time);//
		if( strcmp(all[i].id,all[i-1].id)==0 && strcmp(all[i].status,"out")==0 && strcmp(all[i-1].status,"in")==0 )//匹配
		{
		//	printf("\n测试点%s %d %d\n",all[i].id,all[i-1].time,all[i].time);//
			valid[num++] = all[i - 1];
			valid[num++] = all[i];
			int staytime = all[i].time - all[i-1].time;
			if( parktime.count(all[i].id) == 0 )
			{
				parktime[all[i].id] = 0;
			}
			parktime[all[i].id] += staytime;
			if( maxtime < parktime[all[i].id] )
				maxtime = parktime[all[i].id];
		}
	}

	sort(valid , valid + num , cmptime );
	int nownum = 0;
	int nowtime;
	int j = 0;
	for(int i = 0; i < k; ++i )//计算某时刻校园内的车数
	{
		scanf("%d:%d:%d",&hh,&mm,&ss);
		nowtime = secords(hh,mm,ss);
		//printf("\n测试点 %d %d\n",nowtime,valid[j].time);
		while( valid[j].time <= nowtime && j < num )
		{
			if( strcmp(valid[j].status , "in" ) == 0)
				nownum++;
			else nownum--;
			++j;
		//	printf("\n测试点\n");//
		}
		printf("%d\n",nownum);
	}
	map<string ,int>::iterator it;
	for(it = parktime.begin();it != parktime.end(); it++ )
		if(it->second == maxtime)
			printf("%s ",it->first.c_str());
	printf("%02d:%02d:%02d",maxtime / 3600,(maxtime % 3600) / 60,maxtime % 60 );



	return 0;
}


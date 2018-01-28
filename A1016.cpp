
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct record
{
	char name[25];
	int month,day,hour,m;
	int status;
	int flag;

}rec[1010],temp;
bool cmp(record a ,record b)
{
	if(strcmp(a.name,b.name) != 0) return strcmp(a.name,b.name) < 0;
	else if( a.month != b.month ) return a.month < b.month;
	else if(a.day != b.day ) return a.day < b.day;
	else if( a.hour != b.hour ) return a.hour < b.hour;
	else if(a.m != b.m ) return a.m < b.m;
}

int main()
{
	int n;
	int time = 0,money = 0;
	double dollar;
	double sumdollar = 0;//summoney的循环有问题不能放这
			
	int fee[30];
	for(int i = 0;i < 24; ++i)//费用数组
	{
		scanf("%d",&fee[i]);
	}
	scanf("%d",&n);
	for(int i = 0;i < n; ++i)//初始化记录
	{
		char sta[10];
		scanf("%s %d:%d:%d:%d %s",rec[i].name,&rec[i].month,&rec[i].day,&rec[i].hour,&rec[i].m,sta);
		rec[i].flag = 0;
		if(strcmp(sta,"on-line") == 0)
			rec[i].status = 1;
		else rec[i].status = 0;
	}
	sort( rec ,rec + n , cmp );//排序
	int tempname = 0;//记录上一个输出的序号，用来判断这个人输出过没有
	for(int i = 0; i < n; ++i )
	{
		//这个if能找出来同一用户的匹配的记录
		//这个记录对是i 和i-1
		
		if( i >= 1 && rec[i].status == 0 && rec[i - 1].status == 1 && strcmp(rec[i].name,rec[i - 1].name)==0)
		{
			if(tempname == 0 || strcmp(rec[tempname].name,rec[i].name)!= 0 )
			{
				printf("%s %02d\n",rec[i].name,rec[i].month);
			}
			
			printf("%02d:%02d:%02d %02d:%02d:%02d ",rec[i-1].day,rec[i-1].hour,rec[i-1].m,rec[i].day,rec[i].hour,rec[i].m);
			//紧接着计算时长，花费。注意输出格式  注意费用的美元美分转换 liangweixiaoshu
			//计算费用总计
			time = 0,money = 0;
			temp = rec[i - 1];
			while(temp.day < rec[i].day || temp.hour < rec[i].hour || temp.m < rec[i].m )
			{
				++time;
				money += fee[temp.hour];
				++temp.m;
				if(temp.m == 60)
				{
					temp.m = 0;
					++temp.hour;
					if(temp.hour == 24)
					{
						temp.hour = 0;
						++temp.day;
					}
				}
				dollar = money;
				dollar /= 100;
				
			}
			printf("%d $%.2f\n",time,dollar);
			sumdollar += dollar;
			tempname = i;
		}
		if( strcmp(rec[tempname].name,rec[i].name)!= 0 || i == n-1)
		{
			if(rec[tempname].flag == 0)
			{
				printf("Total amount: $%.2f\n",sumdollar);
				rec[tempname].flag = 1;
				sumdollar = 0;
			}
		}


	}


	return 0;
}


#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student
{
	int id;
	int score[4];
	int rank[4];
}stu[2010];	
int now;
bool cmp(Student a,Student b)
{
	return a.score[now] > b.score[now];
}
/*
5 6
101 98 85 88
102 70 95 88
103 82 87 94
104 91 91 91
105 85 90 90
101
102
103
104
105
997

*/
int main()
{
	char course[4] = {'A','C','M','E'};

	int n,m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i )
	{
		scanf("%d%d%d%d", &stu[i].id, &stu[i].score[1], &stu[i].score[2],&stu[i].score[3]);
		stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
	}
	int sum = 0;//
	for(now = 0;now < 4; ++now )
	{
		sort(stu,stu + n,cmp);
		stu[0].rank[now] = 1;
		for(int i = 1;i < n;++i)
		{
			if(stu[i].score[now] == stu[i - 1].score[now])
				stu[i].rank[now] =stu[i - 1].rank[now];
			else stu[i].rank[now] = i + 1;
		}
		
		
		//sum++;//
		//printf("测试点%d\n",sum);//

	}
	
			//sum = 10;//
	int asknum;
	for(int i = 0;i < m;++i)//m个查询
	{
		int flag = 0;
		scanf("%d",&asknum);
		for(int j = 0;j < n;++j)//每个查询遍历一次
		{
			if(asknum == stu[j].id)//找到在里边
			{
				int k = 0;
				for(int p = 0 ; p < 4 ; ++p )//找出最小的用k记录
				{
					if(stu[j].rank[p] < stu[j].rank[k])
							k = p;
				}
				printf("%d %c\n",stu[j].rank[k],course[k]);
				flag = 1;
				//printf("%d %c\n",stu[j].rank[k],course[k]);//
				break;
			}
			
		}
		if(flag == 0)
			printf("N/A\n");//学生不在里边

	}
	




	return 0;
}


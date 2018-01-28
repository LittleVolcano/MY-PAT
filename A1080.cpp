
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Student
{
	int id,g1,g2,sum;
	int want[10];
	int rank;
}stu[40010];
struct School
{
	int wantnum;//一共要招的人数
	int last;//上一个
	int have;//已经有的人数
	int get[40010];//录取的考生编号
}sch[110];
bool cmp(Student a,Student b)
{
	if(a.sum != b.sum)return a.sum > b.sum;
	else return a.g1 > b.g1;
}

int main()
{
	int n,m,k;//学生数 学校数 志愿数
	scanf("%d%d%d",&n, &m, &k);
	for(int i = 0; i < m ; ++i)//每个学校的信息
	{
		scanf("%d",&sch[i].wantnum);
		sch[i].last = -1;
		sch[i].have = 0;
	}
	for(int i = 0; i < n ; ++i)//每个学生分数和志愿号
	{
		stu[i].id = i;
		scanf("%d%d",&stu[i].g1,&stu[i].g2);
		stu[i].sum = stu[i].g1 + stu[i].g2;
		for(int j = 0; j < k ; ++j)
			scanf("%d",&stu[i].want[j]);
	}
	sort(stu,stu + n ,cmp);
	stu[1].rank = 0;
	for(int i = 1; i < n ; ++i)//添加排名信息
	{
		if(stu[i].sum == stu[i-1].sum && stu[i].g1 == stu[i-1].g1 )
			stu[i].rank = stu[i-1].rank;
		else stu[i].rank = i;
	}
	for(int i = 0; i < n ; ++i)//对每个考生判断录取到哪了
	{
		for(int j = 0; j < k; ++j)//对该考生的志愿做判断
		{
			int p = stu[i].want[j];
			if(sch[p].have < sch[p].wantnum || stu[sch[p].last].rank == stu[i].rank)//学校没录满或者上个学生和这个排名一样
			{
				sch[p].last = i;
				sch[p].get[ sch[p].have ] = stu[i].id;
				++sch[p].have;
				break;//不再找其他学校
			}
		}
	}
	for(int i = 0; i < m ; ++i)//对每个学校的学生id排序并输出
	{
		if(sch[i].have != 0)
		{
			sort(sch[i].get , sch[i].get + sch[i].have );
			for(int j = 0; j < sch[i].have ; ++j)
			{
				if(j != 0)
					printf(" ");
				printf("%d",sch[i].get[j]);
			}
		}
		printf("\n");
	}


	return 0;
}


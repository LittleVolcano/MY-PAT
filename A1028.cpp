#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
	int id;
	char name[10];
	int score;
	}stu[100010];
bool cmp1(Student a,Student b)//按照准考证号从小到大排序
{
	return a.id < b.id;
}
bool cmp2(Student a,Student b)//按姓名排序，相同姓名按准考证
{
	if(strcmp(a.name,b.name) != 0)
		return strcmp(a.name,b.name) < 0;
	else return a.id < b.id;
}
bool cmp3(Student a,Student b)//按分数从小到大排序，相同分数按准考证
{
	if(a.score != b.score)
		return a.score < b.score;
	else return a.id < b.id;
}

int main()
{
	int i,n,c;
	scanf("%d%d", &n, &c);
	for( i = 0;i < n; ++i)
	{
		scanf("%d%s%d",&stu[i].id, &stu[i].name,&stu[i].score);//不空格有影响吗
	}
	if(c == 1)
		sort(stu,stu + n,cmp1);
	else if(c == 2)
		sort(stu,stu + n,cmp2);
	else	sort(stu,stu + n,cmp3);
	for(i = 0;i < n; ++i)
		printf("%06d %s %d\n",stu[i].id, stu[i].name, stu[i].score);
	return 0;
}


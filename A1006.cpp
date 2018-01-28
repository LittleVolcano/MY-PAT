#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student
{
	char id[20];
	int h1,m1,s1;//到的时间
	int h2,m2,s2;//离开的时间
}stu[10000];
bool cmp1(Student a,Student b)//到达排序
{
	if(a.h1 != b.h1) return a.h1 < b.h1;//小时不同小的在前,小时一样看分钟
	else if(a.m1 != b.m1) return a.m1 < b.m1;//分钟不同小的在前，分钟相同看秒
	else return a.s1 < b.s1;
}
bool cmp2(Student a,Student b)//离开排序
{
	if(a.h2 != b.h2) return a.h2 > b.h2;//小时不同大的在前,小时一样看分钟
	else if(a.m2 != b.m2) return a.m2 > b.m2;//分钟不同大的在前，分钟相同看秒
	else return a.s2 > b.s2;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i = 0;i < n; ++i)//输入员工信息
	{
		scanf("%s %d:%d:%d %d:%d:%d",stu[i].id, &stu[i].h1, &stu[i].m1,&stu[i].s1,&stu[i].h2,&stu[i].m2,&stu[i].s2);
	}
	sort(stu,stu + n,cmp1);
	printf("%s ",stu[0].id);//怎么输出一个数组
	sort(stu,stu + n,cmp2);
	printf("%s\n",stu[0].id);
	return 0;
}



	

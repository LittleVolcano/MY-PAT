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
bool cmp1(Student a,Student b)//����׼��֤�Ŵ�С��������
{
	return a.id < b.id;
}
bool cmp2(Student a,Student b)//������������ͬ������׼��֤
{
	if(strcmp(a.name,b.name) != 0)
		return strcmp(a.name,b.name) < 0;
	else return a.id < b.id;
}
bool cmp3(Student a,Student b)//��������С����������ͬ������׼��֤
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
		scanf("%d%s%d",&stu[i].id, &stu[i].name,&stu[i].score);//���ո���Ӱ����
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



#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student
{
	char name[15],id[15];
	int grade;

}stu[20000];
bool cmp(Student a,Student b)
{
	return a.grade > b.grade;
}

int main()
{
	int n,left,right;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i)
	{
		scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
	}
	scanf("%d %d",&left, &right);
	sort(stu,stu + n,cmp);
	int flag = 0;
	for(int i = 0;i < n; ++i)
	{
		if(stu[i].grade >= left && stu[i].grade <= right )
		{
			printf("%s %s\n",stu[i].name,stu[i].id);
			flag = 1;
		}
	}
	if(flag == 0)
		printf("NONE\n");

	return 0;
}


#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student
{
	char id[20];
	int h1,m1,s1;//����ʱ��
	int h2,m2,s2;//�뿪��ʱ��
}stu[10000];
bool cmp1(Student a,Student b)//��������
{
	if(a.h1 != b.h1) return a.h1 < b.h1;//Сʱ��ͬС����ǰ,Сʱһ��������
	else if(a.m1 != b.m1) return a.m1 < b.m1;//���Ӳ�ͬС����ǰ��������ͬ����
	else return a.s1 < b.s1;
}
bool cmp2(Student a,Student b)//�뿪����
{
	if(a.h2 != b.h2) return a.h2 > b.h2;//Сʱ��ͬ�����ǰ,Сʱһ��������
	else if(a.m2 != b.m2) return a.m2 > b.m2;//���Ӳ�ͬ�����ǰ��������ͬ����
	else return a.s2 > b.s2;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i = 0;i < n; ++i)//����Ա����Ϣ
	{
		scanf("%s %d:%d:%d %d:%d:%d",stu[i].id, &stu[i].h1, &stu[i].m1,&stu[i].s1,&stu[i].h2,&stu[i].m2,&stu[i].s2);
	}
	sort(stu,stu + n,cmp1);
	printf("%s ",stu[0].id);//��ô���һ������
	sort(stu,stu + n,cmp2);
	printf("%s\n",stu[0].id);
	return 0;
}



	

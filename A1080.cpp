
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
	int wantnum;//һ��Ҫ�е�����
	int last;//��һ��
	int have;//�Ѿ��е�����
	int get[40010];//¼ȡ�Ŀ������
}sch[110];
bool cmp(Student a,Student b)
{
	if(a.sum != b.sum)return a.sum > b.sum;
	else return a.g1 > b.g1;
}

int main()
{
	int n,m,k;//ѧ���� ѧУ�� ־Ը��
	scanf("%d%d%d",&n, &m, &k);
	for(int i = 0; i < m ; ++i)//ÿ��ѧУ����Ϣ
	{
		scanf("%d",&sch[i].wantnum);
		sch[i].last = -1;
		sch[i].have = 0;
	}
	for(int i = 0; i < n ; ++i)//ÿ��ѧ��������־Ը��
	{
		stu[i].id = i;
		scanf("%d%d",&stu[i].g1,&stu[i].g2);
		stu[i].sum = stu[i].g1 + stu[i].g2;
		for(int j = 0; j < k ; ++j)
			scanf("%d",&stu[i].want[j]);
	}
	sort(stu,stu + n ,cmp);
	stu[1].rank = 0;
	for(int i = 1; i < n ; ++i)//���������Ϣ
	{
		if(stu[i].sum == stu[i-1].sum && stu[i].g1 == stu[i-1].g1 )
			stu[i].rank = stu[i-1].rank;
		else stu[i].rank = i;
	}
	for(int i = 0; i < n ; ++i)//��ÿ�������ж�¼ȡ������
	{
		for(int j = 0; j < k; ++j)//�Ըÿ�����־Ը���ж�
		{
			int p = stu[i].want[j];
			if(sch[p].have < sch[p].wantnum || stu[sch[p].last].rank == stu[i].rank)//ѧУû¼�������ϸ�ѧ�����������һ��
			{
				sch[p].last = i;
				sch[p].get[ sch[p].have ] = stu[i].id;
				++sch[p].have;
				break;//����������ѧУ
			}
		}
	}
	for(int i = 0; i < m ; ++i)//��ÿ��ѧУ��ѧ��id�������
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


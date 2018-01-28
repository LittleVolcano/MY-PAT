
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Student//����ʹ���id
{
	int timu[10];//ÿ����÷�
	int sumscore;//�ܷ�
	int name;
	int flag;
	int solve;
	int rank;
}stu[10010];
bool cmp(Student a, Student b)
{
	if(a.sumscore != b.sumscore) return a.sumscore > b.sumscore;
	else if(a.solve != b.solve) return a.solve > b.solve;
	else return a.name < b.name;
}
int main()
{
	int n;//������
	int m;//��Ŀ��
	int k;//��¼��
	scanf("%d%d%d",&n,&m,&k);
	int score[10];//ÿ����ķ���
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d",&score[i]);
	}
	for(int i = 1; i <= n; ++i)//��ʼ����������
	{
		stu[i].name = i;
		stu[i].solve = 0;
		stu[i].flag = 0;
		for(int j = 1; j <= m; ++j)
		{
			stu[i].timu[j] = -1;
		}
		stu[i].sumscore = 0;
	}
	int id;
	int tihao;
	int tempscore;
	for(int i = 0; i < k; ++i)//�����¼
	{
		scanf("%d %d %d",&id,&tihao,&tempscore);
		if(tempscore != -1)//�÷֣�����߷ָ��·�����������������1
		{
			stu[id].flag = 1;
			if(tempscore > stu[id].timu[tihao])
				stu[id].timu[tihao] = tempscore;
		}
		else if(stu[id].timu[tihao] == -1 )//���÷֣�ԭ��û�й��ύ����0�����򲻶�
			{
				stu[id].timu[tihao] = 0;
			}
	}
	//�������������sum
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(stu[i].timu[j] == score[j] )
				++ stu[i].solve;
			if( stu[i].timu[j] >= 0 )
				stu[i].sumscore +=  stu[i].timu[j];
		}
	}
	sort(stu + 1 ,stu + n +1 ,cmp);//����,�����i��name�Ͳ�ƥ����
	for(int i = 1; i <= n; ++i)//���rank��Ϣ��������
	{
		stu[1].rank = 1;
		if(i > 1 && stu[i].sumscore == stu[i-1].sumscore )
			stu[i].rank = stu[i-1].rank;
		else stu[i].rank = i;

		if(stu[i].flag == 1)
		{
			printf("%d %05d %d",stu[i].rank,stu[i].name,stu[i].sumscore);
			for(int j = 1 ;j <= m ;++j)
			{
				if( stu[i].timu[j] == -1 )
					printf(" -");
				else printf(" %d",stu[i].timu[j]);
			}
			printf("\n");
		}
	}


	return 0;
}


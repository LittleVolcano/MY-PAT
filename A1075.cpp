
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Student//本身就带有id
{
	int timu[10];//每道题得分
	int sumscore;//总分
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
	int n;//考生数
	int m;//题目数
	int k;//记录数
	scanf("%d%d%d",&n,&m,&k);
	int score[10];//每道题的分数
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d",&score[i]);
	}
	for(int i = 1; i <= n; ++i)//初始化考生数组
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
	for(int i = 0; i < k; ++i)//输入记录
	{
		scanf("%d %d %d",&id,&tihao,&tempscore);
		if(tempscore != -1)//得分，用最高分更新分数，并且输出标记置1
		{
			stu[id].flag = 1;
			if(tempscore > stu[id].timu[tihao])
				stu[id].timu[tihao] = tempscore;
		}
		else if(stu[id].timu[tihao] == -1 )//不得分，原来没有过提交，置0，否则不动
			{
				stu[id].timu[tihao] = 0;
			}
	}
	//计算完美解决和sum
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
	sort(stu + 1 ,stu + n +1 ,cmp);//排序,排序后i和name就不匹配了
	for(int i = 1; i <= n; ++i)//添加rank信息并输出结果
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


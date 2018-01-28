
#include <algorithm>
#include <cstring>
using namespace std;
struct Student
{
	char id[15];
	int score;
	int kaochangnum;
	int rank;
}stu[30010];
bool cmp(Student a,Student b)
{
	if(a.score != b.score)
		return a.score > b.score;
	else return strcmp(a.id,b.id) < 0;
}
int main()
{
	int n,k;
	int num = 0;//第几个考生
	//int tempkaochang = 0;//考场号 i就是考场号了
	scanf("%d",&n);
	for(int i = 0;i < n; ++i )//跑n个考场
	{
		scanf("%d",&k);
		for(int j = 0; j < k; ++j)//考场内跑一遍
		{
			scanf("%s %d",&stu[num].id,&stu[num].score);
			stu[num].kaochangnum = i + 1;
			++num;
		}
		sort(stu + num - k,stu + num,cmp);
		stu[num - k].rank = 1;
		for(int j = num - k + 1;j < num; ++j)
		{
			if(stu[j].score == stu[j - 1].score)
				stu[j].rank = stu[j - 1].rank;
			else stu[j].rank = j + 1 - ( num - k );

		}
			

	}
	printf("%d\n",num);
	sort(stu,stu + num,cmp);
	int r = 1;
	for(int i = 0;i < num; ++i)
	{
		if(i > 0 && stu[i].score != stu[i - 1].score)
			r = i + 1;
		printf("%s %d %d %d\n", stu[i].id, r, stu[i].kaochangnum, stu[i].rank);
	}


	return 0;
}


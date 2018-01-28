
#include <stdio.h>

struct Student
{
	char name[15];
	char id[15];
	int score;
}F,M,temp;

int main()
{
	int n;
	char gender;
	M.score = 101;
	F.score = -1;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)//这样定义的话i只能局部使用
	{
		scanf("%s %c %s %d",temp.name,&gender,&temp.id,&temp.score);
		if(gender == 'M' && temp.score < M.score)
			M = temp;//结构体竟然能直接这样赋值
		else if(gender == 'F' && temp.score > F.score)
			F = temp;
	}
	if(F.score == -1)
		printf("Absent\n");
	else printf("%s %s\n",F.name,F.id);//不应是地址，但是还是可以写数组名
	if(M.score == 101)
		printf("Absent\n");
	else printf("%s %s\n",M.name,M.id);
	if(F.score == -1 || M.score == 101 )
		printf("NA\n");
	else printf("%d\n",F.score - M.score);


	return 0;
}


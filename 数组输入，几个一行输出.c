# include<stdio.h>
# include<string.h>
# define M 8	//宏替换 

int main()
{
	int a[M], *p, i;
	for(p = a;p < a + M;p++)//单个输入 
	{
		scanf("%d",p);
	}
	printf("\noutput:\n");
	for(i = 0;i < M;i++)//五个一行输出 
	{
		printf("%4d%c", a[i], (i + 1) % 5 == 0 ? '\n' : ' ');
	}
	
	return 0;
 } 

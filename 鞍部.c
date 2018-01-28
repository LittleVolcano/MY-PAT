//第一行输入读入n，初始化数组nn 
//遍历每一行，找到最大的 元素（可能不止一个）
//然后遍历该元素所在的列，如果该元素是所在列最小的，输出下标，结束
//遍历完了所有行都没输出，结束，打印 NO 
#include <stdio.h>
int main()
{
	int n,i,j;
	int max = 0;
	int j1;
	int flag = 0;
	scanf("%d", &n);
	int a[n][n] = {};
	for(i = 0;i < n; i++)//输入？？？ 
	{
		for(j = 0; j < n; j++)
		{
			
		}
	}
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)//遍历某行 
		{
			if(a[i][j] >= max)
			{
				max = a[i][j];//记录最大的行 
				j1 = j;//记录最大的列 
			}
			
		}//遍历某行结束
		for(i = 0;i < n;i++)//判断最大元素所在列
		{
			if(a[i][j1] < max )//该列有元素比这个数还小，那这个就不是鞍部，什么都不做继续检查下一行
			{
				break;
			 } 
			 else if(j1 == n-1)//最后一个元素都检查了 ，都没有问题，该元素是该列最小的 ，是鞍部，输出鞍部下标，结束程序
			 {
			 	 printf("%d %d", i, j1);
			 	 flag = 1;
			 }
			
		 } 
		 
	}
	if(flag == 0)
	{
		printf("NO");
	}
	
	return 0;
}

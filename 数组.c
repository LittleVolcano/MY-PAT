#include<stdio.h>
int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7}//1 2 3 4 5 6 7 
	int b[10] = {0};//全部初始化为0了		0 0 0 0 0 0 0 0 0 0 
	int c[10] = {[1] = 3, 4, [8] = 6};//0 3 4 0 0 0 0 0 6 0 适合比较稀疏的数据赋值 
	int c[] = {[1] = 3, 4, [8] = 6};  //0 3 4 0 0 0 0 0 6   到第九个就没了 
	
	num = sizeof(a) / sizeof(a[0]);//这样就能得到a中元素个数
	
	int a[][5] = //二维数组注意第二个括号内的maxsize必须要写，即必须给出每行多少个，要不系统不知道怎么排 
	{
		{0, 1, 2, 3, 4}, {2, 4, 5, 6, 7}
	
	} 
	
	
	
	
	return 0;
}

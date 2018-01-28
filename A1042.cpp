
#include <stdio.h>

int main()
{
	char color[5]={'S','H','C','D','J'};
	int i,j,n;
	int old[55],ne[55],l[55];
	for(i = 1;i <= 54; ++ i)//初始化三个数组
		old[i] = ne[i] = l[i] = i;
	scanf("%d",&n);//循环次数
	for(i = 1;i <= 54; ++ i)//输入变形用的序列
		scanf("%d",&l[i]);
	//变形开始
	for(i = 1;i <= n; ++ i)//控制循环次数
	{
		for(j = 1;j <= 54; ++ j)//变形
			ne[l[j]] = old[j];
		for(j = 1;j <= 54; ++ j)//变完一次把变好的重新放到old中为下次是循环做准备
			old[j] = ne[j];

	}
	//输出开始
	for(i = 1;i <= 54; ++ i)
	{
		if(i != 1)
			printf(" ");
		--ne[i];//为匹配花色和对应数字
		printf("%c%d",color[ne[i]/13],ne[i] % 13 +1);
		
	}
	return 0;
}


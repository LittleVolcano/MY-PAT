
#include <cstdio>
#include <stdio.h>
#include <cstring>
char s[110][300];

int main()
{
	int n,minlen = 300,len;
	int pos = 0;
	scanf("%d",&n);
	getchar();
	for(int i = 0; i < n; ++i)
	{
		gets(s[i]);
		len = strlen(s[i]);
		if(len < minlen)
			minlen = len;
		for(int j = 0; j < len / 2; ++j )//反转字符数组
		{
			char temp = s[i][j];
			s[i][j] = s[i][len - 1 - j];
			s[i][len - 1 - j] = temp;
		}
	}
	for(int i = 0; i < minlen; ++i)//控制位置的循环
	{
		int flag = 1;
		char c = s[0][i];
		for(int j = 0; j < n; ++j )//控制第几个数组的循环
		{
			if(c != s[j][i])
			{
				flag = 0;
				break;
			}

		}
		if(flag == 1)//记录相同的有几位
			++pos;
		else break;
		
	}
		

	if(pos == 0 )
		printf("nai");
	else 
	{
		for(int i = pos - 1 ;i >= 0; --i)
			printf("%c",s[0][i]);
	}
	return 0;
}


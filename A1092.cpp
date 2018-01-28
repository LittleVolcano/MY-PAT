
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int status[128]={0};
	int flag = 1;
	int sumshao = 0;
	char str1[80];
	char str2[80];
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0;i < len1 ;++i)
		++status[ str1[i] ];
	for(int i = 0;i < len2 ;++i)
		--status[ str2[i] ];
	for(int i = 0;i < 128 ;++i)
	{
		if(status[i] < 0 )
		{
			sumshao -= status[i];
			flag = -1;
		}
		
		//printf("#%d %d\n",i,status[i]);
	}
	if(flag == -1)
		printf("No %d",sumshao);
	else
		printf("Yes %d",len1-len2);



	return 0;
}


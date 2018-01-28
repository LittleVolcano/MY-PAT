
#include <stdio.h>
#include <cstring>

int main()
{
	int i = 0;
	char data[7][5] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char str1[70],str2[70],str3[70],str4[70];
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	for(i = 0; i < strlen(str1) && i < strlen(str2); ++i)
	{
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
			{
				printf("%s ",data[str1[i] - 'A']);
				break;
			}
	}
	while( i < strlen(str1) && i < strlen(str2) )
	{
		++ i;
		if( str1[i] == str2[i] )
			if(str1[i] >= '0' && str1[i] <= '9')
			{
				printf("%02d:",str1[i] - '0');//可以用字符输出吗
				break;
			}
			else if(str1[i] >= 'A' && str1[i] <= 'N')
				{
				printf("%02d:",str1[i] - 'A' + 10);
				break;
				}
	}
	for(i = 0; i < strlen(str3) && i < strlen(str4); ++i)
	{
		
		//printf("测试点%02d测试点\n",i);
		if(str3[i] == str4[i] && ( ( str3[i] >= 'A' && str3[i] <= 'Z' ) || str3[i] >= 'a' && str3[i] <= 'z' ) )
		{
			printf("%02d",i);
			break;
		}
	}
	return 0;
}


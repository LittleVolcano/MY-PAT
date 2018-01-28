
#include <stdio.h>
#include <cstring>
int main()
{
	char str1[10010],str2[10010];
	int hash[128] = {0};
	int len1,len2;
	gets(str1);
	gets(str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(int i = 0;i < len2 ;++i)
	{
		hash[ str2[i] ] = 1;
	}
	for(int i = 0;i < len1 ;++i)
	{
		if(hash[ str1[i] ] != 1)
			printf("%c",str1[i]);
	}

	return 0;
}


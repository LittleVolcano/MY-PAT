
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char str1[100];
	char str2[100];
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int status[128]={0};
	for(int i = 0 ; i < len1; ++i)
	{
		int j;
		char c1,c2;
		for(j = 0 ; j < len2; ++j)
		{
			c1 = str1[i];
			c2 = str2[j];
			if(c1 >= 'a'&&c1 <= 'z')
				c1 -= 32;
			if(c2 >= 'a'&&c2 <= 'z')
				c2 -= 32;
			if(c1 == c2)
				break;
		}
		if(j == len2 && status[c1] == 0 )
			printf("%c",c1);
		status[c1] = 1;
	}
	return 0;
}


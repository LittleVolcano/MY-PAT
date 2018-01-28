
#include <stdio.h>
#include <cstring>
char num[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[5][5] = {"Shi","Bai","Qian","Wan","Yi"};
int main()
{
	char str[15];
	gets(str);
	int len = strlen(str);
	int left = 0;
	int right = len - 1;
	if(str[0] == '-')
	{
		printf("Fu");
		++left;
	}
	while(left + 4 <= right)//从右往左移，每次移一个字节，这个方法很好
		right -= 4;
	while( left < len )
	{
		int flag = 0;
		int print = 0;
		while( left <= right )
		{
			if(left > 0 && str[left] == '0' )
			{
				flag = 1;
			}
			else
			{
				if( flag == 1 )
				{
					printf(" ling");
					flag = 0;
				}
				if(left > 0)
					printf(" ");
				printf("%s",num[str[left] - '0']);
				print = 1;
				if(left != right)
				{
					printf(" %s",wei[right - left - 1]);
				}
				
			}
			++left;
		}
		if(print == 1 && right != len - 1)
			printf(" %s",wei[ (len - 1 - right) / 4 + 2]);
		right += 4;
	}





	return 0;
}


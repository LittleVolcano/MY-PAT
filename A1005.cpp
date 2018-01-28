#include <stdio.h>
#include <cstring>
char number[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
	int sum = 0,len,sumlen = 0,digit[5];
	char s[110];
	gets(s);
	len = strlen(s);
	for(int i = 0 ; i < len; ++i)
		sum += (s[i] - '0');
	if(sum == 0)
		printf("%s",number[0]);
	else while( sum != 0 )
	{
		digit[sumlen++] = sum % 10;
		sum /= 10;
	}
	for(int i = sumlen - 1; i >=0 ; --i)
	{
		printf("%s",number[digit[i]]);
		if(i != 0)
			printf(" ");
	}

	return 0;
}


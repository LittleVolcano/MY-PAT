
#include<stdio.h>
#include<cstring>



int main()
{
	int n1,n2,n3,N;
	char str[100],ans[50][50];
	gets(str);
	N = strlen(str);
	n1 = n3 =( N + 2 ) / 3;
	n2 = N + 2 - n1 - n3;
	for(int i = 0 ;i < 50; ++i)
		for(int j = 0;j < 50; ++j)
			ans[i][j] = ' ';


	int pos = 0;
	for(int i = 0; i< n1; ++i)
		ans[i][0] = str[ pos++ ];//这个后自加用的漂亮
	for(int j = 1; j < n2; ++j)
		ans[n1 - 1][j] = str[ pos++ ];
	for(int i = n1 - 2; i >= 0; --i)
		ans[i][n2 - 1] = str[ pos++ ];


	for(int i = 0 ;i < n1; ++i)
	{
		for(int j = 0;j < n2; ++j)
			printf("%c",ans[i][j]);
		printf("\n");
	}



	return 0;
}


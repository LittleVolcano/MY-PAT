
#include <stdio.h>
#include <cstring>
int main()
{
	int n,m,k;
	int flag = 0;
	int hash[1010] = {0};
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n;++i)
	{
		scanf("%d",&k);
		hash[k]++;
	}
	for(int i = 1;i <= m - i; ++i)
	{
		if( hash[i] != 0 && hash[m-i] != 0 && i!=(m-i) )
		{
			printf("%d %d",i,m-i);
			flag = 1;
			break;
		}
		if( i == ( m-i ) && hash[i]>=2 )
			{
			printf("%d %d",i,m-i);
			flag = 1;
			break;
			}
	}
	if(flag == 0)
		printf("No Solution");

	return 0;
}


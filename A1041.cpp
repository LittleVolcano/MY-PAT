
#include <stdio.h>

int main()
{
	int a[100010],hash[100010] = {0};
	int n;
	int flag = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		hash[ a[i] ] += 1;
	}
	for(int i = 0; i < n; ++i)
	{
		if(hash[ a[i] ] == 1)
		{
			printf("%d",a[i]);
			flag = 1;
			break;
		}
			
	}
	if(flag == 0)
		{
			printf("None");
		}
	return 0;
}


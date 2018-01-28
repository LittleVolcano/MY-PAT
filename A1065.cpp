
#include <stdio.h>

int main()
{
	long long a,b,c,res;
	int flag;
	int T,tcase = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		res = a + b;
		if(a > 0 && b > 0 && res < 0)
				{
					flag = 1;
					//printf("$1$\n");
				}
		else if(a < 0 && b < 0 && res >= 0)
				{
					flag = 0;
					//printf("$2$\n");
				}
			else if(res > c)
				{
					flag = 1;
					//printf("$3$\n");
				}
				else 
				{
					flag = 0;
					//printf("$4$\n");
				}
		if(flag == 1)
			printf("Case #%d: true\n",tcase++);
		else
			printf("Case #%d: false\n",tcase++);

	
	}
	return 0;
}


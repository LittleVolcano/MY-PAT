
#include <stdio.h>
#include <cstring>
#include <string>
//struct bign
//{
//	int d[30];
//	int len;
//	bign()
//	{
//		memset(d,0,sizeof(d));
//		len = 0;
//	}
//};
//bign change(char str[])
//{
//	bign a;
//	int len = strlen(str);
//	for()
//
//	return a;
//}
//void cut(bign z,bign &a,bign &b);//z to a b
//

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		unsigned int a;
		scanf("%ud",&a);
		unsigned int m = a;
		int num[40];
		int c[20],b[20];
		int len = 0;
		int numb = 0,numc = 0;
		do
		{
			num[len++] = a % 10;
			a /= 10;
		}while(a != 0);
		for(int i = 0;i < len / 2 ;++i)
		{
			b[i] = num[i];
			c[i] = num[i + len / 2];

		}
		int radix = 1;
		for(int i = 0;i < len / 2;++i)
		{

			numb = numb + b[i] * radix;
			numc = numc + c[i] * radix;
			radix *= 10;
		}
		/*printf("%d  %d\n",numb,numc);*/
		if(numb == 0 || numb == 0)
			printf("No\n");
		else
		{
			int temp = m / numb / numc;
		/*	printf("temp:%d \n",temp);*/
			temp = temp * numb * numc;
			/*printf("temp:%d \n",temp);*/
			if( temp == m)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}


#include<stdio.h>
/*
	for(int i = 0 ;i < n1; ++i)
	scanf("%d",&);
	printf("",);
*/
int main()
{
	int b,N,z[40],num = 0;
	scanf("%d %d", &N, &b);
	do
	{
		z[ num++ ] = N % b;
		N = N / b;
	
	}while(N != 0);
	int i = 0,j = num - 1,flag = 1;
	while(i <= j)//judge
	{
		if(z[i] != z[j])
			flag = 0;
		++i;
		--j;
	}
	if(flag == 0)
		printf("No\n");
	else 	printf("Yes\n");
	for(i = num - 1; i>= 0; --i)
	{
		if(i != num -1)
			printf(" ");
		printf("%d",z[i]);
	}


		





	return 0;
}


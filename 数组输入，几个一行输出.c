# include<stdio.h>
# include<string.h>
# define M 8	//���滻 

int main()
{
	int a[M], *p, i;
	for(p = a;p < a + M;p++)//�������� 
	{
		scanf("%d",p);
	}
	printf("\noutput:\n");
	for(i = 0;i < M;i++)//���һ����� 
	{
		printf("%4d%c", a[i], (i + 1) % 5 == 0 ? '\n' : ' ');
	}
	
	return 0;
 } 

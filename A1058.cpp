
#include<stdio.h>
/*
  for(int i = 0 ;i < n1; ++i)
  scanf("%d",&);
  printf("",);
*/
int main()
{
	int a[3],b[3],c[3];
	int temp = 0;
	scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
	scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
	c[2] = ( a[2] + b[2] ) % 29;
	if( (a[2] + b[2]) > 28 ) temp = 1;
	c[1] = ( a[1] + b[1] + temp ) % 17;
	if( a[1] + b[1] + temp > 16 ) temp = 1;
	else temp = 0;
	c[0] = a[0] + b[0] +temp;	
	
	printf("%d.%d.%d",c[0],c[1],c[2]);
	return 0;
}

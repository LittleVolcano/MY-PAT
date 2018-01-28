#include<stdio.h>
//数位处理
//如果逆序后第一位是零也要输出的话，就要每个位处理完执行一次printf 
int main()
{
	int num;
	scanf("%d",&num);
	int A,B,C;
	A = num / 100;
	B = num % 100 / 10;
	C = num % 10;
	num = A + B * 10 + C * 100;
	printf("%d",num);
	
	return 0;
}

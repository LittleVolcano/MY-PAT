#include<stdio.h>
//��λ����
//���������һλ����ҲҪ����Ļ�����Ҫÿ��λ������ִ��һ��printf 
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

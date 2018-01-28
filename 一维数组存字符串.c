#include<stdio.h>
#include<string.h>
#define M 40
int main()
{

	char b[M];
	char *c;
	
	char a[] = "hello world!";
//	char *q, *p = "hi world!";
//	
//	q = b;
//	
//	scanf("%s",q);//读到空格和回车都结束	后边输出项是指针的话得先把指针指到一个足够的空间上，这里指向了b数组 
//	puts(a);//输出结束有回车 
//	puts(p);
//	puts(q);
//	printf("%s",a);//输出结束不带回车 
//	printf("%s",p);
//	printf("%s",q);	
//	
//	printf("\n%s",b);
	gets(c);//从键盘输入数据，直到第一个\0 存在地址为c的地方，即c为指针或者数组名 
	puts(c);
	return 0;
}

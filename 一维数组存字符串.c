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
//	scanf("%s",q);//�����ո�ͻس�������	����������ָ��Ļ����Ȱ�ָ��ָ��һ���㹻�Ŀռ��ϣ�����ָ����b���� 
//	puts(a);//��������лس� 
//	puts(p);
//	puts(q);
//	printf("%s",a);//������������س� 
//	printf("%s",p);
//	printf("%s",q);	
//	
//	printf("\n%s",b);
	gets(c);//�Ӽ����������ݣ�ֱ����һ��\0 ���ڵ�ַΪc�ĵط�����cΪָ����������� 
	puts(c);
	return 0;
}

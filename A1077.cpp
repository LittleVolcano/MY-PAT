
#include <cstdio>
#include <stdio.h>
#include <cstring>
char s[110][300];

int main()
{
	int n,minlen = 300,len;
	int pos = 0;
	scanf("%d",&n);
	getchar();
	for(int i = 0; i < n; ++i)
	{
		gets(s[i]);
		len = strlen(s[i]);
		if(len < minlen)
			minlen = len;
		for(int j = 0; j < len / 2; ++j )//��ת�ַ�����
		{
			char temp = s[i][j];
			s[i][j] = s[i][len - 1 - j];
			s[i][len - 1 - j] = temp;
		}
	}
	for(int i = 0; i < minlen; ++i)//����λ�õ�ѭ��
	{
		int flag = 1;
		char c = s[0][i];
		for(int j = 0; j < n; ++j )//���Ƶڼ��������ѭ��
		{
			if(c != s[j][i])
			{
				flag = 0;
				break;
			}

		}
		if(flag == 1)//��¼��ͬ���м�λ
			++pos;
		else break;
		
	}
		

	if(pos == 0 )
		printf("nai");
	else 
	{
		for(int i = pos - 1 ;i >= 0; --i)
			printf("%c",s[0][i]);
	}
	return 0;
}


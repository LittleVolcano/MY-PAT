
#include <stdio.h>

int main()
{
	char color[5]={'S','H','C','D','J'};
	int i,j,n;
	int old[55],ne[55],l[55];
	for(i = 1;i <= 54; ++ i)//��ʼ����������
		old[i] = ne[i] = l[i] = i;
	scanf("%d",&n);//ѭ������
	for(i = 1;i <= 54; ++ i)//��������õ�����
		scanf("%d",&l[i]);
	//���ο�ʼ
	for(i = 1;i <= n; ++ i)//����ѭ������
	{
		for(j = 1;j <= 54; ++ j)//����
			ne[l[j]] = old[j];
		for(j = 1;j <= 54; ++ j)//����һ�ΰѱ�õ����·ŵ�old��Ϊ�´���ѭ����׼��
			old[j] = ne[j];

	}
	//�����ʼ
	for(i = 1;i <= 54; ++ i)
	{
		if(i != 1)
			printf(" ");
		--ne[i];//Ϊƥ�仨ɫ�Ͷ�Ӧ����
		printf("%c%d",color[ne[i]/13],ne[i] % 13 +1);
		
	}
	return 0;
}


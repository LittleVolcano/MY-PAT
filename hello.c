#include<stdio.h>
int main()
{
	const int amount = 100;//const ��һ�����η�����ʾ��ߵı�����ʼ����Ͳ��ܸ��� 
	int price;//����������ı��������������κεط���VC++6�����ܣ�����Ҫע�� 
	printf("�������Ԫ����");	
	scanf("%d", &price);			//���뺯�� ���������������� 
	//scanf�еĶ�������Ҫ����Ķ����������Ǹ��㿴�� 
	int change = amount - price;
	printf("����%dԪ��\n",change);
	
	return;
	//����������ʱ%lf  ���ʱ%f 
}

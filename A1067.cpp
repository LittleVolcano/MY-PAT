
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,num;
	int temp;//��¼0��λ��
	int k = 1;//��¼�׸����ڱ�λ��Ԫ��
	int a[100010];//a��˳���¼����
	int pos[100010];//pos��¼����������ڵ�λ��
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		pos[a[i]] = i;
	}
	while(k < n)
	{
		if(pos[0] != 0)
		{
			swap( pos[0],a[ a[0] ] );
		}
			
		else
			swap( a[0], );
	}	
	return 0;
}


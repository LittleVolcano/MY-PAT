
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,num;
	int temp;//记录0的位置
	int k = 1;//记录首个不在本位的元素
	int a[100010];//a按顺序记录数字
	int pos[100010];//pos记录这个数字所在的位置
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



#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,m;
	int sum = 0;
	int a[10010],b[100010];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d",&b[i]);
	}
	sort( a , a + n );
	sort( b , b + m );
	int k = 0;
	while( a[k] < 0 && b[k] < 0 && k < m && k < n )
	{
		sum +=  a[k] * b[k];
		++k;
	}
	k = 1;
	while( a[n-k] > 0 && b[m-k] > 0 && n-k >= 0 && m-k >= 0 )
	{
		sum +=  a[n-k] * b[m-k] ;
		++k;
	}
	printf("%d",sum);
	return 0;
}


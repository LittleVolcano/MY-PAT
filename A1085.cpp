
#include <algorithm>
#include<stdio.h>
using namespace std;
int n;
int a[100010];
int binarysearch(int i,long long x)
{
	if(a[n - 1] <= x )
		return n;
	int l = i+1,r = n-1,mid;
	while(l < r)
	{
		mid = (l + r)/2;
		if(a[mid] <= x )
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

int main()
{

	
	long long p;
	scanf("%d%d",&n,&p);
	for(int i = 0;i < n;++i)
	{
		scanf("%d",&a[i]);
	}
	sort( a,a + n );
	int ans = 1;
	for(int i = 0; i < n; ++i)
	{
		int j=binarysearch(i,(long long)a[i]*p);//
		if(ans < j - i)
			ans = j - i;
	}
	printf("%d\n",ans);
	return 0;
}


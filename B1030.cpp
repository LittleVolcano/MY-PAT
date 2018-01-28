#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int maxn = 100010;
int n,p,a[maxn];
int main() {
	scanf("%d%d",&n, &p);
	for(int i = 0;i < n; ++i ){
		scanf("%d",&a[i]);
	}
	sort(a, a+n);
	int ans = 1;
	for(int i=0;i < n;++i){
		int j = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
		ans = max(ans, j - i);
	}
	printf("%d\n",ans);
	return 0;
}	

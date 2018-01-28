#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int maxn = 100010;
int a[maxn],dis[maxn];
int main() {
	int n,m,left,right;
	scanf("%d", &n);
	int sum = 0;
	a[0] = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
		dis[i] = sum;
	}
	scanf("%d",&m);
	for(int i = 0;i < m; ++i){
		scanf("%d %d",&left, &right);
		if(left > right) swap(left,right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n",min(temp,sum - temp));
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int n,money,a[100010],sum[100010];
	sum[0] = 0;
	int near = 100000010;
	scanf("%d %d", &n, &money);
	for(int i = 1; i <= n;++i){
		scanf("%d",&a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = 1;i <= n;++i){
		int* right1 = lower_bound(sum+i,sum+n+1,sum[i-1] + money);//查找右端点,返回的是指针！！ 
		int right = right1 - sum;//地址－地址等于下标 
		if((sum[right] - sum[i - 1])== money){
			near = money;
			break;
		}
		else if(right <= n && sum[right] - sum[i - 1] < near){
			near = sum[right] - sum[i - 1];
		}
	}
	for(int i = 1;i <= n;++i){
		int* right1 = lower_bound(sum+i,sum+n+1,sum[i-1] + near);//查找右端点,返回的是指针！！ 
		int right = right1 - sum;
		if((sum[right] - sum[i - 1])== near){
			printf("%d-%d\n", i, right);
		}
	}
	return 0;
}

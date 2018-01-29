#include <iostream>
const int maxn = 1000010;
const int INF = 0x7fffffff;
int n,m;
int S1[maxn],S2[maxn];
int main(int argc, char** argv) {
	scanf("%d", &n);
	for(int i = 0;i < n;++i){
		scanf("%d", &S1[i]);
	}
	scanf("%d", &m);
	for(int i = 0;i < m;++i){
		scanf("%d", &S2[i]);
	}
	S1[n] = S2[m] = INF;
	int left =( m + n - 1 ) / 2;
	int i = 0,j = 0;
	while(left--){//中位数左边的处理好 
		if(S1[i] <= S2[j]){
			++i;
		}
		else{
			++j;
		}
	} 
	if(S1[i] <= S2[j]){
		printf("%d\n", S1[i]);
	}else{
		printf("%d\n", S2[j]);
	}
	
	return 0;
}

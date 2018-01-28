#include <iostream>
int hash[110] = {0};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n,score,k;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i){
		scanf("%d",&score);
		hash[score]++;
	}
	scanf("%d",&k);
	for(int i = 0;i < k; ++i){
		scanf("%d",&score);
		printf("%d", hash[score]);
		if(i < k - 1)
			printf(" ");
	}
	return 0;
}

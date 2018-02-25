#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n;
int index = 0,num[maxn] = {0}, CBT[maxn] = {0};
void inOrder(int root){
	if(root > n){
		return;
	}
	inOrder(2 * root);
	CBT[root] = num[index++];
	inOrder(2 * root + 1);
}
int main(int argc, char** argv) {

	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&num[i]);
	}
	sort(num, num + n);
	inOrder(1);
	for(int i = 1;i <= n;i++){
		printf("%d",CBT[i]);
		if(i < n){
			printf(" ");
		}
	}
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn];
int rootCount[maxn] = {0};
int hobby[maxn] = {0};
bool cmp(int a, int b){
	return a > b;
}
void init(){
	for(int i = 0;i < maxn;i++){
		father[i] = i;
	}
} 
int findFather(int root){
	int b = root;
	while(root != father[root]){
		root = father[root];
	}
	//Â·¾¶Ñ¹Ëõ
	while(b != father[b]){
		int c = b;
		father[c]= root;
		b = father[b];
	}
	return root;
}
void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}
int main(int argc, char** argv) {
	int n, k, x;
	scanf("%d",&n);
	init();
	for(int i = 1;i <= n;i++){
		scanf("%d:", &k);
		for(int j = 0;j < k;j++){
			scanf("%d", &x);
			if(hobby[x] == 0){
				hobby[x] = i;
			}else{
				Union(i, hobby[x]);//
			}
		}
	}
	for(int i = 1;i <= n;i++){
		rootCount[findFather(i)]++;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(rootCount[i] != 0){
			cnt++;
		}
	}
	printf("%d\n", cnt);
	sort(rootCount + 1,rootCount + n + 1, cmp);
	for(int i = 1;i <= cnt;i++){
		printf("%d",rootCount[i]);
		if(i < cnt){
			printf(" ");
		}
	}
	return 0;
}

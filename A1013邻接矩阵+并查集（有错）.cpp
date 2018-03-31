#include <iostream>
const int maxn = 1010;
int n,m,k;
int num,temp;
int father[maxn];
bool set[maxn] = {false};
int graph[maxn][maxn] = {0};//from 1 to N
void init(){
	num = 0;
	for(int i = 1;i <= n;i++){
		father[i] = i;
		set[i] = false;
	}
}
int getFather(int a){
	int x = a;
	while(father[a] != a){//aÊÇ¸ù 
		a = father[a];
	}
	
	while(x != father[x]){//Â·¾¶Ñ¹Ëõ 
		int z = x;
		x = father[x];
		father[z] = a;
	}
	return a;
}
void Union(int a, int b){
	int afather,bfather; 
	afather = getFather(a);
	bfather = getFather(b);
	if(afather != bfather){
		father[a] = b;
	}
}
int main(int argc, char** argv) {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0;i < m;i++){
		int a,b;
		scanf("%d%d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	
	}
	for(int q = 0;q < k;q++){
		scanf("%d", &temp);
		init();
		for(int i = 1;i <= n;i++){
			if(i != temp){
				for(int j = 1; j <= n;j++){
					if(j != temp && graph[i][j] == 1){
						Union(i,j);
					}
				}
			}	
		}
//		for(int i = 1;i <= n; i++){
//			printf("%d %d %d\n", i, father[i], set[i]);
//		}
//		printf("*************************\n");
		for(int i = 1;i <= n; i++){
			if(set[father[i]] == false && i != temp){
				num++;
				set[father[i]] = true;
			}
		}
		printf("%d\n",num-1);
	}
	return 0;
}

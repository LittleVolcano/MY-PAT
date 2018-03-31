#include <iostream>
const int maxn = 1010;
int n,m,k,a,b;
int num,temp;
bool set[maxn];
int graph[maxn][maxn] = {0};//from 1 to N
void DFS(int v){
	set[v] = true;
	for(int i = 1;i <= n;i++){
		if(graph[v][i] == 1 && set[i] == false && i != temp){
			DFS(i);
		}
	}
}
void allDFS(int temp){
	for(int i = 1;i <= n;i++){
		if(i != temp && set[i] == false){	//haven't visited
			num++;
			DFS(i);	
		}
	}
}
int main(int argc, char** argv) {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0;i < m;i++){
		scanf("%d%d", &a, &b);
		graph[b][a] = 1;
		graph[a][b] = graph[b][a];
	}
	for(int i = 0;i < k;i++){
		for(int j = 1;j <= n;j++){
			set[j] = false;
		}
		num = 0;
		scanf("%d", &temp);
		allDFS(temp);
		printf("%d\n",num-1);
	}
	return 0;
}

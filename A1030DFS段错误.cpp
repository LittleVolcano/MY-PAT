#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int n,m,st,ed,G[maxn][maxn],cost[maxn][maxn];
bool vis[maxn] = {false};
int pre[maxn],minDist[maxn],minCost[maxn];
void Dijkstra(int s){
	fill(pre, pre + maxn, INF);//
	fill(minDist, minDist + maxn, INF);
	fill(minCost, minCost + maxn, INF);
	minDist[s] = 0;
	minCost[s] = 0;
	for(int i = 0;i < n;i++){
		int u = -1,MIN = INF;
		for(int j = 0;j < n;j++){
			if(minDist[i] < MIN && vis[j] == false){
				MIN = minDist[j];
				u = j;
			}
		}
		if(u == -1)return;
		vis[u] = true;
		for(int v = 0; v < n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(minDist[u] + G[u][v] < minDist[v]){
					pre[v] = u;
					minDist[v] = minDist[u] + G[u][v];
					minCost[v] = minCost[u] + cost[u][v];
				}else if(minDist[u] + G[u][v] == minDist[v] && minCost[u] + cost[u][v] < minCost[v]){
					minCost[v] = minCost[u] + cost[u][v];
					pre[v] = u;
				}
			}
		}		
	}
}
void DFS(int x){
	if(x == st){
		printf("%d ",x);
		return;
	}
	DFS(pre[x]);
	printf("%d ",x);
}
int main(int argc, char** argv) {
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	fill(G[0],G[0] + maxn * maxn, INF);
	for(int i = 0;i < m;i++){
		int u,v;
		scanf("%d %d", &u, &v);
		scanf("%d %d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
//	for(int i = 0;i < 20;i++){//
//		printf("%d-%d\n",i,pre[i]);
//	}
	DFS(ed);
	printf("%d %d\n", minDist[ed], minCost[ed]);
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int cmax,m,n,sp,G[maxn][maxn];
int weight[maxn],dis[maxn];
int minRemain = INF,minNeed = INF;
vector<int> pre[maxn];
vector<int> path,tempPath;
bool vis[maxn] = {false};
void DFS(int v){
	int good = cmax/2;
	if(v == 0){
		tempPath.push_back(v);
		int need = 0,remain = 0;
		//这里是最重要的一步，管理站不做处理的话会在走完初始站后打乱need的值
		//要么初始化管理站为good，要么从tempPath.size()-2开始遍历，不遍历管理站，即最后一个 
		weight[0] = good;
		for(int i = tempPath.size()-1;i >= 0;i--){
			int id = tempPath[i];
			if(weight[id] > good){//该站多了 
				remain += weight[id] - good;
			}else if(weight[id] < good){//少了 
				if(remain > good - weight[id]){//少了但是手头的能够用 
					remain -= good - weight[id];
				}else {//少了且不够用 
					need += (good - weight[id] - remain);
					remain = 0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		} else if(need == minNeed && remain < minRemain){
			minRemain = remain;
			path = tempPath;
		}
		tempPath.pop_back();
		return; 
	}
	tempPath.push_back(v);
	for(int i = 0;i < pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
void Dijkstra(int v){
	fill(dis, dis + maxn,INF);
	dis[v] = 0;
	for(int i = 0;i <= n;i++){
		int u = -1,min = INF;
		for(int j = 0;j < n;j++){
			if(vis[j] == false && dis[j] < min){
				u = j;
				min = dis[j];
			}
		}
		if(u == -1)return;
		vis[u] = true;
		for(int v = 0;v <= n; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(dis[u] + G[u][v] < dis[v]){
					dis[v] = dis[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(dis[u] + G[u][v] == dis[v]){
					pre[v].push_back(u);
				}
			}
		}		
	}
}
int main(int argc, char** argv) {
	fill(G[0],G[0] + maxn * maxn, INF);
	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &weight[i]);
	}
	for(int i = 0;i < m;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		scanf("%d", &G[a][b]);
		G[b][a] = G[a][b];
	}
	Dijkstra(0);
	DFS(sp);
	printf("%d ",minNeed);
	for(int i = path.size()-1;i >= 0 ;i--){
		printf("%d", path[i]);
		if(i > 0)printf("->");
	}
	printf(" %d", minRemain);
	return 0;
}

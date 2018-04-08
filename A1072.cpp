#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1020;
const int INF = 100000000;
int G[maxn][maxn];
int n,m,k,ds,u,v,w;
char city1[5],city2[5];
bool vis[maxn] = {false};
int dis[maxn];
void Dijkstra(int s){
	memset(vis,false,sizeof(vis));
	fill(dis, dis + maxn, INF);
	dis[s] = 0;
	for(int i = 0;i < n + m; i++){
		int u = -1, min = INF;
		for(int j = 1;j <= n + m ;j++){
			if(dis[j] < min && vis[j] == false){
				u = j;
				min = dis[j];
			}
		}
		if(u == -1)return;
		vis[u] = true;
		for(int v = 1; v <= n + m;v++){
			if(vis[v] == false && G[u][v] != INF){
				if(dis[u] + G[u][v] < dis[v]){
					dis[v] = dis[u] + G[u][v];
				}
			}
		}
	}
}
int getID(char str[]){
	int len = strlen(str);
	int id = 0;
	for(int i = 0;i < len; i++){
		if(str[i] != 'G'){
			id = id * 10 + (str[i] - '0');
		}
	}
	if(str[0] == 'G')return n + id;
	else return id;
}
int main(int argc, char** argv) {
	fill(G[0], G[0] + maxn * maxn, INF);
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for(int i = 0;i < k;i++){
		scanf("%s %s %d", city1, city2, &w);
		u = getID(city1);
		v = getID(city2);	
		G[u][v] = G[v][u] = w;
	}
	double ansDis = -1, ansAvg = INF;
	int ansID = -1;
	for(int i = n + 1; i <= n + m;i++){
		double minDis = INF,avg = 0;
		Dijkstra(i);
		for(int j = 1;j <= n;j++){
			if(dis[j] > ds){//超过服务范围，无解 
				minDis = -1;
				break;
			}
			if(dis[j] < minDis){
				minDis = dis[j];
			}
			avg += 1.0 * dis[j] / n;
		}
		if(minDis == -1)continue;
		if(minDis > ansDis){
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}else if(minDis == ansDis && avg < ansAvg){
			ansID = i;
			ansAvg = avg;
		}
	}
	if(ansID == -1)
		printf("No Solution\n");//一个大写S找错找了两个小时 
	else{
		printf("G%d\n", ansID - n);
		printf("%.1f %.1f\n", ansDis, ansAvg);
	}
	return 0;
}

//图总结
//存储方式——邻接表（多于1000结点的时候），邻接矩阵（用于小于1000个结点的时候） 
//本部分内容主要有：
//1.DFS和BFS（分别用邻接表和邻接矩阵写）
//常见问题：计算连通子图个数，除了用DFS还可以用并查集 
//2.dijkstra(两种存储方式写)
//3.输出dijkstra算法的最短路径（用DFS递归打印）
//4.长度相同时，第二标尺（边权，点权，条数）（都是只在更新的for循环里修改）
//5.Dijkstra+DFS:第二标尺比较复杂时，用Dijkstra计算最短路径，用DFS计算第二标尺

//不同点 
//邻接表需要int n，需要INF在if判断时用 
//单个DFS或者BFS的for循环时，邻接矩阵 < n,邻接表到G[v].size() 


//DFS邻接矩阵版	
int G[maxn][maxn];
bool vis[maxn] = false;
int n;//不同
const int INF = 1000000000;//不同 

void DFS(int v) {
	//单个DFS的话要在开始这里设置边界判断if(v == 边界) 
	vis[v] = true;
	op();//对访问点的操作在这里进行 
	for(int i = 0;i < n;i++){
		//用邻接矩阵因为可不可达都会被指到，所以要判断是否可达 
		if(vis[i] == false && G[v][i] != INF){
			DFS(G[v][i]);		
		}
	}	
}
void allDFS(){//邻接表和邻接矩阵相同 
	for(int i = 0;i < n;i++){
		if(vis[i]==false){
			DFS(i);
			cnt++;//连通子图+1 
		}
	}
}

//DFS邻接表版
#include <vector>
using namespace std;
vector<int> G[maxn];//不同，用变长数组不用二维数组 
bool vis[maxn] = false;
void DFS(int v){
	vis[v] = true;
	op();
	for(int i = 0;i < G[v].size(); i++){
		int temp = G[v][i];//多这步 
		if(vis[temp] == false){//不同 
			DFS(int temp);
		}
	}
}
void allDFS(){//邻接表和邻接矩阵相同 
	for(int i = 0;i < n;i++){
		if(vis[i]==false){
			DFS(i);
			cnt++;//连通子图+1 
		}
	}
}

//BFS邻接矩阵版
#include<queue>
using namespace std;
int G[maxn][maxn];
bool vis[maxn] = {false};
void BFS(int v){
	queue<int> q;
	q.push(v);
	vis[v] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0;i < n;i++){
			if(vis[i]==false && G[u][i] != INF){
				vis[i] = true;
				q.push(i);
			}
		}
	}
}
void allBFS(){
	for(int i = 0;i < n; i++){
		if(vis[i] == false){
			BFS(i);
			cnt++;
		}
	}
} 

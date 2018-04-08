//ͼ�ܽ�
//�洢��ʽ�����ڽӱ�����1000����ʱ�򣩣��ڽӾ�������С��1000������ʱ�� 
//������������Ҫ�У�
//1.DFS��BFS���ֱ����ڽӱ���ڽӾ���д��
//�������⣺������ͨ��ͼ������������DFS�������ò��鼯 
//2.dijkstra(���ִ洢��ʽд)
//3.���dijkstra�㷨�����·������DFS�ݹ��ӡ��
//4.������ͬʱ���ڶ���ߣ���Ȩ����Ȩ��������������ֻ�ڸ��µ�forѭ�����޸ģ�
//5.Dijkstra+DFS:�ڶ���߱Ƚϸ���ʱ����Dijkstra�������·������DFS����ڶ����

//��ͬ�� 
//�ڽӱ���Ҫint n����ҪINF��if�ж�ʱ�� 
//����DFS����BFS��forѭ��ʱ���ڽӾ��� < n,�ڽӱ�G[v].size() 


//DFS�ڽӾ����	
int G[maxn][maxn];
bool vis[maxn] = false;
int n;//��ͬ
const int INF = 1000000000;//��ͬ 

void DFS(int v) {
	//����DFS�Ļ�Ҫ�ڿ�ʼ�������ñ߽��ж�if(v == �߽�) 
	vis[v] = true;
	op();//�Է��ʵ�Ĳ������������ 
	for(int i = 0;i < n;i++){
		//���ڽӾ�����Ϊ�ɲ��ɴﶼ�ᱻָ��������Ҫ�ж��Ƿ�ɴ� 
		if(vis[i] == false && G[v][i] != INF){
			DFS(G[v][i]);		
		}
	}	
}
void allDFS(){//�ڽӱ���ڽӾ�����ͬ 
	for(int i = 0;i < n;i++){
		if(vis[i]==false){
			DFS(i);
			cnt++;//��ͨ��ͼ+1 
		}
	}
}

//DFS�ڽӱ��
#include <vector>
using namespace std;
vector<int> G[maxn];//��ͬ���ñ䳤���鲻�ö�ά���� 
bool vis[maxn] = false;
void DFS(int v){
	vis[v] = true;
	op();
	for(int i = 0;i < G[v].size(); i++){
		int temp = G[v][i];//���ⲽ 
		if(vis[temp] == false){//��ͬ 
			DFS(int temp);
		}
	}
}
void allDFS(){//�ڽӱ���ڽӾ�����ͬ 
	for(int i = 0;i < n;i++){
		if(vis[i]==false){
			DFS(i);
			cnt++;//��ͨ��ͼ+1 
		}
	}
}

//BFS�ڽӾ����
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

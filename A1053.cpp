#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 110;
struct node{
	int data;
	vector<int> child;
}NODE[maxn];
bool cmp(int a, int b){
	return NODE[a].data > NODE[b].data;
}
int n, m, s;
int path[maxn];
void DFS(int index, int num,int sum){//正在处理的节点号，深度，权和 
	if(sum > s) return;
	if(sum == s){
		if(NODE[index].child.size() != 0){
			return;
		}
		else{//是满足的路径末尾 
			for(int i = 0; i < num; i++){
				printf("%d", NODE[path[i]].data);
				if(i < num - 1)printf(" ");
				else printf("\n");
			}
			return;
		}
	}
	for(int i = 0;i < NODE[index].child.size();i++){//节点数还不够 
		int child = NODE[index].child[i];
		path[num] = child;
		DFS(child, num + 1, sum + NODE[child].data);
	}
}
int main(int argc, char** argv) {
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0;i < n;i++){
		scanf("%d", &NODE[i].data);
	}
	int id, k, child;
	for(int i = 0;i < m;i++){
		scanf("%d%d", &id, &k);
		for(int j = 0;j < k;j++){
			scanf("%d", &child);
			NODE[id].child.push_back(child);
		}
		sort(NODE[id].child.begin(),NODE[id].child.end(),cmp);
	}
	path[0] = 0;
	DFS(0, 1, NODE[0].data);
	
	return 0;
}

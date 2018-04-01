#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//16:18
const int maxn = 10010;
int n;
int nowdepth = 1;
vector<int> G[maxn];
vector<int> temp,ans;
int father[maxn];
bool set[maxn] = {false};
bool isRoot[maxn] = {false};
void init(){
	for(int i = 1;i <= n;i++){
		father[i] = i;
	}
}
void initSet(){
	for(int i = 1;i <= n;i++){
		set[i] = false;
	}
}
int findFather(int a){
	int x = a;
	while(a != father[a]){//a is root 
		a = father[a];
	}
	while(x != father[x]){
		int z = x;//z is father
		x = father[x];
		father[z] = a;
	}
	return a;
}
int Union(int a, int b){
	int fa,fb;
	fa = findFather(a);
	fb = findFather(b);
	if(fa != fb){
		father[fa] = fb;//合并根节点才有效 
	}
}
int cnt(int n){
	int num = 0;
	for(int i = 1 ;i <= n;i++){
		isRoot[findFather(i)] = true;
	}
	for(int i = 1 ;i <= n;i++){
		num += isRoot[i];
	}
	return num;
}
void DFS(int v,int depth){//一定无环的连通图了 
	set[v] = true;
	if(depth > nowdepth){
		temp.clear();
		temp.push_back(v);
		nowdepth = depth;
	}else if(depth == nowdepth){
		temp.push_back(v);
	}
	for(int i = 0;i < G[v].size();i++){
		if(set[G[v][i]] == false){
			DFS(G[v][i],depth + 1);
		}
	}
}
int main(int argc, char** argv) {
	int a,b;
	scanf("%d", &n);
	init();
	for(int i = 1;i < n;i++){
    	scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a, b);
	}
	int num = cnt(n);
	if(num != 1){
		printf("Error: %d components\n", num);
	}else{
		DFS(1,1);
		ans = temp;
		initSet();
		temp.clear();
		DFS(ans[0],1);//容器的第一个元素是从0开始的 
		for(int i = 0;i < temp.size();i++){
			ans.push_back(temp[i]);
		}
		sort(ans.begin(), ans.end());
		printf("%d\n", ans[0]);
		for(int i = 1;i < ans.size();i++){
			if(ans[i] != ans[i - 1]){
				printf("%d\n",ans[i]);
			}
		}	
	}
	return 0;
}

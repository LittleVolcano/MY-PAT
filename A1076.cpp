#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
struct NODE{
	int id;
	int layer;
};
using namespace std;
const int maxn = 1010;
vector<NODE> G[maxn];
int n,l,num;
int foll,temp;
int k;
bool set[maxn] = {false};
void BFS(int v,int l){
	queue<NODE> q;
	NODE first;
	first.id = v;
	first.layer = 0;
	q.push(first);
	set[first.id] = true;
	while(!q.empty()){
		NODE temp = q.front();
		q.pop();
		int now = temp.id;
		for(int i = 0;i < G[now].size();i++){
			NODE next = G[now][i];
			next.layer = temp.layer + 1;
			if(set[next.id]==false && next.layer <= l){
				q.push(next);
				set[next.id] = true;
			}
		}
	}
}
int cnt(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		cnt += set[i];
	}
	return cnt;
}
int main(int argc, char** argv) {
	scanf("%d %d", &n, &l);
	for(int i = 1;i <= n; i++){
		scanf("%d", &num);
		for(int j = 0;j < num;j++){
			NODE user;
			user.id = i;
			scanf("%d",&foll);
			G[foll].push_back(user);
		}
	}
	scanf("%d", &k);
	for(int i = 0;i < k;i++){
		scanf("%d", &temp);
//		initSet();
		memset(set,false,sizeof(set));//use cstring
		BFS(temp,l);
		printf("%d\n",cnt()-1);
	}
	return 0;
}

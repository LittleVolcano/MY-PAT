#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
vector<int> NODE[maxn];
int leaf[maxn];
int maxH = 1;
void DFS(int index, int depth){
	maxH = max(depth,maxH);
	if(NODE[index].size() == 0){
		leaf[depth]++;
		return;//待会试一下用不用return用else 
	}
	for(int i = 0;i < NODE[index].size();i++){
		DFS(NODE[index][i], depth + 1);
	}
}
int main(int argc, char** argv) {
	int n, m, father, child, k;
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		scanf("%d%d", &father, &k);
		for(int j = 0;j < k;j++){
			scanf("%d", &child);
			NODE[father].push_back(child);
		}
	}
	DFS(1,1);
	printf("%d", leaf[1]);
	for(int i = 2;i <= maxH;i++){
		printf(" %d", leaf[i]);
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;
const int maxn = 110;
vector<int> NODE[maxn];
int hashTable[maxn] = {0};
void DFS(int index, int level){
	hashTable[level]++;
	for(int i = 0;i < NODE[index].size();i++){
		DFS(NODE[index][i], level + 1);
	}
}
int main(int argc, char** argv) {
	int n, m, parent, k, child;
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		scanf("%d%d", &parent, &k);
		for(int j = 0;j < k;j++){
			scanf("%d", &child);
			NODE[parent].push_back(child);
		}
	}
	DFS(1, 1);
	int maxLevel = -1,maxValue = 0;
	for(int i = 0;i < maxn;i++){
		if(hashTable[i] > maxValue){
			maxLevel = i;
			maxValue = hashTable[i];
		}
	}
	printf("%d %d\n", maxValue, maxLevel);
	return 0;
}

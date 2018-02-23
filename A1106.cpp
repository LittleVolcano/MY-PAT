#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, depth = 0;
double p, r;
const int maxn = 100010;
vector<int> NODE[maxn];
int minDepth = 100010, num = 0;
void DFS(int index, int depth){
	if(NODE[index].size() == 0){//递归边界，到了叶节点 
		if(depth < minDepth){
			minDepth = depth;
			num = 1;
		}else if(depth == minDepth){
			num++;
		}
		return;
	}
	for(int i = 0;i < NODE[index].size();i++){//不是叶节点，访问每一个子节点 
		DFS(NODE[index][i], depth + 1);
	}
}

int main(int argc, char** argv) {
	int k,child;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0;i < n;i++){
		scanf("%d", &k);
		for(int j = 0;j < k;j++){
			scanf("%d", &child);
			NODE[i].push_back(child);
		}
	}
	DFS(0, 0);
	printf("%.4f %d\n", p * pow(1 + r, minDepth), num);
	return 0;
}

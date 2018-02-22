#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double p, r;
int n;
int maxDepth = 0, num = 0;
const int maxn = 100010;
vector<int> child[maxn];
void DFS(int index, int depth){
	if(child[index].size() == 0){//递归边界，到了叶节点 
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1;
		}else if(depth == maxDepth){
			num++;
		}
		return;
	}
	for(int i = 0;i < child[index].size();i++){//不是叶节点，访问每一个子节点 
		DFS(child[index][i], depth + 1);
	}
}

int main(int argc, char** argv) {
	int father, root;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0;i < n;i++){
		scanf("%d", &father);
		if(father != -1){
			child[father].push_back(i);
		}else{
			root = i;
		}
	}
	DFS(root, 0);
	printf("%.2f %d\n", p * pow(1 + r, maxDepth), num);
	return 0;
}

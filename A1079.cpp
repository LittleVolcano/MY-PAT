#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, depth = 0;
double p, r, sum = 0;
const int maxn = 100010;
struct node{
	int data;
	vector<int> child;
}NODE[maxn];

void DFS(int index, int depth){
	if(NODE[index].child.size() == 0){//递归边界，到了叶节点 
		sum += NODE[index].data * pow(1 + r, depth);
		return;
	}
	for(int i = 0;i < NODE[index].child.size();i++){//不是叶节点，访问每一个子节点 
		DFS(NODE[index].child[i], depth + 1);
	}
}

int main(int argc, char** argv) {
	int k,child;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0;i < n;i++){
		scanf("%d", &k);
		if(k == 0){
			scanf("%d",&NODE[i].data);
		}else{
			for(int j = 0;j < k;j++){
				scanf("%d", &child);
				NODE[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f\n", p * sum);
	return 0;
}

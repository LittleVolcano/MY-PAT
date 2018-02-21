#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
int n, num = 0;
struct node{
	int lchild,rchild;
}NODE[maxn];
bool isRoot[maxn] = {false};
int findRoot(){
	for(int i = 0;i < n; i++){
		if(isRoot[i] == false)
			return i;
	}
}
void print(int id){
	printf("%d", id);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
}
void inOrder(int root){
	if(root == -1){
		return;
	}
	inOrder(NODE[root].lchild);
	print(root);
	inOrder(NODE[root].rchild);
}
void BFS(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		print(now);
		if(NODE[now].lchild != -1)
			q.push(NODE[now].lchild);
		if(NODE[now].rchild != -1)
			q.push(NODE[now].rchild);
	}
}
void postOrder(int root){
	if(root == -1){
		return;
	}
	postOrder(NODE[root].lchild);
	postOrder(NODE[root].rchild);
	swap(NODE[root].lchild, NODE[root].rchild);	
}
int strTonum(char c){
	if(c == '-'){
		return -1;
	}else{
		isRoot[c - '0'] = true;
		return c - '0';
	}
}
int main(int argc, char** argv) {
	char lchild, rchild;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%*c%c %c",&lchild, &rchild);
		NODE[i].lchild = strTonum(lchild);
		NODE[i].rchild = strTonum(rchild);
	}
	int root = findRoot();
	postOrder(root);
	BFS(root);
	num = 0;
	inOrder(root);
	return 0;
}

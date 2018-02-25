#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
//思路同上一题，建树，排序，用中序遍历赋值，层次遍历 
using namespace std;
const int maxn = 110;
int n, num[maxn] = {0}, index = 0;
int cnt = 1;
struct node{
	int data;
	int lchild, rchild;
}NODE[maxn];
void inOrder(int root){
	if(root >= n){
		return;
	}
	if(NODE[root].lchild != -1){
		inOrder(NODE[root].lchild);	
	}
	NODE[root].data = num[index++];	
	if(NODE[root].rchild != -1){
		inOrder(NODE[root].rchild);	
	}	
}
void levelOrder(int root){
	queue<int> q;
	q.push(root);
	while(q.size() != 0){
		int temp = q.front();
		q.pop();
		printf("%d",NODE[temp].data);
		if(cnt++ < n){
			printf(" ");
		}
		if(NODE[temp].lchild != -1){
			q.push(NODE[temp].lchild);
		}
		if(NODE[temp].rchild != -1){
			q.push(NODE[temp].rchild);
		}		
	}
}
int main(int argc, char** argv) {
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d %d",&NODE[i].lchild,&NODE[i].rchild);
	}
	for(int i = 0;i < n;i++){
		scanf("%d",&num[i]);
	}
	sort(num, num + n);
	inOrder(0);
	levelOrder( 0 );
	return 0;
}

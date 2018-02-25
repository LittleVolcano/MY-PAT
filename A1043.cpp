#include <iostream>
#include <cstdio>
#include <vector>
//输入一个序列建BST，判断另一个序列是不是这个BST的先序遍历或者镜像遍历
//是的话第二行输出这种树的后序遍历 
using namespace std;
struct node{
	int data;
	node* lchild, *rchild;	
};
void insert(node* &root, int x){
	if(root == NULL){
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(root->data <= x){
		insert(root->rchild, x);
	}else{
		insert(root->lchild, x);
	}
}
void preOrder(node* root, vector<int>&vi){
	if(root == NULL){
		return;
	}
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}
void mirrorPreOrdr(node* root, vector<int>&vi){
	if(root == NULL){
		return;
	}
	vi.push_back(root->data);
	mirrorPreOrdr(root->rchild, vi);	
	mirrorPreOrdr(root->lchild, vi);
}
void postOrder(node* root, vector<int>&vi){
	if(root == NULL){
		return;
	}
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);	
}
void mirrorPostOrder(node* root, vector<int>&vi){
	if(root == NULL){
		return;
	}
	mirrorPostOrder(root->rchild, vi);	
	mirrorPostOrder(root->lchild, vi);
	vi.push_back(root->data);	
}
int main(int argc, char** argv) {
	vector<int> origin,pre,preM,post,postM;
	int n, data;
	node* root = NULL;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	preOrder(root, pre);
	postOrder(root, post);
	mirrorPreOrdr(root, preM);	
	mirrorPostOrder(root, postM);
	if(origin == pre){
		printf("YES\n");
		for(int i = 0;i < post.size();i++){
			printf("%d",post[i]);
			if(i != post.size() - 1){
				printf(" ");
			}
		}		
	}else if(origin == preM){
		printf("YES\n");
		for(int i = 0;i < postM.size();i++){
			printf("%d",postM[i]);
			if(i != postM.size() - 1){
				printf(" ");
			}
		}
	}else{
		printf("NO\n");
	}
//
//	for(int i = 0;i < pre.size();i++){
//		printf("%d",pre[i]);
//			if(i != pre.size() - 1){
//				printf(" ");
//			}else{
//				printf("\n");
//			}
//	}
//	for(int i = 0;i < preM.size();i++){
//		printf("%d",preM[i]);
//			if(i != preM.size() - 1){
//				printf(" ");
//			}else{
//				printf("\n");
//			}	
//	}
	return 0;
}

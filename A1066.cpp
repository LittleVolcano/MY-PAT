#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	int data, heigh;
	node *lchild, *rchild;//星跟哪个近有影响吗 
}*root;
node* newNode(int v){
	node* NODE = new node;
	NODE->data = v;
	NODE->lchild = NODE->rchild = NULL;
	NODE->heigh = 1;
	return NODE;
}
int getH(node* root){
	if(root == NULL){
		return 0;
	}
	return root->heigh;
}
void updateH(node* root){
	root->heigh = max(getH(root->lchild),getH(root->rchild)) + 1;//不用getH也可以吧?不行，有null情况 
}
int getBalanceFactor(node* root){
	return getH(root->lchild) - getH(root->rchild);
}
void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateH(root);
	updateH(temp);
	root = temp;
}
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateH(root);
	updateH(temp);
	root = temp;
}
void insert(node* &root, int v){
	if(root == NULL){
		root = newNode(v);
		return;
	}
	if(v < root->data){
		insert(root->lchild, v);
		updateH(root);
		if(getBalanceFactor(root) == 2){
			if(getBalanceFactor(root->lchild) == 1){
				R(root);
			}else if(getBalanceFactor(root->lchild) == -1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild, v);
		updateH(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->rchild) == -1){
				L(root);
			}else if(getBalanceFactor(root->rchild) == 1){
				R(root->rchild);
				L(root);
			}
		}		
	}	
}
int main(int argc, char** argv) {
	int n, v;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", &v);
		insert(root, v);
	}
	printf("%d\n",root->data);//root还没定义 
	return 0;
}

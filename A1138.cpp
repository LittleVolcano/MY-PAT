#include <iostream>
const int maxn = 500010;
int n,pre[maxn],in[maxn];
bool flag = true;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* create(int preL, int preR, int inL, int inR){
	if(preL > preR){
		return NULL;//?NULL
	}
	node* root = new node;
	root->data = pre[preL];
	int k;
	for(k = inL;k <= inR;k++){
		if(in[k] == pre[preL]){
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create( preL + numLeft + 1, preR, k + 1, inR);
	return root;
}
void postOrder(node* root){
	if(root == NULL||flag == false){//开始出错出在没写递归边界 
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	if(flag == true){
		flag = false;
		printf("%d",root->data);		
	}
}
int main(int argc, char** argv) {

	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i = 0;i < n;i++){
		scanf("%d",&in[i]);
	}
	node* root = create( 0, n - 1, 0, n - 1);
	postOrder(root);
	return 0;
}

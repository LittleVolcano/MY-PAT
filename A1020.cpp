#include <iostream>
#include <queue>
using namespace std;
const int maxn = 40;
int in[maxn],post[maxn], n, num = 0;
struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* create(int postL, int postR, int inL, int inR){
	if(postL > postR){
		return NULL;
	}
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k = inL;k < inR;k++){
		if(in[k] == post[postR]){
			break;
		}
	}
	int numleft = k - inL;
	root->lchild = create(postL, postL + numleft - 1, inL, k - 1);
	root->rchild = create(postL + numleft, postR - 1, k + 1, inR);
	return root;
}
void BFS(node* root){
	queue<node*> q;
	q.push(root);//������ô���Զ���ȫ�ˣ�����->�༭��ѡ������ѡһ�δ��벹ȫ�ͺ��ˡ��� 
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num < n){
			printf(" ");
		}
		if(now->lchild != NULL){
			q.push(now->lchild);
		}
		if(now->rchild != NULL){
			q.push(now->rchild);
		}
	}
}
int main(int argc, char** argv) {
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d",&post[i]);
	}
	for(int i = 0;i < n;i++){
		scanf("%d",&in[i]);
	}
	node* root = create(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}

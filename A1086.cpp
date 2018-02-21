#include <iostream>
#include <stack>
#include <cstring>
const int maxn = 50;
using namespace std;
int pre[maxn], in[maxn], post[maxn];
int n;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* create(int preL, int preR, int inL, int inR){
	if(preL > preR){
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k;
	for(k = inL;k <= inR;k++){
		if(pre[preL] == in[k]){
			break;
		}
	}
	int numleft = k - inL;
	root->lchild = create(preL + 1, preL + numleft, inL, k - 1);
	root->rchild = create(preL + numleft + 1, preR, k + 1, inR);
	return root;
}
int num = 0;
void postorder(node* root){
	if(root == NULL){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d",root->data);
	num++;
	if(num < n){
		printf(" ");
	}
	
}
int main(int argc, char** argv) {
	scanf("%d",&n);
	char str[5];
	stack<int> st;
	int x, preIndex = 0, inIndex = 0;
	for(int i = 0;i < 2 * n; i++){
		scanf("%s",str);
		if(strcmp(str,"Push") == 0){
			scanf("%d", &x);
			pre[preIndex++] = x;
			st.push(x);
		}else{
			in[inIndex++] = st.top();
			st.pop();
		}
	}
	node* root = create( 0, n - 1, 0, n - 1);
	postorder(root);
	return 0;
}

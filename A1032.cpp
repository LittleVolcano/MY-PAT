#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct NODE{
	char data;
	int next;
	bool flag;//此节点是否在第一条链表中出现 
}node[maxn];

int main(int argc, char** argv) {
	for(int i = 0; i < maxn;i++){
		node[i].flag = false;//初始化所有节点都标为未出现过 
	}
	int s1, s2, n;
	scanf("%d%d%d",&s1, &s2, &n);
	int address, next;
	char data;
	for(int i = 0;i < n;i++){
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}
	int temp;//正在处理的节点 
	for(temp = s1; temp != -1;temp = node[temp].next){
		node[temp].flag = true;
	}
	for(temp = s1; temp != -1;temp = node[temp].next){
		if(node[temp].flag == true){
			break;
		}
	}
	if(temp != -1){
		printf("%5d", temp);
	}else{
		printf("-1");
	}
	return 0;
}

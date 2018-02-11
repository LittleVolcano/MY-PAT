#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 100010;
bool hashTable[maxn] = {false};
struct NODE{
	int address, data, next;
	int order;
}node[maxn];
bool cmp(NODE a, NODE b){
	return a.order < b.order;
}
int main(int argc, char** argv) {
	int p,n;
	int countValid = 0, countRemoved = 0;
	memset(hashTable,false,sizeof(hashTable));
	for(int i = 0;i < maxn;i++){
		node[i].order = 2 * maxn;
	}
	scanf("%d%d", &p, &n);
	for(int i = 0;i < n;i++){
		int address, data, next;
		scanf("%d%d%d",&address, &data, &next);
		node[address].address = address;
		node[address].data = data;
		node[address].next = next;
	}
	while( p != -1){
		if(!hashTable[abs(node[p].data)]){
			hashTable[abs(node[p].data)] = true;
			node[p].order = countValid++;
		}else{
			node[p].order = maxn + countRemoved++;
		}
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	int count = countValid + countRemoved;
	for(int i = 0;i < count ;i++){
		if(i != countValid - 1 && i != count - 1){
			printf("%05d %d %05d\n",node[i].address, node[i].data, node[i + 1].address);
		}else{
			printf("%05d %d -1\n",node[i].address, node[i].data);
		}
	}
	return 0;
}

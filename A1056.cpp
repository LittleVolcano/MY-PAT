#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1010;
struct MOUSE{
	int weight, rank;
}mouse[maxn];
int main(int argc, char** argv) {
	int np, ng, order;
	scanf("%d%d", &np, &ng);
	for(int i = 0;i < np;i++){
		scanf("%d", &mouse[i].weight);
	}
	queue<int> q;
	for(int i = 0;i < np;i++){
		scanf("%d", &order);
		q.push(order);
	}
	int tempnum = np,groupnum;
	while(q.size() != 1){
		if(tempnum % ng == 0){
			groupnum = tempnum / ng;
		}else{
			groupnum = tempnum / ng + 1;
		}
		for(int i = 0;i < groupnum;i++){
			int k = q.front();
			for(int j = 0;j < ng;j++){
				if(i * ng + j >= tempnum){
					break;
				}
				int front = q.front();
				if(mouse[front].weight > mouse[k].weight){
					k = front;
				}
				mouse[front].rank = groupnum + 1;
				q.pop();
			}
			q.push(k);
		}
		tempnum = groupnum;
	}
	mouse[q.front()].rank = 1;
	for(int i = 0;i < np;i++){
		printf("%d", mouse[i].rank);
		if(i < np - 1){
			printf(" ");
		}
	}
	return 0;
}

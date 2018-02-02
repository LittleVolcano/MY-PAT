#include <iostream>
#include <set>
using namespace std;
const int N = 60;
set<int> sets[N];
void compare(int x,int y){
	int allNum = sets[y].size(), sameNum = 0;
	for(set<int>::iterator it = sets[x].begin();it != sets[x].end();it++){//�Կ�ǰ�ļ��ϱ��� 
		if(sets[y].find(*it) != sets[y].end()){//����ڲ��ҵ�Ԫ�ز��ں�һ���� 
			sameNum++;
		}else allNum++;
	}
	printf("%.1f%%\n", sameNum * 100.0 / allNum);//!!! 100.0���븡�� 
}
int main(int argc, char** argv) {
	int n, k, q, v, sets1, sets2;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){//from 1?
		scanf("%d",&k);
		for(int j = 0;j < k;j++ ){
			scanf("%d", &v);
			sets[i].insert(v);
		}
	}
	scanf("%d", &q);
	for(int i = 0;i < q;i++){
		scanf("%d%d",&sets1, &sets2);
		compare(sets1,sets2);
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> fac, temp, ans;
int n, k, p, maxfacsum = -1;
void init(){
	int i = 0,temp = 0;
	while(temp <=  n){
		fac.push_back(temp);
		++i; 
		temp = pow(i,p);//temp�����������εģ��Զ�ǿ������ת���ˡ� i��p�Ĳ���Ҫ��ʱ�����ͣ�����Ҳ�Զ�ת���� 
	}
}
void DFS(int index, int nowK, int sum, int facsum){
	if(nowK == k & sum == n){
		if(facsum > maxfacsum){
			maxfacsum = facsum;
			ans = temp;
		}
		return;
	}
	if(sum > n || nowK > k){
		return;
	}
	if(index >= 1){
		//�����index 
		temp.push_back(index);
		DFS(index, nowK + 1, sum + fac[index], facsum + index);
		temp.pop_back();
		//�������index 
		DFS(index - 1, nowK, sum, facsum);
	}
}
int main(int argc, char** argv) {
	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if(maxfacsum == -1){
		printf("Impossible\n");
	}else{
		printf("%d = %d^%d", n, ans[0], p);
		for(int i = 1;i < ans.size(); i++){
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}

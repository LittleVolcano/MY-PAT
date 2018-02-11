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
		temp = pow(i,p);//temp本来就是整形的，自动强制类型转换了。 i和p的参数要求时浮点型，所以也自动转换了 
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
		//加入该index 
		temp.push_back(index);
		DFS(index, nowK + 1, sum + fac[index], facsum + index);
		temp.pop_back();
		//不加入该index 
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

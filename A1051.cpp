#include <iostream>
#include <stack> 
using namespace std;
const int maxn = 1010;
int arry[maxn];
int M, N, K;
stack<int> st;
void init(){//清空栈并读入新数据 
	while(!st.empty()){
		st.pop();
	}
	for(int i = 1;i <= N;i++){
		scanf("%d",&arry[i]);
	}
}
int main(int argc, char** argv) {


	scanf("%d%d%d", &M, &N, &K);
	while(K--){
		init();
		int now = 1;
		bool flag = true;
		for(int i = 1;i <= N;i++){
			st.push(i);
			if(st.size() > M){
				flag = false;
				break;
			}
			while(!st.empty() && st.top() == arry[now]){
				st.pop();
				now++;
			}
		}
		if(st.empty() == true && flag == true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}
	
	
	
	return 0;
}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char ans[1010]="string";
char* annon(int n, char* characteristic){
	int i;
	for(i = 0;i < n;i++){
		ans[i] = characteristic[i];
	}
	ans[n] = '\0';
//	strcpy(ans,characteristic);
	cout<<ans<<endl;

	return ans;
}
int main(int argc, char** argv) {
	string res = annon(5,"ABCDE");
	cout<<res;
	return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
//using namespace std;

int main(int argc, char** argv) {
	long long n;
	scanf("%lld", &n);
	long long sqr = (long long)sqrt(1.0 * n),ansi = 0,anslen = 0;
	for(long long i = 2;i <= sqr; i++){//i指向序列第一个，j指向i后正在试探的那个 
		long long temp = 1,j = i;
		while(1){
			temp *= j;
			if(n % temp != 0) break;
			if(j - i + 1 > anslen){
				ansi = i;
				anslen = j - i + 1;
			}
			j++;
		}
	} 
	if(anslen == 0){
		printf("1\n%lld", n);
	}else{
		printf("%lld\n",anslen);
		for(long long i = 0;i < anslen;i++){
			printf("%lld", ansi + i);
			if(i < anslen - 1)
				printf("*");
		}
	}
	return 0;
}

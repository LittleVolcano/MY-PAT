#include <iostream>
int main(int argc, char** argv) {
	int n,a = 1,ans = 0;
	int left,now,right;
	scanf("%d", &n);
	while(n / a != 0){
		left = n / (a * 10);
		right = n % a;
		now = n / a % 10;
		if(now == 0){
			ans += left * a;
		}
		else if(now == 1){
			ans += left * a + right + 1;
		}
		else ans += (left + 1) * a;
		a *= 10;
	}
	printf("%d\n", ans);
	return 0;
}

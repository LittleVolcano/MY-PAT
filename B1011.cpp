#include <iostream>
#include <stdio.h>


int main() {

	int n;
	int num = 1;
	long long a,b,c;
	//input
	scanf("%d",&n);
	while(n--){
	scanf("%lld %lld %lld", &a, &b, &c);
	if(a + b > c)
	printf("Case #%d: true\n", num++);
	else
	printf("Case #%d: false\n", num++);
	}

	return 0;
}

#include <iostream>
#include <stdio.h>
const int maxn = 1010;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct stu{
	long long id;
	int examset;
}testset[maxn];
int main() {
	int n;
	long long a;
	int b,c;
	
	//input
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
	scanf("%lld %d %d", &a, &b, &c);
	testset[b].id = a;
	testset[b].examset = c;	
	}

	//output
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
	scanf("%d",&b);
	printf("%lld %d\n", testset[b].id, testset[b].examset);
	}
	
	return 0;
}

#include <iostream>
#include <stdio.h>

int main() {
	int n,m;
	int a[110];
	scanf("%d %d", &n, &m);
	m %= n;
	int count = n;
	for(int i = 0;i < n;++i){
		scanf("%d", &a[i]);		
	}
	for(int i = n - m; i < n; ++i){
		--count;
		if(count != 0){

			printf("%d ", a[i]);
		}
		else{

		printf("%d", a[i]);
		}
	}
	
	for(int i = 0; i < n - m; ++i){
		--count;
		if(count != 0){

			printf("%d ", a[i]);
		}
		else{

		printf("%d", a[i]);
		}
	}		
		
	return 0;
}

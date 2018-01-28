#include <iostream>
#include <stdio.h>

int main() {
	int num;
	scanf("%d",&num);
	int a[4];
	int n = 0;
	while(num!=0){
		a[n++] = num % 10;
		num /= 10;
	}
	for(int i = n - 1;i >= 0; --i){
		if(i == 2){
			for(int j = 0; j < a[i]; ++j){
				printf("B");
			}
		}
		else if(i == 1){
			for(int j = 0;j < a[i]; ++j){
				printf("S");
			}
		}
			else if(i == 0){
				for(int j = 1; j <= a[i]; ++j){
					printf("%d",j);
				}
			}
	}

	return 0;
}

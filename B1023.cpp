#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int num[10] = {0};
	for(int i = 0;i < 10;i++){
		scanf("%d",&num[i]);
	}
	for(int i = 1; i < 10;++i){//first
		if(num[i] > 0){
			printf("%d",i);
			num[i]--;
			break;
		}
	}
	for(int i = 0;i < 10;++i){//others
		while(num[i] > 0){
			printf("%d",i);
			num[i]--;
		}
		
	}
	
	return 0;
}

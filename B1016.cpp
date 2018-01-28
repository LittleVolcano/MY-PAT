#include <iostream>
#include <stdio.h>


int main() {
	int DA,DB;
	long long A,B;
	long long PA = 0,PB = 0;
	//input

	scanf("%lld %d %lld %d", &A, &DA, &B, &DB);
	while(A != 0){
	if(A % 10 == DA){
		PA = PA * 10 + DA;	
	}
	A /= 10;
	}
	while(B != 0){
	if(B % 10 == DB){
		PB = PB * 10 + DB;	
	}
	B /= 10;
	}

	printf("%lld",PA + PB);
	return 0;
}

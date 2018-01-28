#include <iostream>
#include <stdio.h>

int main() {
	int n;
	int num1 = 0,num2 = 0;//num1Îª¼×ºÈµÄ±­Êý 
	int a,b,c,d;
	scanf("%d", &n);
	while(n--){
		int flag1 = 0;
		int flag2 = 0;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(b == a + c)
			flag1 = 1;
		if(d == a + c)
			flag2 = 1;
		if(flag1 == 1 && flag2 == 0)
			++num2;
		if(flag1 == 0 && flag2 == 1)
			++num1;
		
	}
	printf("%d %d", num1, num2);	
	return 0;
}

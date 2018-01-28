#include <iostream>
#include <stdio.h>
const int g = 17*29;
const int s = 29;
int main() {
	int g1,g2,s1,s2,k1,k2;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
	int p = g1 * g + s1 * s + k1;
	int a = g2 * g + s2 * s + k2;
	int change = a - p;
	if(change < 0){
	printf("-");
	change = -change;
	}
	printf("%d.%d.%d", change / g , change % g / s , change % s);
	return 0;
}

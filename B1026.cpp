#include <iostream>
#include <stdio.h>


int main() {
	int c1,c2;
	scanf("%d %d", &c1, &c2);
	int c3 = c2 - c1;
	if(c3 % 100 >= 50)
		c3 = c3 / 100 + 1;
	else c3 /= 100;
	
	printf("%02d:%02d:%02d\n",c3 / 3600, c3 % 3600 / 60, c3 % 60);
	return 0;
}

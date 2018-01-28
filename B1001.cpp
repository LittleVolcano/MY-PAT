#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n;
	int step = 0;
	scanf("%d", &n);
	while(n != 1)
	{
		if(n % 2 == 0)
		n /= 2;
		else
		n = (3 * n + 1)/2;
		++step;
	}
	printf("%d", step);
	return 0;
}

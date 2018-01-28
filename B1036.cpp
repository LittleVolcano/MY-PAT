#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int col,row;
	char a,x;
	scanf("%d %c", &col, &a);
	
	x = col;
	while(x--)
	printf("%c", a);
	printf("\n");
	
	
	if(col % 2 == 0)
	 row = col / 2 - 2;
	 else
	 row  = col / 2 - 1;
	while(row--){
		int col2 = col - 2;
		printf("%c", a);
		while(col2--)
		printf(" ");
		printf("%c\n", a);
	}
	
	x = col;
	while(x--)
	printf("%c", a);
	printf("\n");
	
	
	
	return 0;
}

#include <iostream>
#include <cmath> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n;
	char c;
	int count = 0;
	scanf("%d %c",&n, &c);
	int fline = (int) sqrt(2.0 * ( n + 1 )) - 1;
	if(fline % 2 == 0)
		--fline;
	int used = (fline + 1) * (fline + 1) / 2 - 1;
	for(int i = fline ;i >= 1;i -= 2){
		for(int j = 0;j < (fline - i)/2 ; j++){
			printf(" ");
		}
		for(int j = 0;j < i;j++){
			printf("%c",c);
			count++;//
		}
		printf("\n");
	}
	for(int i = 3;i <= fline;i+=2){
		for(int j = 0;j < (fline - i) / 2;j++){
			printf(" ");
		}
		for(int j=0;j <i;j++){
			printf("%c",c);
			count++;//
		}
		printf("\n");
	}
	printf("%d\n",n - count);//
	return 0;
}

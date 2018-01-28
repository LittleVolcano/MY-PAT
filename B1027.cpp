#include <iostream>
#include <math.h>
int main() {
	int count = 0;
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int fline = (int) sqrt(2.0 * (n + 1)) - 1;
	if(fline % 2 == 0)
		fline--;
	int i = fline;//control char
	int j = 0;//control space
	while( i >= 1){
		int m = j,n = i;
		while(m--){
		printf(" ");
		}
		while(n--){
			count++;
			printf("%c",c);		
		}
		m = j;
		while(m--){		
		printf(" ");
		}
		printf("\n");
		i -= 2;
		j++;
	}
	i = 3;//control char
	j = ( fline - i ) / 2;//control space
	while( i <= fline){
		int m = j,n = i;
		while(m--){
		printf(" ");		
		}
		while(n--){
			count++;
			printf("%c",c);		
		}
		m = j;
		while(m--){
		printf(" ");
		}
	
		printf("\n");
		i += 2;
		j--;
	}
	printf("%d",n - count);
	
	
	
	return 0;
}

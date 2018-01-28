#include <iostream>
#include <stdio.h>
#include <string.h>
int main() {
	char str[90];
	gets(str);
	int len = strlen(str);
	int a = 0,b = 0;
	char ans[90][90];
	
	for(int i = 0; i < len;++i){
		if(str[i] != ' '){
			ans[a][b++] = str[i];
		}
		else{
			ans[a][b] = '\0';
			a++;
			b = 0;
		}
	}
	for(int i = a;i >= 0 ; --i){
		printf("%s",ans[i]);
		if(i > 0)
		printf(" ");
	}
	
	
	return 0;
}

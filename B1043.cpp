#include <iostream>
#include <cstring>
const int maxn = 10010;
int hash[6] = {0};
char dic[6] = {'P','A','T','e','s','t'};
int main(int argc, char** argv) {
	char str[maxn];
	int sum = 0;
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len ;++i){
		for(int j = 0; j < 6; ++j){
			if(str[i] == dic[j]){
				hash[j]++;
				sum++;
			}
		}
	}
	while(sum > 0){
		for(int i = 0; i < 6;++i){
			if(hash[i] > 0){
				printf("%c",dic[i]);
				hash[i]--;
				sum--;
			}
				
		}
	}
	
	return 0;
}

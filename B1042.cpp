#include <iostream>
#include <cstring> 
const int maxn = 1010;
char str[maxn];
int hash[30] = {0};
int main() {
	gets(str);
	int len = strlen(str);
	for(int i = 0;i < len; ++i){
		if(str[i] >= 'A' && str[i] <= 'Z')
			hash[str[i] - 'A']++;
		else if(str[i] >= 'a' && str[i] <= 'z')
			hash[str[i] - 'a']++;
	}
	int k=0;
	for(int i = 0;i < 26; ++i){
		if(hash[i] > hash[k])
			k = i;
	}	
	printf("%c %d\n", 'a' + k, hash[k]);
	return 0;
}

#include <iostream>
#include <cstring>

int main() {
	bool hashtable[260];
	memset(hashtable,true,sizeof(hashtable));
	char str[110000];
	gets(str);
	int len = strlen(str);
	for(int i = 0;i < len;++i){
		if(str[i] >= 'A'&& str[i] <= 'Z' ){
			str[i] = str[i] - 'A' + 'a';
		}
	
		hashtable[ str[i] ] = false;
	}
	gets(str);
	len = strlen(str);
	for(int i = 0;i < len;++i){
		if(str[i] >= 'A'&& str[i] <= 'Z' ){
			if(hashtable['+'] == true && hashtable[str[i] - 'A' + 'a']==true)
				printf("%c",str[i]);
		}
		else if(hashtable[str[i]] == true)
				printf("%c",str[i]);
	}
	return 0;
}

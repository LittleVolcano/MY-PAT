#include <iostream>
#include <string.h>
struct bign{//大整数结构定义 
	int d[1010];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
}; 
bign change(char str[]){//把读入的字符形式的大整数，逆向放入大整数型结构体 
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len;i++){
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}
bign divide(bign a,int b,int &r){//除法，返回商，并用引用修改r 
	bign c;
	c.len = a.len;
	for(int i = a.len - 1;i >= 0;i--){
		r = 10 * r + a.d[i];
		if(r < b){
			c.d[i] = 0;
		}else{
			c.d[i] = r / b;
			r = r % b;
		}
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
		c.len--;
	}
	return c;
}
void printBign(bign a){//输出大整数 
	for(int i = a.len - 1; i >= 0;i--){
		printf("%d",a.d[i]);
	}
}
int main(int argc, char** argv) {
	char str1[1010],str2[1010];
	int b, r = 0;
	scanf("%s%d", str1, &b);
	bign a = change(str1);
	printBign(divide(a, b, r));//商 
	printf(" %d",r);//余数 
	return 0;
}

#include <iostream>
#include <string.h>
struct bign{//�������ṹ���� 
	int d[1010];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
}; 
bign change(char str[]){//�Ѷ�����ַ���ʽ�Ĵ��������������������ͽṹ�� 
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len;i++){
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}
bign divide(bign a,int b,int &r){//�����������̣����������޸�r 
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
void printBign(bign a){//��������� 
	for(int i = a.len - 1; i >= 0;i--){
		printf("%d",a.d[i]);
	}
}
int main(int argc, char** argv) {
	char str1[1010],str2[1010];
	int b, r = 0;
	scanf("%s%d", str1, &b);
	bign a = change(str1);
	printBign(divide(a, b, r));//�� 
	printf(" %d",r);//���� 
	return 0;
}

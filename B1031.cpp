#include <iostream>
#include <cstring>
const int w[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char cheak[15] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	char str[20];
	bool flag = true;//总体 
	bool flag2;
	for(int i = 0;i < n;++i){
		gets(str);
		flag2 = true;//当前 
		int sum = 0,j;
		for(j = 0;j < 17;++j){//前17位 
			if(str[j] > '9'|| str[j] < '0'|| strlen(str)<18){//前17位如果有非数字字符，或长度不够，标记为错，不再判断 
				flag = false;//总体不输出 
				flag2 = false;//本次要打印 
				break;
			}
			else{
				sum+= (str[j] - '0') * w[j];
			}
		}
		if( str[17] != cheak[sum % 11] || flag2== false){//第18位 
			flag = false;
			if(flag2 == false){
				printf("%s\n",str);	
			}

		}
	}
	if(flag == true)
	printf("All passed");
	return 0;
}

#include <iostream>
#include <cstring>
const int w[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char cheak[15] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	char str[20];
	bool flag = true;//���� 
	bool flag2;
	for(int i = 0;i < n;++i){
		gets(str);
		flag2 = true;//��ǰ 
		int sum = 0,j;
		for(j = 0;j < 17;++j){//ǰ17λ 
			if(str[j] > '9'|| str[j] < '0'|| strlen(str)<18){//ǰ17λ����з������ַ����򳤶Ȳ��������Ϊ�������ж� 
				flag = false;//���岻��� 
				flag2 = false;//����Ҫ��ӡ 
				break;
			}
			else{
				sum+= (str[j] - '0') * w[j];
			}
		}
		if( str[17] != cheak[sum % 11] || flag2== false){//��18λ 
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

#include <iostream>
#include <cstring>
int pos_p = -1,pos_t = -1;
int len;
char str[110];
int numx(){
	int x=0;
	for(int i = 0;i < pos_p;i++){
		if(str[i] != 'A'){
			return -1;
		}
		else{
			x++;
		}
	}
	return x;
}
int numy(){
	int y=0;
	for(int i = pos_p + 1;i < pos_t;i++){
		if(str[i] != 'A'){
			return -1;
		}
		else{
			y++;
		}
	}
	return y;	
}
int numz(){
	int z=0;
	for(int i = pos_t + 1;i < len;i++){
		if(str[i] != 'A'){
			return -1;
		}
		else{
			z++;
		}
	}
	return z;	
}
int main(int argc, char** argv) {
	int n;
	scanf("%d", &n) ;
	getchar();
	while(n--){
		bool flag = true;
		int x = 0,y = 0,z = 0;
		pos_p = -1;
		pos_t = -1;
		gets(str);
		len = strlen(str);
		for(int i = 0;i < len;i++){//定位p和t 
			if(str[i] == 'P'){
				pos_p = i;
			}
			else if(str[i] == 'T'){
				pos_t = i;
			}
		}
		if(pos_p < 0 || pos_t < 2){
			flag = false;
		}
		else{
			x = numx();//统计xyz 
			y = numy();
			z = numz();
			if(x < 0 || y < 0 || z < 0 || x * y != z){//判定 
				flag = false;
			}
		}
		
		if(flag == true){//输出 
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	
	return 0;
}

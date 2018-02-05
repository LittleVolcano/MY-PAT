#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m,n,temp, a = -1, count = 0;
	scanf("%d%d",&m,&n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			scanf("%d", &temp);
			if(temp == a){
				count++;
			}else{
				count--;
				if(count < 0){
					a = temp;
					count = 1;
				}
			}
		}
	}
	printf("%d",a);
	return 0;
}

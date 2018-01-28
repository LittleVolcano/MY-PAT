#include <iostream>
#include <stdio.h>

int count[6] = {0};
int ans[6] = {0};
int main() {
	int n;
	scanf("%d", &n);
	while(n--){//input
		int temp;
		scanf("%d", &temp);
		if(temp % 10 == 0){//A1
			++count[1];
			ans[1] += temp;
		}
		else if(temp % 5 == 1){//A2
			++count[2];
			if(count[2] % 2 == 1){
				ans[2] += temp;
			}
			else ans[2] -= temp;
		}
		else if(temp % 5 == 2){//A3
			++count[3];
		}
		else if(temp % 5 == 3){//A4
			++count[4];
			ans[4] += temp;
		}
		else if(temp % 5 == 4){//A5
			++count[5];
			if(temp > ans[5])
				ans[5] = temp;//
		}
	}
	//output
	if(count[1] == 0)
		printf("N ");
	else printf("%d ",ans[1]);
	
	if(count[2] == 0)
		printf("N ");
	else printf("%d ",ans[2]);
		
	if(count[3] == 0)
		printf("N ");
	else printf("%d ",count[3]);
		
	if(count[4] == 0)
		printf("N ");
	else printf("%.1f ", (double) ans[4]/count[4]);//
	
	if(count[5] == 0)
		printf("N");	
	else printf("%d",ans[5]);
	
	return 0;
}

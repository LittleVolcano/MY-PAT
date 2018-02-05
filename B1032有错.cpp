#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n,schID,score,MAXID,MAXSCORE;
	int sch[100010] = {0};
	scanf("%d", &n);
	for(int i = 0;i < n; ++i){
		scanf("%d %d", &schID, &score);
		sch[schID] += score;
	} 
	MAXSCORE = 0;
	MAXID = 1;
	for(int i = 1;i <= n; ++i){//为什么要取到n 
		if(sch[i] > MAXSCORE){
			MAXID = i;
			MAXSCORE = sch[i];			
		}
	}
	printf("%d %d", MAXID,MAXSCORE);
	return 0;
}

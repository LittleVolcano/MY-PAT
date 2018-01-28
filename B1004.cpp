#include <iostream>
#include <stdio.h>
const int maxn = 1010;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct stu{
	char name[11];
	char id[11];
	int score;
}min,max,temp;

int main() {
	min.score = 101;
	max.score = -1;
	int n;
	int b,c;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
	scanf("%s %s %d", temp.name, temp.id, &temp.score);
	if(temp.score > max.score) max = temp;
	if(temp.score < min.score) min = temp;
	}


	printf("%s %s\n", max.name, max.id);
	printf("%s %s\n", min.name, min.id);
	
	return 0;
}

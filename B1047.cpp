#include <iostream>
#include <cstring>
const int maxn = 1010;
int hash[maxn] = {0};
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n ;++i){
	int team,memb,score;
	scanf("%d-%d %d", &team, &memb, &score);
	hash[team] += score;
	}
	int k,max = -1;
	for(int i = 0; i < maxn ;++i){
		if(hash[i]>max){
			k = i;
			max = hash[i];
		}
	}
	printf("%d %d\n", k, max);
	return 0;
}

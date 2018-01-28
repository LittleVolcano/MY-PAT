#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct mooncake{
	double store;//库存 
	double sell;//总价 
	double price;//单价 
}cake[1010];
bool cmp(mooncake a,mooncake b){
	return a.price > b.price;
}

int main() {
	int n,need;
	scanf("%d %d", &n, &need);
	for(int i = 0;i < n; ++i){
		scanf("%lf",&cake[i].store);
	}
	for(int i = 0;i < n; ++i){
		scanf("%lf",&cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;
	}
	sort(cake,cake + n,cmp);
	double sum = 0;//总收入
//	for(int i = 0;i < n; ++i){
//		printf("%.2f %.2f %.2f \n",cake[i].price,cake[i].store,cake[i].sell);
//	}
	for(int i = 0;i < n; ++i){
		if(cake[i].store >= need){
			sum = sum + need * cake[i].price;
			need = 0;
			break;
		}
		else{
			sum += cake[i].sell;
			need -=cake[i].store;
		}
	}
		printf("%.2f",sum);
	return 0;
}

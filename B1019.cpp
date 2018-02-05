#include <iostream>
#include <algorithm>
using namespace std;
int a[10]={0,0,0,0},val,MIN,MAX;
bool cmp(int a, int b){
	return a > b;
}
void toArray(int val,int a[]){
	a[0] = val / 1000;
	a[1] = val / 100 % 10;
	a[2] = val / 10 % 10;
	a[3] = val % 10;

}
int toNumber(int a[]){
	val = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
	return val;
}
int main(int argc, char** argv) {
	scanf("%d",&val);
	do{
		toArray(val,a);
		sort(a,a+4);
		MIN = toNumber(a);
		sort(a,a+4,cmp);
		MAX = toNumber(a);
		val = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, val);		
	}while(val != 6174 && val != 0);
	return 0;
}

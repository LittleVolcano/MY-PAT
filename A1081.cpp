#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b){//最大公约数 
	return !b ? a :gcd(b, a % b);
}
struct Fraction{//定义分数的结构 
	long long up,down;
}; 
Fraction reduction(Fraction a){//化简 
	if(a.down < 0){
		a.up = -a.up;
		a.down = - a.down;
	}
	if(a.up == 0){
		a.down = 1;
	}else{
		int d = gcd(abs(a.up), abs(a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}
Fraction add(Fraction a, Fraction b){//加 
	Fraction c;
	c.up = a.up * b.down + a.down * b.up;
	c.down = a.down * b.down;
	return reduction(c);
}
void printFraction(Fraction a){//打印 
	reduction(a);
	if(a.down == 1){
		printf("%lld\n",a.up);
	}else if(abs(a.up) > a.down){
		printf("%lld %lld/%lld\n",a.up / a.down, abs(a.up) % a.down, a.down);
	}else{
		printf("%lld/%lld\n",a.up, a.down);
	}
}
int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	Fraction sum,temp;
	sum.up = 0;
	sum.down = 1;
	for(int i = 0;i < n;i++){
		scanf("%lld/%lld",&temp.up, &temp.down);
		sum = add(sum, temp);
	}
	printFraction(sum);
	return 0;
}

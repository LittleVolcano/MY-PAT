#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b){//最大公约数 
	return !b ? a : gcd(b, a % b);
}
struct Fraction{//分数结构 
	long long up,down;
}a,b;
Fraction reduction(Fraction a){//化简 
	if(a.down < 0){
		a.up = -a.up;
		a.down = - a.down;
	}
	if(a.up == 0){
		a.down = 1;
	}else{
		int d = gcd(abs(a.up), abs(a.down));
		a.down /= d;
		a.up /= d;
	}
	return a;
}
Fraction add(Fraction a,Fraction b){//加 
	Fraction c;
	c.up = a.up * b.down + a.down * b.up;
	c.down = a.down * b.down;
	return reduction(c);
}
Fraction minu(Fraction a,Fraction b){//减 
	Fraction c;
	c.up = a.up * b.down - a.down * b.up;
	c.down = a.down * b.down;
	return reduction(c);
}
Fraction multi(Fraction a,Fraction b){//乘 
	Fraction c;
	c.up = a.up * b.up;
	c.down = a.down * b.down;
	return reduction(c);
}
Fraction divide(Fraction a,Fraction b){//除 
	Fraction c;
	c.up = a.up * b.down;
	c.down = a.down * b.up;
	return reduction(c);
}
void printfFraction(Fraction a){//输出 
	a = reduction(a);
	if(a.up < 0){
		printf("(");		
	}
	if(a.down == 1){
		printf("%lld",a.up);
	}else if(abs(a.up) > a.down){
		printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
	}else{
		printf("%lld/%lld", a.up, a.down);
	}
	if(a.up < 0){
		printf(")");
	}
}
int main(int argc, char** argv) {
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	//+
	printfFraction(a);
	printf(" + ");
	printfFraction(b);
	printf(" = ");
	printfFraction(add(a, b));
	printf("\n");
	//-
	printfFraction(a);
	printf(" - ");
	printfFraction(b);
	printf(" = ");
	printfFraction(minu(a, b));
	printf("\n");
	//*
	printfFraction(a);
	printf(" * ");
	printfFraction(b);
	printf(" = ");
	printfFraction(multi(a, b));
	printf("\n");
	//   /
	printfFraction(a);
	printf(" / ");
	printfFraction(b);
	printf(" = ");
	if(b.up == 0)
		printf("Inf");
	else
		printfFraction(divide(a, b));
	return 0;
}

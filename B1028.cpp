#include <iostream>
#include <stdio.h>

struct person{
	char name[11];
	int yy,mm,dd;
}oldest,youngster,left,right,temp;
bool isless(person a, person b){//a是否比给定b小
	if(a.yy != b.yy) return a.yy <= b.yy;
	else if(a.mm != b.mm) return a.mm <= b.mm;
	else return a.dd <= b.dd;
}
bool ismore(person a, person b){//a是否比给定b大 
	if(a.yy != b.yy) return a.yy >= b.yy;
	else if(a.mm != b.mm) return a.mm >= b.mm;
	else return a.dd >= b.dd;
}
void init(){//初始化 
	left.yy = 1814;
	left.mm = 9;
	left.dd = 6;
	youngster = left;
	right.yy = 2014;
	right.mm = 9;
	right.dd = 6;
	oldest = right;
}


int main() {
	init();
	int num = 0;
	int n;
	//input
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
	scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
//		bool aa = ismore(temp,left);
//		bool bb = isless(temp,right);
//		printf("%d %d\n", aa, bb);
	//judge
	if( isless(temp,right) && ismore(temp,left) ){
		++num;
	
		if( ismore(temp,youngster) )
		youngster = temp;
		if( isless(temp,oldest) )
		oldest = temp;
	}
	}
	//output
	if(num == 0){
		printf("0");
	}
	else{
		printf("%d ", num);
		printf("%s ", oldest.name);
		printf("%s", youngster.name);
	}
	
	return 0;
}

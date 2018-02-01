#include <iostream>


int main(int argc, char** argv) { 
double r,A = 3000;
while(1){
	double M = 300000;
	printf("年利率(%%)");
	scanf("%lf",&r);
//	printf("每月还款额（元）");
//	scanf("%lf", &A);
	r /= 1200;
//	printf("%f %f %f",r,A,M);
	for(int i = 0;i < 120;i++){
		M = M * (1 + r) - A;
	}
	printf("十年后欠款：%lf\n",M);
	
}
	
	return 0;
}

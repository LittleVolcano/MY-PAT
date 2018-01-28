#include <iostream>
#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const double eps = 1e-8;
const double pi = acos(-1.0);
#define Equ(a , b) ((fabs((a) - (b))) < (eps))
int main() {
	double db = 1.23;
	if(Equ(db,1.23)){
		printf("ture\n");

	}	
	else
	printf("false\n");
	printf("%.11lf",pi);
	return 0;
}

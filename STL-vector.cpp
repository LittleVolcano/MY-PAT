#include <iostream>
struct aa{
	int r1;
	double r2;
	float r3;
};
int main() {
	
	printf("struct:%d\n",sizeof(aa));
	printf("int:%d\n",sizeof(int));
	printf("long int:%d\n",sizeof(long int));
	printf("double:%d\n",sizeof(double));
	printf("float:%d\n",sizeof(float));
	return 0;
}

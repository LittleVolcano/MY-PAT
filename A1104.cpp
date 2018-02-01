#include <iostream>
int main(int argc, char** argv) {
	int n;
	double num,ans = 0;
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++){
		scanf("%lf",&num);//double输入时用lf输出用f
		ans += num * i *(n + 1 - i) ;
	}
	printf("%.2f\n",ans);
	return 0;
}

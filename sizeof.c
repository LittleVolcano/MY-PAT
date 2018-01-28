#include<stdio.h>
//sizeof()用来看括号里的类型占用多少字节空间
//sizeof是静态的，括号内的不会进行计算例如sizeof(a++)这里的a++就不会计算；但是sizeof(a + 1.0)知道把a变成double类型后进行计算 

void max(int a; int b);//要么用之前在main之前定义；要么像这样原型声明，函数体卸载main后边 	变量名可以不写 

int main(){
int a = 6;
printf("%ld\n",sizeof(char));
printf("%ld\n",sizeof(short));
printf("%ld\n",sizeof(int));
printf("%ld\n",sizeof(long));
printf("%ld\n",sizeof(float));
printf("%ld\n",sizeof(double));
printf("%ld\n",sizeof(long long));
return 0;
}
void max(int a; int b)//函数定义 
{
	
 啥啥啥 
}

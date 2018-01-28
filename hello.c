#include<stdio.h>
int main()
{
	const int amount = 100;//const 是一个修饰符，表示后边的变量初始化后就不能改了 
	int price;//这个编译器的变量声明可以在任何地方，VC++6好像不能，考试要注意 
	printf("请输入金额（元）：");	
	scanf("%d", &price);			//输入函数 ，变量处用了引用 
	//scanf中的东西都是要输入的东西，都不是给你看的 
	int change = amount - price;
	printf("找您%d元。\n",change);
	
	return;
	//浮点型输入时%lf  输出时%f 
}

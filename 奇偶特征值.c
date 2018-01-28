#include<stdio.h>
int main()
{
	int i;//输入值 
	int n = 1;//n表示位数 
	int temp;
	int k;
	int number = 0;
	scanf("%d",&i);
	while(i != 0)
	{
		if(i % 10 %2 == n % 2)//位数的奇偶性和该位上数字的奇偶性相同，输出1，否则输出0 
		{temp = 1;
		}
		else//0其实没起到作用，所以应该设置一个为1的常量，是1就用，不是就跳过去了。 
		{temp = 0;
		}
	k = n;
	while(k > 1 )//每一位到这里都会运行一次累乘，很浪费时间，所以应该设置一个每处理一位乘一次供所有位使用的变量。 
	{temp *= 2;
	k--;
	}
	
	number = number + temp;
	i /= 10;//最右边一位处理完毕，丢弃 
	
	n++;
	}
 printf("%d",number);
	return 0;
 } 

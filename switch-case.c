#include<stdio.h>
int main()
{
	int RS,R,S;
	scanf("%d",&RS);
	R = RS / 10;
	S = RS % 10;
	switch(S)//要注意的地方是每个case后边别忘记break	再就是case 数字：这里是冒号 
	{
		case 1:printf("Faint signals, barely perceptible");break;
		case 2:printf("Very weak signals");break;
		case 3:printf("Weak signals");break;
		case 4:printf("Fair signals");break;
		case 5:printf("Fairly good signals");break;
		case 6:printf("Good signals");break;
		case 7:printf("Moderately strong signals");break;
		case 8:printf("Strong signals");break;
		case 9:printf("Extremely strong signals");break;
	}
	printf(", ");
	switch(R)
	{
		case 1:printf("unreadable");break;
		case 2:printf("barely readable, occasional words distinguishable");break;
		case 3:printf("readable with considerable difficulty");break;
		case 4:printf("readable with practically no difficulty");break;
		case 5:printf("perfectly readable");break;
	}
	printf(".");
	return 0;
 } 









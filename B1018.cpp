#include <iostream>
#include <stdio.h>
//��¼������ʤ��ʱ���Ǽ�
//ȫƽ��ʱ�������һ�� 
int main() {
	int n;
	int winA[3] = {0},winB[3] = {0};//ʤ��ʱBCJ
	int count[3] = {0};//�� Ӯƽ�� 
	char a,b;
	scanf("%d", &n);
	while(n--){//input
		getchar();//Ϊʲô��ǰ�� 
		scanf("%c %c", &a, &b);
//		printf("\n//%c  %c//\n", a, b);//

		if(a == b){
					++count[1];
			}
		else if( (a == 'B'&& b == 'C')||(a == 'C'&& b == 'J')||(a == 'J'&& b == 'B') ){//��Ӯ 
					++count[0];
					if(a == 'B') ++winA[0];
					else if(a == 'C')	++winA[1];
					else if(a == 'J')	++winA[2];
			
				}
		else if( (b == 'B'&& a == 'C')||(b == 'C'&& a == 'J')||(b == 'J'&& a == 'B') ){//��Ӯ 
					++count[2];
					if(b == 'B') ++winB[0];
					else if(b == 'C')	++winB[1];
					else if(b == 'J')	++winB[2];
			
				}		
	}
	//output
	printf("%d %d %d\n", count[0], count[1], count[2]);
	printf("%d %d %d\n", count[2], count[1], count[0]);
	if(winA[0] >= winA[1]&&winA[0] >= winA[2])
	printf("B ");
	else if(winA[1] >= winA[2])
	printf("C ");
	else printf("J ");
	
	if(winB[0] >= winB[1]&&winB[0] >= winB[2])
	printf("B");
	else if(winB[1] >= winB[2])
	printf("C");
	else printf("J");
	return 0;
}

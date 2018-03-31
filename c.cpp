#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i;
	scanf("%c",&i);
	switch(i){
		case 1:	printf("1");break;
		case 2:printf("2");break;
		case 'c':printf("3");break;
		default:printf("4");
	}

	return 0;
}

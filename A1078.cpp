#include <iostream>
#include <cmath>
using namespace std;
const int N = 11000;
bool isPrime(int n){
	if(n <= 1){
		return false;
	}
	int sqr = (int) sqrt(1.0 * n);
	for(int i = 2;i <= sqr;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
bool hashTable[N] = {0};
int main(int argc, char** argv) {
	int n, Tsize, a;
	scanf("%d%d", &Tsize, &n);
	while(isPrime(Tsize) == false){//令Tsize为素数 
		Tsize++;
	}
	for(int i = 0; i < n;i++){
		scanf("%d", &a);
		int M = a % Tsize;
		if(hashTable[M] == false){//无冲突 
			hashTable[M] = true;
			if(i == 0){
				printf("%d", M);
			}else{printf(" %d",M);
			}
		}else{//有冲突 
			int step;
			for(step = 1;step < Tsize;step++){
				M = (a + step * step) % Tsize;
				if(hashTable[M] == false){ 
					hashTable[M] = true;
					if(i == 0){
						printf("%d", M);
					}else{printf(" %d",M);
						}
					break;
				}
			}
			if(step >= Tsize){
				if(i > 0)
					printf(" ");
				printf("-");
			}
		}
	}
	return 0;
}

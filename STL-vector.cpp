#include <iostream>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main() {
	
	
	vector<int> vi;
	for(int i = 1;i <=5;i++){
		vi.push_back(i);
	}
	
	
	vector<int>::iterator it = vi.begin();
	for(int i = 0;i < 5;i++){
		printf("%d ",vi[0]);
	}
	return 0;
}

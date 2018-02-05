#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int now[N],origin[N],aim[N];
int n;
bool isSame(int a[],int b[]){
	for(int i = 0;i < n;i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	return true;
}
void printArray(int a[]){
	for(int i = 0;i < n; i++){
		printf("%d",a[i]);
		if(i < n - 1)
			printf(" ");
	}
	printf("\n");
}
bool isInsertSort(){
	bool flag = false;
	for(int i = 1;i < n;i++){//sort
		if(i != 1 && isSame(aim,now)){
			flag = true;
		}
		int temp = now[i],j = i;
		while(j > 0 && now[j - 1] > temp){
			now[j] = now[j - 1];
			j--;
		}
		now[j] = temp;
		if(flag == true){
			return true;
		}
	}
	return false;
}
void mergeSort(){
	bool flag = false;
	for(int step = 2;step / 2 <= n;step *= 2){//
		if(step != 2 && isSame(origin,aim)){
			flag = true;
		}
		for(int i = 0;i < n;i += step){
			sort(origin + i,origin + min(i + step,n) );
		}
		if(flag == true){
			printArray(origin);
			return;
		}

	}
}
int main(int argc, char** argv) {
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d",&origin[i]);
		now[i] = origin[i];
	}
	for(int i = 0;i < n;i++){
		scanf("%d", &aim[i]);
	}
	if(isInsertSort()){
		printf("Insertion Sort\n");
		printArray(now);
	}
	else{
		printf("Merge Sort\n");
		mergeSort();

	}
	
	return 0;
}

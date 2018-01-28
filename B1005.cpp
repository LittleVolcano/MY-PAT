#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	bool hashtable[110];//数组名叫做hash的时候可能编译报错，以后命名用hashtable 
	memset(hashtable,0,sizeof(hashtable));
	int a[110];
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n ;++i){
		int m;
		scanf("%d", &a[i]);
		m = a[i];
		while(m != 1){
			if(m % 2 == 1){
				m = (3 * m + 1) / 2;
			}
			else{
				m /= 2;
			}
			if(m <= 100){
				hashtable[m] = true;
			}
		}
	}
	int count = 0;
	sort(a,a + n);
	for(int i = 0;i < n;++i){
		if(hashtable[a[i]] == false)
			count++;
	}
	for(int i = n - 1;i >= 0;--i){//注意边界，i=0也是可取的 
		if(hashtable[a[i]] == false){
			printf("%d",a[i]);
			count--;
			if(count > 0)
			printf(" ");
		}
	}

	return 0;
}

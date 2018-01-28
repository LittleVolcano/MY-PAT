
#include <iostream>
#include <string>

#include<algorithm>
using namespace std;
string str[10010];
bool cmp(string a,string b)
{
	return a + b < b + a;
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i)
	{
		cin >> str[i];//
	}
	sort(str,str + n ,cmp);
	string ans;
	for(int i = 0;i < n; ++i)
	{
		ans += str[i];
	}
	while(ans.size()!=0&&ans[0] == '0')
		ans.erase(ans.begin());
	if(ans.size() == 0)
		cout << 0;
	/*	printf("0");*/
	else	/*printf("%s",ans);*/
		cout << ans;
	return 0;
}


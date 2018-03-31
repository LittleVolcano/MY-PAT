#include <iostream>
#include <map>
#include <vector>
#include <string>
const int maxn = 2010;
using namespace std;
int n,k;
int GangNum = 0;
int weight[maxn] = {0};
vector<int> graph[maxn];
map<string ,int> Gang;//head groupnum
map<string ,int> strtonum;
map<int, string> numtostr;
int allnum = 0;
bool set[maxn] = {false};
int StrChangeToNum(string str){
	if(strtonum.find(str) != strtonum.end()){//have in
		return strtonum[str];

	}else{//haven't in
		strtonum[str] = allnum;
		numtostr[allnum] = str;
		return allnum++;
	}
}
void DFS(int now,int &head,int &partsum, int &cnt){
	set[now] = true;
	cnt++;
	partsum += weight[now];
	if(weight[now] > weight[head]){
		head = now;
	}
	for(int i = 0;i < graph[now].size();i++){
		int v = graph[now][i];
		if(set[v] == false){
			DFS(v,head,partsum,cnt);
		}
	}
}
void allDFS(){
	for(int i = 0 ;i < allnum ;i++){
		if(set[i] == false){
			int head = i;
			int partsum = 0;
			int cnt = 0;
			DFS(i,head,partsum,cnt);
			if(partsum/2 > k && cnt > 2){
				GangNum++;
				Gang[numtostr[head]] = cnt;
			}
		}
	}
}

int main(int argc, char** argv) {
	string a,b;
	int w;
	scanf("%d %d", &n, &k);
	for(int i = 0 ;i < n; i++){
		cin>>a>>b>>w;
		int id1 = StrChangeToNum(a);
		int id2 = StrChangeToNum(b);
		weight[id1] += w;
		weight[id2] += w;
		graph[id1].push_back(id2);
		graph[id1].push_back(id1);
	}
	allDFS();
	cout<<GangNum<<endl;
	for(map<string, int>::iterator it = Gang.begin();it != Gang.end();it++){
		cout << it->first <<" "<<it->second<<endl;
	}
	
	return 0;
}

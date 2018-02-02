#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxC = 2510;
const int maxn = 40010;
char name[maxn][5];
vector<int> course[maxC];
bool cmp(int a,int b){
	return strcmp(name[a], name[b]) < 0;
}
int main(int argc, char** argv) {
	int n, k, courseNum, courseID;
	scanf("%d %d", &n, &k);
	for(int i = 0;i < n; i++){
		scanf("%s %d",name[i], &courseNum);
		for(int j = 0;j < courseNum;j++){
			scanf("%d", &courseID);
			course[courseID].push_back(i);			
		}
	}
	for(int i = 1;i <= k;i++){
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j = 0; j < course[i].size();j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
}

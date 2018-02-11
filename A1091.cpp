#include <iostream>
#include <queue>
using namespace std;
struct NODE{
	int x, y, z;
}node;
int pixel[1300][130][70], n, m, slice, t;
bool vis[1300][130][70] = {false};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
bool judge(int x, int y, int z){
	if(x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0){
		return false;
	}
	if(pixel[x][y][z] == 0 || vis[x][y][z] == true){
		return false;
	}
	return true;
}
int BFS(int x, int y, int z){
	int sum = 0;
	queue<NODE> q;
	node.x = x;
	node.y = y;
	node.z = z;
	q.push(node);
	vis[x][y][z] = true;
	while( !q.empty() ){
		NODE temp = q.front();
		q.pop();
		sum++;
		for(int i = 0 ;i < 6;i++){
			int nowx = temp.x + X[i];
			int nowy = temp.y + Y[i];
			int nowz = temp.z + Z[i];
			if(judge(nowx, nowy, nowz)){
				node.x = nowx;
				node.y = nowy;
				node.z = nowz;
				q.push(node);
				vis[nowx][nowy][nowz] = true;
			}
		}
	}
	if(sum >= t){
		return sum;
	}else {return 0;
	}
}

int main(int argc, char** argv) {
	scanf("%d%d%d%d", &n, &m, &slice, &t);
	for(int z = 0;z < slice;z++){
		for(int x = 0; x < n; x++){
			for(int y = 0; y < m; y++){
				scanf("%d", &pixel[x][y][z]);
			}
		}
	}
	int ans = 0;
	for(int z = 0;z < slice;z++){
		for(int x = 0; x < n; x++){
			for(int y = 0; y < m; y++){
				if(pixel[x][y][z] == 1 && vis[x][y][z] == false){
					ans += BFS(x, y, z);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

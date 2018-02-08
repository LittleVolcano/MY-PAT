#include <iostream>
#include <algorithm>
using namespace std; 
const int INF = 1000000000;
const int MAXV = 200;//最大顶点数
int n, m;
int origin[MAXV][MAXV], dis[MAXV][MAXV];
void Floyd(){
	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			for(int j = 0; j < n;j++){
				if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k]+dis[k][j] < dis[i][j]){//找到最短路了 
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
} 
void putinArry(){
	int temp;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			scanf("%d", &temp);
			if(temp == -1){
				origin[i][j] = INF;
			}else{
				origin[i][j] = temp;
			}
			
		}
	}
}
int main(int argc, char** argv) {
	fill(origin[0], origin[0] + MAXV * MAXV,INF);
	printf("输入节点总数，回车结束：\n");
	scanf("%d",&n);
	printf("输入距离矩阵（无直接路径用-1表示,自己到自己用0）：\n");
	putinArry();//输入距离矩阵
	while(1){//每次少放一个 
		printf("输入不做计算的节点号（从0开始编号）：\n");
		int sub;
		scanf("%d", &sub);
		for(int i = 0; i < n;i++){
			for(int j = 0;j < n;j ++){
				dis[i][j] = origin[i][j];
			}
		}
		for(int i = 0; i < n;i++){
			dis[i][sub] = INF;
			dis[sub][i] = INF;
		}
		Floyd();
		for(int i = 0; i < n;i++){
			for(int j = 0;j < n;j ++){
				if(dis[i][j] == INF){
					printf(" * ");
				}else printf(" %d ",dis[i][j]);
			}
			printf("\n");
		}
	} 
	return 0;
}

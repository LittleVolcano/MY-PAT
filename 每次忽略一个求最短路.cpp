#include <iostream>
#include <algorithm>
#include <stdio.h>
FILE* fp;
FILE* fp2;
using namespace std; 
const double INF = 100000000.0;
const int MAXV = 200;//最大顶点数
int n, m;
double origin[MAXV][MAXV], dis[MAXV][MAXV];
void Floyd(){
	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			for(int j = 0; j < n;j++){
				if(dis[i][k] < 10000000.0 && dis[k][j] < 10000000.0 && dis[i][k]+dis[k][j] < dis[i][j]){//找到最短路了 
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
} 
void putinArry(){
	double temp;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			fscanf(fp, "%lf", &temp);
			if(temp < 0){
				origin[i][j] = INF;
			}else{
				origin[i][j] = temp;
			}	
		}
	}
}
int main(int argc, char** argv) {
//	printf("输入格式：\n第一行节点总数，回车结束：\n");
//	printf("从第二行开始输入距离矩阵（无直接路径用-1表示,自己到自己用0）：\n");
//	printf("每行一个标号，输入不做计算的节点号（从0开始编号）：\n");	
	if((fp = fopen("输入.txt","r")) == NULL){
		printf("cannot open this file!\n");
		exit(0);
	}
	if((fp2 = fopen("result.txt","w+")) == NULL){
		printf("cannot write this file!\n");
		exit(0);
	}
	fill(origin[0], origin[0] + MAXV * MAXV,INF);
	fscanf(fp,"%d",&n);
	putinArry();//输入距离矩阵
	while(1){//每次少放一个 
		int sub;
		if(feof(fp)){
			break;	
		}
		fscanf(fp, "%d", &sub);
		fprintf(fp2, "不计算的节点标号为：%d\n",sub);
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
				if(dis[i][j] > 10000000.0){
					fprintf(fp2, "  *  ");
				}else{
					fprintf(fp2, "  %.2lf  ",dis[i][j]);
				} 
			}
			fprintf(fp2, "\n");
		}
		fprintf(fp2, "\n\n");
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}

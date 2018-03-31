#include <iostream>
#include <algorithm>
#include <stdio.h>
FILE* fp;
FILE* fp2;
using namespace std; 
const double INF = 100000000.0;
const int MAXV = 200;//��󶥵���
int n, m;
double origin[MAXV][MAXV], dis[MAXV][MAXV];
void Floyd(){
	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			for(int j = 0; j < n;j++){
				if(dis[i][k] < 10000000.0 && dis[k][j] < 10000000.0 && dis[i][k]+dis[k][j] < dis[i][j]){//�ҵ����·�� 
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
//	printf("�����ʽ��\n��һ�нڵ��������س�������\n");
//	printf("�ӵڶ��п�ʼ������������ֱ��·����-1��ʾ,�Լ����Լ���0����\n");
//	printf("ÿ��һ����ţ����벻������Ľڵ�ţ���0��ʼ��ţ���\n");	
	if((fp = fopen("����.txt","r")) == NULL){
		printf("cannot open this file!\n");
		exit(0);
	}
	if((fp2 = fopen("result.txt","w+")) == NULL){
		printf("cannot write this file!\n");
		exit(0);
	}
	fill(origin[0], origin[0] + MAXV * MAXV,INF);
	fscanf(fp,"%d",&n);
	putinArry();//����������
	while(1){//ÿ���ٷ�һ�� 
		int sub;
		if(feof(fp)){
			break;	
		}
		fscanf(fp, "%d", &sub);
		fprintf(fp2, "������Ľڵ���Ϊ��%d\n",sub);
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

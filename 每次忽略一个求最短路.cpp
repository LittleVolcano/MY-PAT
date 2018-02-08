#include <iostream>
#include <algorithm>
using namespace std; 
const int INF = 1000000000;
const int MAXV = 200;//��󶥵���
int n, m;
int origin[MAXV][MAXV], dis[MAXV][MAXV];
void Floyd(){
	for(int k = 0;k < n;k++){
		for(int i = 0;i < n;i++){
			for(int j = 0; j < n;j++){
				if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k]+dis[k][j] < dis[i][j]){//�ҵ����·�� 
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
	printf("����ڵ��������س�������\n");
	scanf("%d",&n);
	printf("������������ֱ��·����-1��ʾ,�Լ����Լ���0����\n");
	putinArry();//����������
	while(1){//ÿ���ٷ�һ�� 
		printf("���벻������Ľڵ�ţ���0��ʼ��ţ���\n");
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

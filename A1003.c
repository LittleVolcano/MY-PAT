#include<stdio.h>    
#include<string.h>    

int N, M, C1, C2, x, y, z;  
int v[510], dis[510], map[510][510], vis[510], ans[510];  //数组括号只能放整数常量，不能是变量 
int cnt[510];  
int i;
int main()  
{  
    scanf("%d%d%d%d", &N, &M, &C1, &C2);  
    for (i = 0; i<N; i++) scanf("%d", &v[i]);  
    memset(map, -1, sizeof(map));  
    memset(dis, -1, sizeof(dis));  
    while (M--)  
    {  
        scanf("%d%d%d", &x, &y, &z);  
        map[x][y] = map[y][x] = z;  
    }  
    ans[C1] = v[C1]; dis[C1] = 0;  cnt[C1] = 1;  
    while (1)  
    {  
        int now = -1;  
        for (i = 0; i<N; i++)  
            if (!vis[i] && dis[i] != -1)  
            {  
                if (now == -1) now = i; else now = dis[now] < dis[i] ? now : i;  
            }  
        if (now == -1) break;  
        vis[now] = 1;  
        for (i = 0; i < N; i++)  
        {  
            if (map[now][i] != -1)  
            {  
                if (dis[i] == -1 || dis[i]>dis[now] + map[now][i])  
                {   
                    dis[i] = dis[now] + map[now][i];   
                    cnt[i] = cnt[now]; ans[i] = ans[now] + v[i];  
                }  
                else if (dis[i] == dis[now] + map[now][i])
				{
					cnt[i] += cnt[now];
					if(ans[i] <= ans[now] + v[i])
					{
						ans[i] = ans[now] + v[i];
					}
				} 
            }  
        }  
    }  
    printf("%d %d\n", cnt[C2], ans[C2]);  
    return 0;  
} 


#include <cstdio>
#include <stdio.h>
#include <cstring>

struct Student
{
	char id[12],password[12];
	int flag;
}stu[1010];
int main()
{
	int N,count = 0;
	scanf("%d", &N);
	for(int i = 0;i < N ; ++i )//������Щ�˵���Ϣ
	{
		scanf("%s %s", stu[i].id, stu[i].password);
		stu[i].flag = 0;
	}
	for(int i = 0;i < N ; ++i )//�ж��Ƿ�Ҫ�޸ģ�����count��¼Ҫ�޸�����
	{
		int len = strlen(stu[i].password);
		//printf("%d\n",len);
		for(int j = 0;j < len ; ++j )
		{
			if(stu[i].password[j] == '1')
			{
				stu[i].password[j] = '@';
				stu[i].flag = 1;
			}
			else if(stu[i].password[j] == 'l')
			{
				stu[i].password[j] = 'L';
				stu[i].flag = 1;
			}
			else if(stu[i].password[j] == '0')
			{
				stu[i].password[j] = '%';
				stu[i].flag = 1;
			}
			else if(stu[i].password[j] == 'O')
			{
				stu[i].password[j] = 'o';
				stu[i].flag = 1;
			}

		}
		//printf("countΪ��%d NΪ:%d\n",count,N);
		if(stu[i].flag == 1)
			++count;
	}
	//printf("countΪ��%d NΪ:%d\n",count,N);
	if(count == 0)//û��Ҫ�޸ĵ�
		{
			if(N == 1)
				printf("There is %d account and no account is modified",N);
			else printf("There are %d accounts and no account is modified",N);
		}
	else 
		{
			printf("%d\n",count);
			for(int i = 0;i < N ; ++i )
				if(stu[i].flag == 1)
				printf("%s %s\n",stu[i].id,stu[i].password);
		}
	

	
	return 0;
}


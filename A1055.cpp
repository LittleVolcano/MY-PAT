
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
struct Man
{
	char name[10];
	int age,worths;
}man[100010],temp[20010];
bool cmp(Man a,Man b)
{
	if(a.worths != b.worths)
		return a.worths > b.worths;
	else if(a.age != b.age)
		return a.age < b.age;
	else return strcmp(a.name , b.name) < 0;
}


int main()
{
	int n,k;
	int tempnum = 0;
	int Age[210] = {0};
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s%d%d",man[i].name,&man[i].age,&man[i].worths);
	}
	sort(man , man + n , cmp);
	for(int i = 0; i < n; ++i)//yu chu li
	{
		if( Age[man[i].age] < 100)
		{
			Age[man[i].age]++;
			temp[tempnum++] = man[i];
		}

	}
	int m,ageL,ageR;
	for(int i = 0; i < k; ++i)
	{
		scanf("%d %d %d",&m,&ageL,&ageR);
		printf("Case #%d:\n", i + 1);
		int num = 0;
		for( int j = 0; j < tempnum && num < m; ++j)
		{
			if(temp[j].age >= ageL && temp[j].age <= ageR )
			{
				printf("%s %d %d\n",temp[j].name,temp[j].age,temp[j].worths);
				++ num;
			}
		}
		if(num == 0)
			printf("None\n");

	}





	return 0;
}


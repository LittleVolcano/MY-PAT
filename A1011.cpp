
#include <stdio.h>
int main()
{
	int i,j,k;
	double max,ans,sum = 1;
	double game[3];
	char S[3] = {'W','T','L'};
	for(i = 0;i < 3 ; ++i)
	{
		scanf("%lf %lf %lf",&game[0], &game[1], &game[2]);
		max = game[0];
		k = 0;
		for(j = 1 ;j < 3; ++j )
		{
			if(max < game[j])
			{
				max = game[j];
				k = j;
			}
			
		}
		sum *= game[k];
		printf("%c ",S[k]);
	}
	ans = (sum * 0.65 - 1) * 2;
	printf("%.2f",ans);
	return 0;
}


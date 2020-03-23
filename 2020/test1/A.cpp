#include <cstdio>
#include <iostream>
using namespace std;
int sum,ma,mb,mc;
int main()
{
	int n;
	scanf("%d",&n);
	int p = n / 14;
	sum = 1e9;
	for(int i = max(1,p - 1000);i <= min(n,p + 1000); ++i)
	{
		for(int j = max(1,p - 1000);j <= min(n,p + 1000); ++j)
		{
			int res = n - i * 7 - j * 4;
			if(res < 3 || res % 3 != 0)
			{
				continue;
			}
			res /= 3;
			int mix = min(i,min(j,res));
			if(mix < sum)
			{
				sum = mix;
				ma = i,mb = j,mc = res;
			}
			else if(mix == sum)
			{
				if(i + j + res > ma + mb + mc)
				{
					ma = i,mb = j,mc = res;
				}
			}
		}
	}
	if(sum == 1e9)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d %d %d\n",ma,mb,mc);
	}
	return 0;
}
//http://codeforces.com/contest/263/problem/A
#include <cstdio>
using namespace std;
int abs(int x)
{
	return x >= 0 ? x : -x;
}
int main()
{
	int x,y;
	for(int i = 1;i <= 5; ++i)
	{
		for(int j = 1;j <= 5; ++j)
		{
			int p;
			scanf("%d",&p);
			if(p == 1)
			{
				x = i,y = j;
			}
		}
	}
	printf("%d\n",abs(x - 3) + abs(y - 3));
	return 0;
}
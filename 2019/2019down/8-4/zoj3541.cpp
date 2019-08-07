#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 205;
const int inf = 1e9 + 7;
int t[maxn],d[maxn],dp[maxn][maxn][2],pre[maxn][maxn][2];
int go(int l,int r,int p)
{
	int tmp,add;
	int& ret = dp[l][r][p];
	if(ret == -1)
	{
		if(l == r)
		{
			ret = 0;
		}
		else
		{
			ret = inf;
			tmp = d[l + 1] - d[l] + go(l + 1,r,0);
			add = (p == 0 ? 0 : d[r] - d[l]);
			if(t[l] > tmp && ret > (tmp + add))
			{
				ret = tmp + add;
				pre[l][r][p] = 0;
			}
			tmp = d[r] - d[r - 1] + go(l,r - 1,1);
			add = (p == 1 ? 0 : d[r] - d[l]);
			if(t[r] > tmp && ret > (tmp + add))
			{
				ret = tmp + add;
				pre[l][r][p] = 1;
			}
		}
	}
	return ret;
}
void output(int l,int r,int p)
{
	if(l == r)
	{
		printf("%d\n",l + 1);
	}
	else if(pre[l][r][p] == 0)
	{
		printf("%d ",l + 1);
		output(l + 1,r,0);
	}
	else
	{
		printf("%d ",r + 1);
		output(l,r - 1,1);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0;i < n; ++i)
		{
			scanf("%d",&t[i]);
		}
		for(int i = 0;i < n; ++i)
		{
			scanf("%d",&d[i]);
		}
		memset(dp,-1,sizeof(dp));
		if(go(0,n - 1,0) == inf)
		{
			printf("Mission Impossible\n");
		}
		else
		{
			output(0,n - 1,0);
		}
	}
	return 0;
}
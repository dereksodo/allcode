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
#include <numeric>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 10005;
const int maxm = 2005;
int x[maxn],y[maxn],low[maxn],high[maxn];
int f[maxn][maxm];
int e[maxn];
int main(int argc, char const *argv[])
{
	int n,m,p;
	cin>>n>>m>>p;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		low[i] = 1;
		high[i] = m;
	}
	int a,b,c;
	for(int i = 1;i <= p; ++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		e[a] = 1;
		low[a] = b + 1;
		high[a] = c - 1;
	}
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i = 1;i <= m; ++i)
	{
		f[0][i] = 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = x[i] + 1;j <= m + x[i]; ++j)
		{
			f[i][j] = min(f[i - 1][j - x[i]] + 1,f[i][j - x[i]] + 1);
		}
		for(int j = m + 1;j <= m + x[i]; ++j)
		{
			f[i][m] = min(f[i][m],f[i][j]);
		}
		for(int j = 1;j <= m - y[i]; ++j)
		{
			f[i][j] = min(f[i][j],f[i - 1][j + y[i]]);
		}
		for(int j = 1;j < low[i]; ++j)
		{
			f[i][j] = f[0][0];
		}
		for(int j = high[i] + 1;j <= m; ++j)
		{
			f[i][j] = f[0][0];
		}
	}
	int ans = f[0][0];
	for(int j = 1;j <= m; ++j)
	{
		ans = min(ans,f[n][j]);
	}
	if(ans < f[0][0])
	{
		printf("1\n%d\n",ans);
	}
	else
	{
		int i,j;
		for(i = n;i >= 1; --i)
		{
			for(j = 1;j <= m; ++j)
			{
				if(f[i][j] < f[0][0])
				{
					break;
				}
			}
			if(j <= m)
			{
				break;
			}
		}
		ans = 0;
		for(int j = 1;j <= i; ++j)
		{
			if(e[j])
			{
				ans++;
			}
		}
		printf("0\n%d\n",ans);
	}
	return 0;
}
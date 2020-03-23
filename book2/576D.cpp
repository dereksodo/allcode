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
#include <sstream>
#include <bitset>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 160;
const int inf = 0x3f3f3f3f;
struct cyc{
	int x,y,d;
}e[maxn];
int n,m,mp[maxn][maxn];
bitset<maxn> a[maxn],ans[maxn],c[maxn],z[maxn];
bool cmp(cyc a,cyc b)
{
	return a.d < b.d;
}
void mul(bitset<maxn> a[maxn],bitset<maxn> b[maxn])
{
	for(int i = 1;i <= n; ++i)
	{
		c[i].reset();
	}
	for(int k = 1;k <= n; ++k)
	{
		for(int i = 1;i <= n; ++i)
		{
			if(a[i][k])
			{
				c[i] |= b[k];
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		a[i] = c[i];
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].d);
	}
	sort(e + 1,e + m + 1,cmp);
	for(int i = 1;i <= n; ++i)
	{
		ans[i].reset();
	}
	for(int i = 1;i <= n; ++i)
	{
		ans[i][i] = 1;
	}
	int ret = inf;
	for(int b = 1;b <= m; ++b)
	{
		for(int i = 1;i <= n; ++i)
		{
			a[i].reset();
		}
		for(int i = 1;i < b; ++i)
		{
			a[e[i].x][e[i].y] = 1;
		}
		int k = e[b].d - e[b - 1].d;
		while(k)
		{
			if(k & 1)
			{
				mul(ans,a);
			}
			mul(a,a);
			k >>= 1;
		}
		memset(mp,0x3f,sizeof(mp));
		for(int i = 1;i <= n; ++i)
		{
			mp[i][i] = 0;
		}
		for(int j = 1;j <= b; ++j)
		{
			mp[e[j].x][e[j].y] = 1;
		}
		for(int k = 1;k <= n; ++k)
		{
			for(int i = 1;i <= n; ++i)
			{
				for(int j = 1;j <= n; ++j)
				{
					mp[i][j] = min(mp[i][j],mp[i][k] + mp[k][j]);
				}
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			if(ans[1][i])
			{
				ret = min(ret,e[b].d + mp[i][n]);
			}
		}
	}
	if(ret == inf)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%d\n",ret);
	}
	return 0;
}
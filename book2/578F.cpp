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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 105;
const int maxm = 505;
int n,m,mod,f[maxn * maxn],id[maxn * maxn],tot[2];
char a[maxn][maxn];
int getid(int x,int y)
{
	return x * (m + 1) + y;
}
int ff(int x){return x == f[x] ? x : (f[x] = ff(f[x]));}
void merge(int x,int y)
{
	x = ff(x),y = ff(y);
	f[y] = x;
}
int mypow(int x,int y)
{
	int ret = 1;
	for(;y;y >>= 1,x = (ll)x * x % mod)
	{
		if(y & 1)
		{
			ret = (ll)ret * x % mod;
		}
	}
	return ret;
}
struct Graph{
	int a[maxm][maxm];
	void add(int x,int y)
	{
		a[x][x]++;
		a[y][y]++;
		a[x][y]--;
		a[y][x]--;
	}
	int det(int n)
	{
		int ret = 1;
		for(int i = 1;i <= n; ++i)
		{
			if(!a[i][i])
			{
				for(int j = i + 1;j <= n; ++j)
				{
					if(a[j][i])
					{
						for(int k = i;k <= n; ++k)
						{
							swap(a[i][k],a[j][k]);
						}
						ret = -ret;
						break;
					}
				}
			}
			if(!a[i][i])
			{
				break;
			}
			int inv = mypow(a[i][i],mod - 2);
			for(int j = i + 1;j <= n; ++j)
			{
				int w = (ll)a[j][i] * inv % mod;
				for(int k = i;k <= n; ++k)
				{
					(a[j][k] -= (ll)w * a[i][k] % mod) %= mod;
				}
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			ret = (ll)ret * a[i][i] % mod;
		}
		return ret;
	}
}G[2];
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&mod);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%s",a[i] + 1);
	}
	for(int i = 0;i <= (n + 1) * (m + 1); ++i)
	{
		f[i] = i;
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(a[i][j] == '/')
			{
				merge(getid(i,j - 1),getid(i - 1,j));
			}
			if(a[i][j] == '\\')
			{
				merge(getid(i - 1,j - 1),getid(i,j));
			}
		}
	}
	for(int i = 0;i <= n; ++i)
	{
		for(int j = 0;j <= m; ++j)
		{
			int x = getid(i,j);
			if(f[x] == x)
			{
				id[x] = ++tot[(i + j) & 1];
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(a[i][j] == '*')
			{
				G[(i + j) & 1].add(id[ff(getid(i - 1,j - 1))],id[ff(getid(i,j))]);
				G[((i + j) & 1) ^ 1].add(id[ff(getid(i,j - 1))],id[ff(getid(i - 1,j))]);
			}
		}
	}
	int ans = (G[0].det(tot[0] - 1) + G[1].det(tot[1] - 1)) % mod;
	printf("%d\n",(ans + mod) % mod);
	return 0;
}
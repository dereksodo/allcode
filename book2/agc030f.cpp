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
const int mod = 1e9 + 7;
const int maxn = 305;
void add(int &x,int y)
{
	x += y;
	if(x >= mod)
	{
		x -= mod;
	}
}
int n,m,ans,a[maxn << 1];
int cnt1,cnt2,f[maxn << 1][maxn][maxn];
int s[maxn << 1],vis[maxn << 1],book[maxn << 1];
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 1;i <= n + n; ++i)
	{
		scanf("%d",a + i);
	}
	for(int i = 1;i <= n + n;i += 2)
	{
		if(a[i] == -1 && a[i + 1] == -1)
		{
			++cnt1;
		}
		else if(a[i] > 0 && a[i + 1] > 0)
		{
			vis[a[i]] = vis[a[i + 1]] = 1;
		}
		else
		{
			++cnt2,book[a[i] == -1 ? a[i + 1] : a[i]] = 1;
		}
	}
	for(int i = n + n;i; --i)
	{
		if(!vis[i])
		{
			s[++m] = i;
		}
	}
	f[0][0][0] = 1;
	for(int i = 1;i <= m; ++i)
	{
		for(int j = 0;j <= cnt1 + cnt2; ++j)
		{
			for(int k = 0;k <= cnt2; ++k)
			{
				if(!f[i - 1][j][k])
				{
					continue;
				}
				if(!book[s[i]])
				{
					add(f[i][j + 1][k],f[i - 1][j][k]);
					if(j)
					{
						add(f[i][j - 1][k],f[i - 1][j][k]);
					}
					if(k)
					{
						add(f[i][j][k - 1],1ll * k * f[i - 1][j][k] % mod);
					}
				}
				else
				{
					add(f[i][j][k + 1],f[i - 1][j][k]);
					if(j)
					{
						add(f[i][j - 1][k],f[i - 1][j][k]);
					}
				}
			}
		}
	}
	ans = f[m][0][0];
	for(int i = 1;i <= cnt1; ++i)
	{
		ans = 1ll * ans * i % mod;
	}
	printf("%d\n",ans);
	return 0;
}
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
const int maxn = 1010;
const int maxm = 50010;
int n,m;
int deg[maxm << 2],vis[maxm << 2],f[maxm << 2];
int vis2[maxm << 2];
int ff(int x)
{
	return f[x] == x ? x : (f[x] = ff(f[x]));
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		f[i] = i;
	}
	for(int i = 0,x,y;i < m; ++i)
	{
		scanf("%d%d",&x,&y);
		if(x == 0)
		{
			++n;
			f[n] = x = n;
		}
		if(y == 0)
		{
			++n;
			f[n] = y = n;
		}
		deg[x]++;
		deg[y]++;
		f[ff(x)] = ff(y);
	}
	int ans = 0,cnt = 0,num = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(deg[i] == 0)
		{
			continue;
		}
		if(ff(i) == i)
		{
			++num;
		}
		if(deg[i] & 1)
		{
			vis[f[i]] = 1,cnt++;
		}
		if(deg[i] > 2)
		{
			vis2[f[i]] = 1,ans++;
		}
	}
	if(num != 1)
	{
		for(int i = 1;i <= n; ++i)
		{
			if(deg[i] != 0 && f[i] == i && vis[i] == 0)
			{
				cnt += 2;
				if(!vis2[i])
				{
					++ans;
				}
			}
		}
	}
	ans += cnt / 2;
	printf("%d\n",ans);
	return 0;
}
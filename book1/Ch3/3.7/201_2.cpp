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
const int maxn = 100005;
int f[maxn],deg[maxn],odd[maxn],vis[maxn];
int ff(int x)
{
	return f[x] == x ? x : (f[x] = ff(f[x]));
}
void join(int x,int y)
{
	x = ff(x),y = ff(y);
	if(x == y)
	{
		return;
	}
	f[y] = x;
	return;
}
int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i = 1;i <= n; ++i)
		{
			f[i] = i;
			deg[i] = vis[i] = odd[i] = 0;
		}
		for(int i = 0,x,y;i < m; ++i)
		{
			scanf("%d%d",&x,&y);
			deg[x]++,deg[y]++;
			join(x,y);
		}
		vector<int> v;
		for(int i = 1;i <= n; ++i)
		{
			int fa = ff(i);
			if(!vis[fa])
			{
				v.push_back(fa);
				vis[fa] = 1;
			}
			if(deg[i] & 1)
			{
				odd[fa]++;
			}
		}
		int ans = 0;
		for(int i = 0;i < v.size(); ++i)
		{
			int k = v[i];
			if(deg[k] != 0)
			{
				if(odd[k] == 0)
				{
					++ans;
				}
				else
				{
					ans += odd[k] / 2;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
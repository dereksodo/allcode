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
const int maxn = 1050;
int f[maxn],vis[maxn],cnt[maxn],in[maxn],out[maxn];
int ff(int x)
{
	return f[x] == x ? x : (f[x] = ff(f[x]));
}
void join(int u,int v)
{
	u = ff(u),v = ff(v);
	f[v] = u;
}
set< pair<int,int> > s;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i < maxn; ++i)
	{
		f[i] = i;
	}
	int del = 0;
	for(int i = 1,u,v;i <= n; ++i)
	{
		scanf("%d%d",&u,&v);
		if(s.find(make_pair(u,v)) != s.end())
		{
			++del;
			continue;
		}
		s.insert(make_pair(u,v));
		vis[u] = vis[v] = 1;
		out[u]++,in[v]++;
		join(u,v);
	}
	int ans = 0;
	for(int i = 1;i < maxn; ++i)
	{
		if(vis[i])
		{
			cnt[ff(i)] += abs(in[i] - out[i]);
		}
	}
	for(int i = 1;i < maxn; ++i)
	{
		if(vis[i] && f[i] == i)
		{
			ans++;
			ans += max(0,(cnt[i] - 2) / 2);
		}
	}
	printf("%d\n",ans + n - del);
	return 0;
}
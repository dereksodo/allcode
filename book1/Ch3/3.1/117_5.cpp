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
const int maxn = 1005;
const int mod = 31011;
struct Edge{
	int u,v,w;
	bool operator <(const Edge &b)const
	{
		return w < b.w;
	}
}e[maxn];
int n,m,f[maxn],l[maxn],r[maxn],c[maxn];
int sum,cnt;
int ff(int x)
{
	return f[x] == x ? x : ff(f[x]);
}
void dfs(int now,int x,int num)
{
	if(now > r[x])
	{
		sum += (num == c[x]);
		return;
	}
	int f1 = ff(e[now].u);
	int f2 = ff(e[now].v);
	if(f1 != f2)
	{
		f[f1] = f2;
		dfs(now + 1,x,num + 1);
		f[f1] = f1,f[f2] = f2;
	}
	dfs(now + 1,x,num);
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e + 1,e + m + 1);
	for(int i = 1;i <= n; ++i)
	{
		f[i] = i;
	}
	int tot = 0;
	for(int i = 1;i <= m; ++i)
	{
		if(e[i].w != e[i - 1].w)
		{
			r[cnt] = i - 1;
			l[++cnt] = i;
		}
		int f1 = ff(e[i].u);
		int f2 = ff(e[i].v);
		if(f1 != f2)
		{
			++c[cnt];
			f[f1] = f2;
			++tot;
		}
	}
	r[cnt] = m;
	if(tot != n - 1)
	{
		printf("0\n");
		return 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		f[i] = i;
	}
	int ans = 1;
	for(int i = 1;i <= cnt; ++i)
	{
		sum = 0;
		dfs(l[i],i,0);
		ans = ans * sum % mod;
		for(int j = l[i];j <= r[i]; ++j)
		{
			f[ff(e[j].u)] = ff(e[j].v);
		}
	}
	printf("%d\n",ans);
	return 0;
}
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
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
struct bit{
	int n;
	ll a[maxn];
	void add(int p,ll x)
	{
		for(;p <= n;p += p & -p)
		{
			a[p] += x;
		}
	}
	ll query(int p)
	{
		ll ret = 0;
		for(;p;p -= p & -p)
		{
			ret += a[p];
		}
		return ret;
	}
}b1,b2;
struct node{
	int n;
	int head[maxm],nxt[maxm],to[maxm],tot;
	int st[maxn],en[maxn],dep[maxn],id;
	void add(int u,int v)
	{
		to[++tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	void dfs(int u)
	{
		st[u] = ++id;
		for(int i = head[u];i;i = nxt[i])
		{
			int v = to[i];
			if(st[v])
			{
				continue;
			}
			dep[v] = dep[u] + 1;
			dfs(v);
		}
		en[u] = id;
	}
	void prepare()
	{
		id = 0;
		dfs(1);
		b1.n = b2.n = n;
	}
	void add1(int u,int x)
	{
		b1.add(st[u],x);
		b1.add(en[u] + 1,-x);
	}
	void add2(int u,int x)
	{
		b1.add(st[u],(ll)(1 - dep[u]) * x);
		b1.add(en[u] + 1,(ll)(dep[u] - 1) * x);
		b2.add(st[u],x);
		b2.add(en[u] + 1,-x);
	}
	ll query(int u)
	{
		return b1.query(st[u]) + b2.query(st[u]) * dep[u];
	}
}G;
int a[maxn],n,m;
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	G.n = n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1,u,v;i < n; ++i)
	{
		scanf("%d%d",&u,&v);
		G.add(u,v);
		G.add(v,u);
	}
	G.prepare();
	for(int i = 1;i <= n; ++i)
	{
		G.add1(i,a[i]);
	}
	while(m--)
	{
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op == 3)
		{
			printf("%lld\n",G.query(x));
		}
		else
		{
			scanf("%d",&y);
			if(op == 1)
			{
				G.add1(x,y);
			}
			else
			{
				G.add2(x,y);
			}
		}
	}
	return 0;
}
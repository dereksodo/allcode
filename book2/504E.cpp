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
const int maxn = 1000005;
const int LOG = 20;
int n;
ll mod = 1e9 + 7;
ll p = 31;
ll revP = 129032259;
ll powers[maxn];
ll rpowers[maxn];
void inithsh()
{
	powers[0] = rpowers[0] = 1;
	for(int j = 0;j <= n; ++j)
	{
		powers[j + 1] = powers[j] * p % mod;
		rpowers[j + 1] = rpowers[j] * revP % mod;
	}
}
int up[LOG][maxn];
vector<int> G[maxn];
ll UP[maxn],DOWN[maxn];
char str[maxn];
int tin[maxn],tout[maxn],h[maxn];
int timer = 0;
void dfs(int v,int par)
{
	tin[v] = timer++;
	up[0][v] = par;
	for(int i = 1;i < LOG; ++i)
	{
		up[i][v] = up[i - 1][up[i - 1][v]];
	}
	for(int i = 0;i < (int)G[v].size(); ++i)
	{
		int to = G[v][i];
		if(to == par)
		{
			continue;
		}
		h[to] = h[v] + 1;
		UP[to] = (UP[v] + (str[to] - 'a' + 1) * powers[h[to] - 1]) % mod;
		DOWN[to] = (DOWN[v] * p + str[to] - 'a' + 1) % mod;
		dfs(to,v);
	}
	tout[v] = timer++;
}
ll getUp(int v1,int v2)
{
	ll res;
	res = (UP[v1] - UP[up[0][v2]] + mod) * rpowers[h[v2] - 1];
	if(res >= mod)
	{
		res %= mod;
	}
	return res;
}
ll getDown(int v1,int v2)
{
	ll res = DOWN[v2] - DOWN[v1] * powers[h[v2] - h[v1]] % mod + mod;
	if(res >= mod)
	{
		res %= mod;
	}
	return res;
}
bool upper(int a,int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a,int b)
{
	if(upper(a,b))
	{
		return a;
	}
	if(upper(b,a))
	{
		return b;
	}
	for(int i = LOG - 1;i >= 0; --i)
	{
		if(!upper(up[i][a],b))
		{
			a = up[i][a];
		}
	}
	return up[0][a];
}
int get(int v,int k)
{
	for(int i = 0;i < LOG; ++i)
	{
		if(k & (1 << i))
		{
			v = up[i][v];
		}
	}
	return v;
}
ll gethash(int a,int b,int l,int cnt)
{
	int len = h[a] + h[b] - 2 * h[l] + 1;
	if(cnt > h[a] - h[l] + 1)
	{
		ll h1 = getUp(a,l);
		int v = get(b,len - cnt);
		ll h2 = getDown(1,v);
		h2 -= (str[l] - 'a' + 1) * powers[h[v] - h[l]] % mod;
		if(h2 < 0)
		{
			h2 += mod;
		}
		return (h1 * powers[h[v] - h[l]] + h2) % mod;
	}
	else
	{
		int v = get(a,cnt - 1);
		return getUp(a,v);
	}
}
const int maxm = 1000005;
int a[maxm][2],b[maxm][2],lc[maxm][2],res[maxm << 1],needH[maxm << 1],l[maxm],r[maxm],len[maxm][2];
ll hashtolca[maxm][2];
int *queries[maxn];
int sz[maxn],cnt[maxn],pos = 0,st[maxn],ptr[maxn];
char used[maxn];
void dfsQ(int v,int par)
{
	st[pos] = v;
	ptr[pos] = 0;
	++pos;
	while(pos)
	{
		v = st[pos - 1];
		int &i = ptr[pos - 1];
		if(i == 0)
		{
			used[v] = 1;
			for(int j = 0;j < sz[v]; ++j)
			{
				int q = queries[v][j];
				res[q] = st[pos - needH[q] - 1];
			}
			sz[v] = 0;
		}
		if(i < (int)G[v].size())
		{
			int to = G[v][i++];
			if(!used[to])
			{
				st[pos] = to;
				ptr[pos] = 0;
				++pos;
			}
		}
		else
		{
			used[v] = 0;
			--pos;
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	inithsh();
	scanf("%s",str);
	for(int i = 0;i < n - 1; ++i)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		--s,--t;
		G[s].push_back(t);
		G[t].push_back(s);
	}
	G[n].push_back(0);
	dfs(n,n);
	int q;
	scanf("%d",&q);
	for(int i = 0;i < q; ++i)
	{
		for(int j = 0;j < 2; ++j)
		{
			scanf("%d%d",&a[i][j],&b[i][j]);
			--a[i][j],--b[i][j];
			int A = a[i][j];
			int B = b[i][j];
			cnt[A]++,cnt[B]++;
			int c = lc[i][j] = lca(A,B);
			len[i][j] = h[A] + h[B] - 2 * h[c] + 1;
			hashtolca[i][j] = (getUp(A,c) - DOWN[c] + mod) % mod;
		}
		l[i] = 0;
		r[i] = min(len[i][0],len[i][1]);
	}
	for(int i = 0;i < n; ++i)
	{
		queries[i] = new int[cnt[i]];
	}
	while(1)
	{
		bool ok = 1;
		for(int i = 0;i < q; ++i)
		{
			if(l[i] == r[i])
			{
				continue;
			}
			ok = 0;
			int m = (l[i] + r[i] + 1) >> 1;
			for(int j = 0;j < 2; ++j)
			{
				if(m > h[a[i][j]] - h[lc[i][j]])
				{
					needH[i * 2 + j] = len[i][j] - m;
					queries[b[i][j]][sz[b[i][j]]++] = i * 2 + j;
				}
				else
				{
					needH[i * 2 + j] = m;
					queries[a[i][j]][sz[a[i][j]]++] = i * 2 + j;
				}
			}
		}
		if(ok)
		{
			break;
		}
		dfsQ(0,0);
		for(int i = 0;i < q; ++i)
		{
			if(l[i] == r[i])
			{
				continue;
			}
			int m = (l[i] + r[i] + 1) >> 1;
			ll ha[2];
			for(int j = 0;j < 2; ++j)
			{
				if(m > h[a[i][j]] - h[lc[i][j]])
				{
					int v = res[i * 2 + j];
					ha[j] = hashtolca[i][j] * powers[h[v] - h[lc[i][j]]] + DOWN[v];
				}
				else
				{
					int v = res[i * 2 + j];
					ha[j] = (UP[a[i][j]] - UP[v] + mod) * rpowers[h[v]];
				}
			}
			if((ha[0] - ha[1]) % mod == 0)
			{
				l[i] = m;
			}
			else
			{
				r[i] = m - 1;
			}
		}
	}
	for(int i = 0;i < q; ++i)
	{
		printf("%d\n",l[i]);
	}
	return 0;
}
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
const int maxblcsz = 300;
int nxt[maxn][30],f[maxn],state[maxn],sz = 1;
int insert(string s)
{
	int v = 0;
	for(int i = 0;i < s.size(); ++i)
	{
		if(nxt[v][s[i] - 'a'] == 0)
		{
			nxt[v][s[i] - 'a'] = sz++;
		}
		v = nxt[v][s[i] - 'a'];
	}
	return v;
}
int q[maxn];
void aho()
{
	int h = 0,t = 0;
	for(int i = 0;i < 26; ++i)
	{
		if(nxt[0][i])
		{
			q[t++] = nxt[0][i];
		}
	}
	while(h < t)
	{
		int v = q[h++];
		for(int i = 0;i < 26; ++i)
		{
			if(nxt[v][i])
			{
				f[nxt[v][i]] = nxt[f[v]][i];
				q[t++] = nxt[v][i];
			}
			else
			{
				nxt[v][i] = nxt[f[v]][i];
			}
		}
	}
}
int head[maxn],nxt_g[maxn << 1],to[maxn << 1],tot;
void addedge(int u,int v)
{
	to[++tot] = v;
	nxt_g[tot] = head[u];
	head[u] = tot;
}
int st[maxn],fi[maxn],cnt;
void dfs(int v)
{
	st[v] = cnt++;
	for(int i = head[v];i;i = nxt_g[i])
	{
		dfs(to[i]);
	}
	fi[v] = cnt;
}
int tr[maxn];
void _add(int p,int v)
{
	for(;p > 0;p -= p & -p)
	{
		tr[p] += v;
	}
}
void add(int l,int r,int val)
{
	_add(r,val);
	_add(l,-val);
}
int get(int p)
{
	int ret = 0;
	for(++p;p < maxn;p += p & -p)
	{
		ret += tr[p];
	}
	return ret;
}
struct query{
	int r,k,id,sign;
	query(int _r = 0,int _k = 0,int _id = 0,int _sign = 0):r(_r),k(_k),id(_id),sign(_sign){};
}que[maxn << 1];
bool cmp(query x,query y)
{
	return x.r < y.r;
}
vector<query> qq[maxn];
ll ps[maxn],ans[maxn];
int sum[maxn],n;
void pre(int v)
{
	for(int i = head[v];i;i = nxt_g[i])
	{
		int u = to[i];
		pre(u);
		sum[v] += sum[u];
	}
}
string s[maxn];
void solve(int id)
{
	memset(sum,0x00,sizeof(sum));
	int v = 0;
	for(int i = 0;i < s[id].size(); ++i)
	{
		v = nxt[v][s[id][i] - 'a'];
		sum[v]++;
	}
	pre(0);
	for(int i = 0;i < n; ++i)
	{
		ps[i + 1] = ps[i] + sum[state[i]];
	}
	for(int i = 0;i < qq[id].size(); ++i)
	{
		ans[qq[id][i].id] += qq[id][i].sign * ps[qq[id][i].r];
	}
}
int main(int argc, char const *argv[])
{
	int q;
	scanf("%d%d",&n,&q);
	for(int i = 0;i < n; ++i)
	{
		cin>>s[i];
		state[i] = insert(s[i]);
	}
	aho();
	for(int i = 1;i < sz; ++i)
	{
		addedge(f[i],i);
	}
	dfs(0);
	sz = 0;
	for(int i = 0,l,r,k;i < q; ++i)
	{
		scanf("%d%d%d",&l,&r,&k);
		--l,--k;
		if(s[k].size() <= maxblcsz)
		{
			que[sz++] = query(r,k,i,1);
			que[sz++] = query(l,k,i,-1);
		}
		else
		{
			qq[k].push_back(query(r,k,i,1));
			qq[k].push_back(query(l,k,i,-1));
		}
	}
	for(int i = 0;i < n; ++i)
	{
		if(s[i].size() > maxblcsz)
		{
			solve(i);
		}
	}
	sort(que,que + sz,cmp);
	int ptr = 0;
	for(int i = 0;i < sz; ++i)
	{
		while(ptr < que[i].r)
		{
			add(st[state[ptr]],fi[state[ptr]],1);
			ptr++;
		}
		int v = 0;
		for(int j = 0;j < s[que[i].k].size(); ++j)
		{
			v = nxt[v][s[que[i].k][j] - 'a'];
			ans[que[i].id] += que[i].sign * get(st[v]);
		}
	}
	for(int i = 0;i < q; ++i)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}
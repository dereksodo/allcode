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
int dep[maxn],sz[maxn],f[maxn],son[maxn];
int top[maxn],rev[maxn],seg[maxn];
int head[maxn],nxt[maxn << 1],to[maxn << 1],tot;
int w[maxn],c[maxn];
int root[maxn],n,q,rot;
struct Ans{
	int mx,sum;
}ans;
struct node{
	int l,r,mx,sum;
}t[maxn << 5];
void addedge(int u,int v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
void dfs1(int u,int fa)
{
	dep[u] = dep[fa] + 1;
	f[u] = fa;
	sz[u] = 1;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v != fa)
		{
			dfs1(v,u);
			sz[u] += sz[v];
			if(sz[v] > sz[son[u]])
			{
				son[u] = v;
			}
		}
	}
}
void dfs2(int u,int tp)
{
	top[u] = tp;
	seg[u] = ++seg[0];
	rev[seg[u]] = u;
	if(!son[u])
	{
		return;
	}
	dfs2(son[u],tp);//not dfs2(son[u],u)
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(!top[v])
		{
			dfs2(v,v);
		}
	}
}
void pushup(int rt)
{
	t[rt].sum = t[t[rt].l].sum + t[t[rt].r].sum;
	t[rt].mx = max(t[t[rt].l].mx,t[t[rt].r].mx);
}
void update(int &rt,int l,int r,int x,int c)//order is important
{
	if(!rt)
	{
		rt = ++rot;
	}
	if(l == r && l == x)
	{
		t[rt].mx = t[rt].sum = c;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= x)
	{
		update(t[rt].l,l,mid,x,c);
	}
	else
	{
		update(t[rt].r,mid + 1,r,x,c);
	}
	pushup(rt);
}
void remove(int &rt,int l,int r,int k)
{
	if(l == r)
	{
		t[rt].sum = t[rt].mx = 0;
		return;
	}
	int mid = l + r >> 1;
	if(k <= mid)
	{
		remove(t[rt].l,l,mid,k);
	}
	else
	{
		remove(t[rt].r,mid + 1,r,k);
	}
	pushup(rt);
}
void query(int rt,int l,int r,int left,int right)
{
	if(right < l || left > r)
	{
		return;
	}
	if(left <= l && r <= right)
	{
		ans.sum += t[rt].sum;
		ans.mx = max(ans.mx,t[rt].mx);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= left)
	{
		query(t[rt].l,l,mid,left,right);
	}
	if(mid < right)
	{
		query(t[rt].r,mid + 1,r,left,right);
	}
}
void query(int u,int v)
{
	int col = c[u];
	ans.sum = ans.mx = 0;
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
		{
			swap(u,v);
		}
		query(root[col],1,n,seg[top[u]],seg[u]);
		u = f[top[u]];
	}
	if(dep[u] < dep[v])
	{
		swap(u,v);
	}
	query(root[col],1,n,seg[v],seg[u]);
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&w[i],&c[i]);
	}
	for(int i = 1,u,v;i < n; ++i)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i = 1;i <= n; ++i)
	{
		update(root[c[i]],1,n,seg[i],w[i]);
	}
	char buf[10];
	while(q--)
	{
		int u,v;
		scanf("%s%d%d",buf,&u,&v);
		if(buf[0] == 'C')
		{
			if(buf[1] == 'C')
			{
				remove(root[c[u]],1,n,seg[u]);
				update(root[v],1,n,seg[u],w[u]);
				c[u] = v;
			}
			else
			{
				remove(root[c[u]],1,n,seg[u]);//can't be forgotten
				update(root[c[u]],1,n,seg[u],v);
				w[u] = v;
			}
		}
		else
		{
			query(u,v);//solve for sum and mx
			if(buf[1] == 'S')
			{
				printf("%d\n",ans.sum);
			}
			else
			{
				printf("%d\n",ans.mx);
			}
		}
	}
	return 0;
}
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
int rev[maxn],dep[maxn],f[maxn],son[maxn],seg[maxn],sz[maxn],top[maxn];
int head[maxn],nxt[maxn << 1],to[maxn << 1],tot;
int add[maxn << 2],col[maxn];
void addedge(int x,int y)
{
    nxt[++tot] = head[x];
    head[x] = tot;
    to[tot] = y;
}
struct point{
	int pre,suf,sum;
	point(int a = 0,int b = 0,int c = 0)
	{
		pre = a,suf = b,sum = c;
	}
	point operator +(const point &b)const
	{
		int res = sum + b.sum;
		if(suf == b.pre)
		{
			--res;
		}
		return point(pre,b.suf,res);
	}
}p[maxn << 2];
void pushup(int rt)
{
	p[rt] = p[rt << 1] + p[rt << 1 | 1];
}
void pushdown(int rt)
{
	if(!add[rt])
	{
		return;
	}
	p[rt << 1].suf = p[rt << 1].pre = add[rt << 1] = add[rt];
	p[rt << 1 | 1].suf = p[rt << 1 | 1].pre = add[rt << 1 | 1] = add[rt];
	p[rt << 1].sum = p[rt << 1 | 1].sum = 1;
	add[rt] = 0;
}
void build(int rt,int l,int r)
{
	if(l == r)
	{
		p[rt].sum = 1;
		p[rt].suf = p[rt].pre = col[rev[l]];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1,l,mid);
	build(rt << 1 | 1,mid + 1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int left,int right,int c)
{
	if(left > r || right < l)
    {
        return;
    }
	if(left <= l && r <= right)
	{
		add[rt] = p[rt].pre = p[rt].suf = c;
		p[rt].sum = 1;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if(left <= mid)
	{
		update(rt << 1,l,mid,left,right,c);
	}
	if(mid < right)
	{
		update(rt << 1 | 1,mid + 1,r,left,right,c);
	}
	pushup(rt);
}
point query(int rt,int l,int r,int left,int right)
{
	if(left > r || right < l)
    {
        return point();
    }
	if(left <= l && r <= right)
	{
		return p[rt];
	}
	int mid = l + r >> 1;
	pushdown(rt);
	//because the color may contain 0,so can't
	//use res to plus two situations
	//order here is improtant
	if(right <= mid)
	{
		return query(rt << 1,l,mid,left,right);
	}
	if(mid < left)
	{
		return query(rt << 1 | 1,mid + 1,r,left,right);
	}
	return query(rt << 1,l,mid,left,right) + query(rt << 1 | 1,mid + 1,r,left,right);
}
void change(int u,int v,int c)
{
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
		{
			swap(u,v);
		}
		update(1,1,seg[0],seg[top[u]],seg[u],c);
		u = f[top[u]];
	}
	if(dep[u] > dep[v])
	{
		swap(u,v);
	}
	update(1,1,seg[0],seg[u],seg[v],c);
}
point query(int u,int v)
{
	point l = point(),r = point();
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
		{
			swap(u,v);
			swap(l,r);
		}
		//the order is improtant
		l = query(1,1,seg[0],seg[top[u]],seg[u]) + l;
		u = f[top[u]];
	}
	if(dep[u] > dep[v])
	{
		swap(u,v);
		swap(l,r);
	}
	//lhs has another order
	swap(l.pre,l.suf);
	return (l + query(1,1,seg[0],seg[u],seg[v]) + r);
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
	dfs2(son[u],tp);
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(!top[v])
		{
			dfs2(v,v);
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&col[i]);
	}
	for(int i = 1,u,v;i < n; ++i)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	char buf[10];
	while(m--)
	{
		int x,y;
		scanf("%s%d%d",buf,&x,&y);
		if(buf[0] == 'C')
		{
			int z;
			scanf("%d",&z);
			change(x,y,z);
		}
		else
		{
			printf("%d\n",query(x,y).sum);
		}
	}
	return 0;
}
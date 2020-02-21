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
const int maxn = 13e4;
const int inf = 0x3f3f3f3f;
//maxn:rev,sum,mx
int seg[maxn],rev[maxn],sz[maxn],son[maxn],top[maxn],dep[maxn];
int sum[maxn],num[maxn],f[maxn],mx[maxn];
int head[maxn],nxt[maxn],to[maxn],tot;//for the graph
struct Ans{
	int sum,mx;
	void clear()
	{
		sum = 0;
		mx = -inf;
	}
	Ans(){clear();};
}ans;
void add(int x,int y)
{
	nxt[++tot] = head[x];
	head[x] = tot;
	to[tot] = y;
}
void insert(int x,int y)
{
	add(x,y);
	add(y,x);
}
void pushup(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	mx[rt] = max(mx[rt << 1],mx[rt << 1 | 1]);
}
void query(int rt,int l,int r,int left,int right)
{
	if(left > r || right < l)
	{
		return;
	}
	if(left <= l && r <= right)
	{
		ans.sum += sum[rt];
		ans.mx = max(ans.mx,mx[rt]);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= left)
	{
		query(rt << 1,l,mid,left,right);
	}
	if(mid < right)
	{
		query(rt << 1 | 1,mid + 1,r,left,right);
	}
}
void update(int rt,int l,int r,int v,int k)
{
	if(k > r || k < l)
	{
		return;
	}
	if(l == r && l == k)
	{
		sum[rt] = v;
		mx[rt] = v;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= k)
	{
		update(rt << 1,l,mid,v,k);
	}
	if(mid < k)
	{
		update(rt << 1 | 1,mid + 1,r,v,k);
	}
	pushup(rt);
}
void build(int rt,int l,int r)
{
	if(l == r)
	{
		mx[rt] = sum[rt] = num[rev[l]];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1,l,mid);
	build(rt << 1 | 1,mid + 1,r);
	pushup(rt);
}
void dfs1(int u,int fa)
{
	sz[u] = 1;
	f[u] = fa;
	dep[u] = dep[fa] + 1;
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
void dfs2(int u,int fa)
{
	if(son[u])
	{
		seg[son[u]] = ++seg[0];//seg[0] for the size of seg
		top[son[u]] = top[u];
		rev[seg[0]] = son[u];//rev is the reverse of seg
		dfs2(son[u],u);
	}
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(!top[v])
		{
			seg[v] = ++seg[0];
			rev[seg[0]] = v;
			top[v] = v;
			dfs2(v,u);
		}
	}
}
void ask(int x,int y)
{
	int fx = top[x];
	int fy = top[y];
	while(fx != fy)
	{
		if(dep[fx] < dep[fy])
		{
			swap(x,y);
			swap(fx,fy);
		}
		query(1,1,seg[0],seg[fx],seg[x]);
		x = f[fx];
		fx = top[x];
	}
	if(dep[x] > dep[y])
	{
		swap(x,y);
	}
	query(1,1,seg[0],seg[x],seg[y]);
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d",&n);
	for(int i = 1;i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&num[i]);
	}
	dfs1(1,0);
	seg[0] = seg[1] = top[1] = rev[1] = 1;
	dfs2(1,0);
	build(1,1,seg[0]);
	scanf("%d",&m);
	char buf[10];
	for(int i = 1,u,v;i <= m; ++i)
	{
		scanf("%s",buf);
		scanf("%d%d",&u,&v);
		if(buf[0] == 'C')
		{
			update(1,1,seg[0],v,seg[u]);
		}
		else
		{
			ans.clear();
			ask(u,v);
			if(buf[1] == 'M')
			{
				printf("%d\n",ans.mx);
			}
			else
			{
				printf("%d\n",ans.sum);
			}
		}
	}
	return 0;
}
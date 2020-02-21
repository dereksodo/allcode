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
int read() {
    char ch = getchar();
    int sum = 0;
    while (!(ch >= '0' && ch <= '9')) ch = getchar();
    while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
    return sum;
}
const int maxn = 1e6 + 5;
int vis[maxn],dep[maxn],f[maxn];
int head[maxn],nxt[maxn],to[maxn];
int hd[maxn];
int ans[maxn * 3];
int tot,n,m,cnt;
struct node{
	int to,nxt,num;
}q[maxn * 3];
struct input{
	int a,b,c;
}inp[maxn];
void add(int u,int v)
{
	nxt[++tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}
void add2(int u,int v,int num)
{
	q[++cnt] = (node){v,hd[u],num};
	hd[u] = cnt;//not head
}
void dfs(int u,int fa)
{
	dep[u] = dep[fa] + 1;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v != fa)
		{
			dfs(v,u);
		}
	}
}
int ff(int x)
{
	return x == f[x] ? x : (f[x] = ff(f[x]));
}
void tarjan(int u,int fa)
{
	f[u] = u;
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(v != fa)
		{
			if(!vis[v])
			{
				tarjan(v,u);
				f[v] = u;
			}
		}
	}
	vis[u] = 1;
	for(int i = hd[u];i;i = q[i].nxt)
	{
		int v = q[i].to;
		if(vis[v])
		{
			ans[q[i].num] = ff(v);
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i < n; ++i)
	{
		int x,y;
		// scanf("%d%d",&x,&y);
		x = read(),y = read();
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	int id = 0;
	for(int i = 1;i <= m; ++i)
	{
		int a,b,c;
		// scanf("%d%d%d",&a,&b,&c);
		a = read(),b = read(),c = read();
		inp[i] = (input){a,b,c};
		add2(a,b,++id);
		add2(b,a,id);
		add2(a,c,++id);
		add2(c,a,id);
		add2(b,c,++id);
		add2(c,b,id);
	}
	tarjan(1,-1);
	id = 0;
	for(int i = 1;i <= m; ++i)
	{
		int l1 = ans[++id];
		int l2 = ans[++id];
		int l3 = ans[++id];
		int a = inp[i].a;
		int b = inp[i].b;
		int c = inp[i].c;
		int ans,src;
		if(l1 == l2 && l2 == l3)
		{
			src = l1;
			ans = dep[a] + dep[b] + dep[c] - 3 * dep[l1];
		}
		else if(l1 == l2)
		{
			src = l3;
			ans = dep[b] + dep[c] - 2 * dep[l3] + dep[a] - dep[l1] + dep[l3] - dep[l1];
		}
		else if(l2 == l3)
		{
			src = l1;
			ans = dep[a] + dep[b] - 2 * dep[l1] + dep[c] - dep[l3] + dep[l1] - dep[l3];
		}
		else
		{
			src = l2;
			ans = dep[a] + dep[c] - 2 * dep[l2] + dep[b] - dep[l1] + dep[l2] - dep[l1];
		}
		printf("%d %d\n",src,ans);
	}
	return 0;
}
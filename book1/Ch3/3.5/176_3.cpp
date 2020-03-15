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
const int inf = 0x3f3f3f3f;
const int maxn = 200010;
int head[maxn],nxt[maxn],to[maxn],tot;
int pd,dfn[maxn],low[maxn],sta[maxn],co[maxn],ins[maxn];
int sum[maxn],v[maxn],inx,num,n,a[maxn],b[maxn],in[maxn];
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void tarjan(int x)
{
	dfn[x] = low[x] = ++pd;
	sta[++inx] = x;
	ins[x] = 1;
	for(int i = head[x];i;i = nxt[i])
	{
		int v = to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[x] = min(low[x],low[v]);
		}
		else if(ins[v])
		{
			low[x] = min(low[x],dfn[v]);
		}
	}
	if(low[x] == dfn[x])
	{
		++num;
		while(sta[inx + 1] != x)
		{
			co[sta[inx]] = num;
			ins[sta[inx]] = 0;
			sum[num] = min(sum[num],v[sta[inx]]);
			--inx;
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,p,r;
	scanf("%d%d",&n,&p);
	memset(sum,inf,sizeof(sum));
	memset(v,inf,sizeof(v));
	for(int i = 1,x,y;i <= p; ++i)
	{
		scanf("%d%d",&x,&y);
		v[x] = y;
	}
	scanf("%d",&r);
	for(int i = 1;i <= r; ++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		add(a[i],b[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		if(!dfn[i] && v[i] != inf)
		{
			tarjan(i);
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		if(!dfn[i])
		{
			printf("NO\n%d\n",i);
			return 0;
		}
	}
	printf("YES\n");
	for(int i = 1;i <= n; ++i)
	{
		for(int j = head[i];j;j = nxt[j])
		{
			int v = to[j];
			if(co[i] != co[v])
			{
				in[co[v]]++;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= num; ++i)
	{
		if(!in[i])
		{
			ans += sum[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
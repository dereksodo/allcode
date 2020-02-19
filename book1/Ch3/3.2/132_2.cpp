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
const int inf = 0x3f3f3f3f;
int f[maxn],cnt,n,m,d[maxn],d2[maxn];
struct edge{
	int nxt,to,v;
}e[maxn << 1];
void add(int u,int v,int w)
{
	e[++cnt] = (edge){f[u],v,w};
	f[u] = cnt;
}
void spfa()
{
	priority_queue< pair<int,int> > q;
	memset(d,inf,sizeof(d));
	memset(d2,inf,sizeof(d2));
	d[1] = 0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int u = q.top().second;
		int val = q.top().first;
		q.pop();
		if(d2[u] < -val)
		{
			continue;
		}
		for(int i = f[u];i;i = e[i].nxt)
		{
			int v = e[i].to;
			int dis = e[i].v - val;
			if(d[v] > dis)
			{
				swap(d[v],dis);
				q.push(make_pair(-d[v],v));
			}
			if(d2[v] > dis && d[v] < dis)
			{
				d2[v] = dis;
				q.push(make_pair(-d2[v],v));
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1,u,v,w;i <= m; ++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	spfa();
	printf("%d\n",d2[n]);
	return 0;
}
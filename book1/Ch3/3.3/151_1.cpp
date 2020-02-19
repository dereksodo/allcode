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
const int maxn = 1e4 + 5;
const double eps = 1e-10;
struct edge{
	int to,nxt;
	double v;
}e[maxn];
int head[maxn],vis[maxn],n,m,tot;
double dis[maxn];
void add(int x,int y,double z)
{
	e[++tot] = (edge){y,head[x],z};
	head[x] = tot;
}
bool spfa(int u,double mid)
{
	vis[u] = 1;
	for(int i = head[u],v;i;i = e[i].nxt)
	{
		v = e[i].to;
		if(dis[v] > dis[u] + e[i].v - mid)
		{
			dis[v] = dis[u] + e[i].v - mid;
			if(vis[v] || spfa(v,mid))
			{
				return 1;
			}
		}
	}
	vis[u] = 0;
	return 0;
}
bool check(double mid)
{
	for(int i = 1;i <= n; ++i)
	{
		dis[i] = 0.0;
		vis[i] = 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(spfa(i,mid))
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		int x,y;
		double w;
		scanf("%d%d%lf",&x,&y,&w);
		add(x,y,w);
	}
	double l = -1e7,r = 1e7;
	while(r - l > eps)
	{
		double mid = (l + r) / 2.0;
		if(check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	printf("%.8lf\n",r);
	return 0;
}
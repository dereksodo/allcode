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
set<int> G[maxn];
int u[maxn << 2],v[maxn << 2],color[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d",&u[i],&v[i]);
		G[u[i]].insert(v[i]);
		G[v[i]].insert(u[i]);
	}
	int a = 1,b = -1,c = -1;
	for(int i = 1;i <= m; ++i)
	{
		if(u[i] == 1)
		{
			color[v[i]] = -1;
		}
	}
	for(int i = 1;i <= m; ++i)
	{
		if(color[u[i]] == -1 && color[v[i]] == -1)
		{
			b = u[i];
			c = v[i];
			break;
		}
	}
	if(b == -1)
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		bool fa = G[i].count(a),fb = G[i].count(b),fc = G[i].count(c);
		if(fa + fb + fc != 2)
		{
			printf("-1\n");
			return 0;
		}
		if(!fa)
		{
			color[i] = 1;
		}
		else if(!fb)
		{
			color[i] = 2;
		}
		else
		{
			color[i] = 3;
		}
	}
	for(int i = 1;i <= m; ++i)
	{
		if(color[u[i]] == color[v[i]])
		{
			printf("-1\n");
			return 0;
		}
	}
	int ta = count(color + 1,color + n + 1,1),tb = count(color + 1,color + n + 1,2),tc = count(color + 1,color + n + 1,3);
	if(m != (ta * tb + ta * tc + tb * tc))
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		printf("%d ",color[i]);
	}
	printf("\n");
	return 0;
}
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
struct edge{
	int x,y;
}e[150];
const int maxn = 1 << 20;
int ok[maxn],f[maxn];
int vis[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	n = 0;
	for(int i = 1;i <= m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(!vis[x])
		{
			vis[x] = ++n;
		}
		if(!vis[y])
		{
			vis[y] = ++n;
		}
		e[i].x = vis[x],e[i].y = vis[y];
	}
	for(int S = 1;S < (1 << n); ++S)
	{
		ok[S] = 1;
		for(int i = 1;i <= m; ++i)
		{
			if(((1 << (e[i].x - 1)) & S) && ((1 << (e[i].y - 1)) & S))
			{
				ok[S] = 0;
				break;
			}
		}
	}
	f[0] = 0;
	for(int S = 1;S < (1 << n); ++S)
	{
		f[S] = inf;
		for(int T = S;T;T = (T - 1) & S)
		{
			if(ok[T] && f[S ^ T] != inf)
			{
				f[S] = min(f[S],f[S ^ T] + 1);
			}
		}
	}
	printf("%d\n",f[(1 << n) - 1] - 1);
	return 0;
}
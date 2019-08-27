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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
double a[25];
int n,m;
double pe;
void dfs(int x,int d,double now)
{
	if(d > m)
	{
		return;
	}
	if(x == n + 1)
	{
		if(d == m)
		{
			pe += now;
		}
		return;
	}
	dfs(x + 1,d + 1,now * a[x]);
	dfs(x + 1,d,now * (1 - a[x]));
}
double ans;
void dfs2(int x,int d,int i,double now)
{
	if(d > m)
	{
		return;
	}
	if(x == n + 1)
	{
		if(d == m)
		{
			ans += now;
		}
		return;
	}
	dfs2(x + 1,d + 1,i,now * a[x]);
	if(x == i)
	{
		return;
	}
	dfs2(x + 1,d,i,now * (1 - a[x]));
}
int main(int argc, char const *argv[])
{
	int cnt = 0;
	while(cin>>n>>m && (n + m))
	{
		for(int i = 1;i <= n; ++i)
		{
			scanf("%lf",&a[i]);
		}
		printf("Case %d:\n",++cnt);
		pe = 0;
		dfs(1,0,1);
		for(int i = 1;i <= n; ++i)
		{
			ans = 0.0;
			dfs2(1,0,i,1);
			printf("%.6lf\n",ans / pe);
		}
	}
	return 0;
}
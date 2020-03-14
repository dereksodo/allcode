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
const int maxn = 3005;
int vis[maxn],ans[maxn];
int n,t;
int dfs(int x,int k)
{
	if(vis[x])
	{
		return 0;
	}
	if(k == t)
	{
		return 1;
	}
	vis[x] = 1;
	ans[k + n - 1] = x & 1;
	int y = ((x << 1) & (t - 1));
	if(dfs(y,k + 1))
	{
		return 1;
	}
	if(dfs(y | 1,k + 1))
	{
		return 1;
	}
	vis[x] = 0;
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	printf("%d ",(1 << n));
	t = 1 << n;
	dfs(0,1);
	for(int i = 1;i <= t; ++i)
	{
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
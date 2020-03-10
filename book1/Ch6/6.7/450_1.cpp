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
const int maxn = 1005;
int n,m;
int a[maxn],b[maxn];
int sg[maxn];
int getsg(int u)
{
	if(sg[u] != -1)
	{
		return sg[u];
	}
	int vis[maxn];//can't be defined outside
	//because later dfs will clear the data
	memset(vis,0x00,sizeof(vis));
	for(int i = 0;i < m; ++i)
	{
		if(u >= b[i])
		{
			vis[getsg(u - b[i])] = 1;
		}
	}
	for(int i = 0;; ++i)
	{
		if(!vis[i])
		{
			// printf("%d->%d\n",u,i);
			return sg[u] = i;
		}
	}
}
int main(int argc, char const *argv[])
{
	memset(sg,-1,sizeof(sg));
	scanf("%d",&n);
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i = 0;i < m; ++i)
	{
		scanf("%d",&b[i]);
	}
	int ans = 0;
	for(int i = 0;i < n; ++i)
	{
		ans ^= getsg(a[i]);
	}
	if(ans == 0)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if(b[j] <= a[i] && ((ans ^ sg[a[i]]) == sg[a[i] - b[j]]))
			{
				printf("%d %d\n",i + 1,b[j]);
				return 0;
			}
		}
	}
	return 0;
}
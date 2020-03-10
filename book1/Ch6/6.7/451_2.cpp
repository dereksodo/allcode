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
const int maxn = 2005;
int sg[maxn],a[maxn];
int ans,n;
void dfs(int x,int pos,int now)
{
	if(x == n + 1)
	{
		if(!now && pos > 0)
		{
			ans = 1;
		}
		return;
	}
	dfs(x + 1,pos,now);
	dfs(x + 1,pos + 1,now ^ a[x]);
}
int main(int argc, char const *argv[])
{
	for(int i = 1;i <= 10; ++i)
	{
		memset(sg,-1,sizeof(sg));
		ans = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,0,0);
		if(ans)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
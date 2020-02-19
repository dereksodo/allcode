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
int n,m;
int c[maxn],dp[maxn];
int mx[maxn];
vector<int> G[maxn];
void dfs(int pos,int m,int pre)
{
	int f = 1;
	m = min(m,c[pos]);
	if(mx[pos] > m)
	{
		mx[pos] = m;
		f = 0;
	}
	int k = max(dp[pre],c[pos] - m);
	if(dp[pos] < k)
	{
		dp[pos] = k;
		f = 0;
	}
	if(f)
	{
		return;
	}
	for(int i = 0;i < G[pos].size(); ++i)
	{
		dfs(G[pos][i],m,pos);
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&c[i]);
	}
	memset(mx,0x3f3f3f3f,sizeof(mx));
	for(int i = 1;i <= m; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back(y);
		if(z == 2)
		{
			G[y].push_back(x);
		}
	}
	dfs(1,0x3f3f3f3f,0);
	printf("%d\n",dp[n]);
	return 0;
}
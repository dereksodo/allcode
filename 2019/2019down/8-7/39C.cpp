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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 2005;
int n;
int cnt,low[maxn],high[maxn];
int id[maxn << 1][maxn << 1];
int dp[maxn << 1][maxn << 1];
map<int,int> mp;
vector<int> v[maxn << 1];
int dfs(int l,int r)
{
	if(dp[l][r] != -1)
	{
		return dp[l][r];
	}
	if(l == r)
	{
		return dp[l][r] = 0;
	}
	int cur = 0;
	if(id[l][r] != -1)
	{
		cur = 1;
	}
	int ans = cur + dfs(l,r - 1);
	for(int i = 0;i < v[r].size(); ++i)
	{
		int now = low[v[r][i]];
		if(now <= l)
		{
			continue;
		}
		int x = cur + dfs(l,now) + dfs(now,r);
		ans = max(ans,x);
	}
	return dp[l][r] = ans;
}
vector<int> ansv;
void path(int l,int r)
{
	if(l == r)
	{
		return;
	}
	int cur = 0;
	if(id[l][r] != -1)
	{
		cur = 1;
		ansv.push_back(id[l][r]);
	}
	if(dp[l][r] == cur + dp[l][r - 1])
	{
		path(l,r - 1);
		return;
	}
	for(int i = 0;i < v[r].size(); ++i)
	{
		int now = low[v[r][i]];
		if(now <= l)
		{
			continue;
		}
		if(cur + dp[l][now] + dp[now][r] == dp[l][r])
		{
			path(l,now);
			path(now,r);
			return;
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		low[i] = x - y;
		high[i] = x + y;
		mp[low[i]] = mp[high[i]] = 0;
	}
	for(map<int,int>::iterator iter = mp.begin();iter != mp.end(); ++iter)
	{
		iter->second = cnt++;
	}
	for(int i = 0;i < n; ++i)
	{
		low[i] = mp[low[i]];
		high[i] = mp[high[i]];
		v[high[i]].push_back(i);
	}
	for(int i = 0;i < cnt; ++i)
	{
		for(int j = 0;j < cnt; ++j)
		{
			id[i][j] = -1;
		}
	}
	for(int i = 0;i < cnt; ++i)
	{
		id[low[i]][high[i]] = i;
	}
	int ans = dfs(0,cnt - 1);
	printf("%d\n",ans);
	path(0,cnt - 1);
	for(int i = ansv.size();i >= 0; --i)
	{
		printf("%d ",ansv[i] + 1);
	}
	printf("\n");
	return 0;
}
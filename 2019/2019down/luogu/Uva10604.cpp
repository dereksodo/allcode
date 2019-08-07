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
const int maxn = 15;
int color[maxn][maxn],heat[maxn][maxn];
int n,k;
int dp[maxn][maxn][maxn][maxn][maxn][maxn],cnt[maxn];
int dfs(int num)
{
	if(num == k - 1)
	{
		return 0;
	}
	if(dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]] != -1)
	{
		return dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]];
	}
	int ret = 0x3f3f3f3f;
	for(int i = 1;i <= 6; ++i)
	{
		if(!cnt[i])
		{
			continue;
		}
		cnt[i]--;
		for(int j = 1;j <= 6; ++j)
		{
			if(cnt[j])
			{
				int newcolor = color[i][j];
				cnt[j]--;
				cnt[newcolor]++;
				ret = min(dfs(num + 1) + heat[i][j],ret);
				cnt[j]++;
				cnt[newcolor]--;
			}
		}
		cnt[i]++;
	}
	return dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]] = ret;
}
char s[10000];
int x;
int main(int argc, char const *argv[])
{
	// freopen("test.in","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>n;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				scanf("%d%d",&color[i][j],&heat[i][j]);
			}
		}
		cin>>k;
		memset(cnt,0x00,sizeof(cnt));
		for(int i = 1;i <= k; ++i)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		printf("%d\n",dfs(0));
		scanf("%s",s);
		if(T == 0)
		{
			break;
		}
		scanf("\n");
	}
	return 0;
}
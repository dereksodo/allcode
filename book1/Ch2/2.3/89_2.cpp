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
const int maxn = 1e6 + 5;
const int maxm = 30;
int ch[maxn][maxm],vis[maxn],dp[maxn];
char s[maxn];
int tot,n,m;
void init()
{
	tot = 1;
}
void insert()
{
	scanf("%s",s);
	int l = strlen(s);
	int u = 1;
	for(int i = 0;i < l; ++i)
	{
		int c = s[i] - 'a';
		if(!ch[u][c])
		{
			ch[u][c] = ++tot;
		}
		u = ch[u][c];
	}
	vis[u] = 1;
}
int search()
{
	scanf("%s",s + 1);
	int l = strlen(s + 1);
	int ans = 0;
	memset(dp,0x00,sizeof(dp));
	dp[0] = 1;
	for(int i = 0;i <= l; ++i)
	{
		if(!dp[i])
		{
			continue;
		}
		ans = i;
		for(int j = i + 1,u = 1;j <= l; ++j)
		{
			int c = s[j] - 'a';
			u = ch[u][c];
			if(!u)
			{
				break;
			}
			if(vis[u])
			{
				dp[j] = 1;
			}
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	init();
	for(int i = 1;i <= n; ++i)
	{
		insert();
	}
	for(int i = 1;i <= m; ++i)
	{
		printf("%d\n",search());
	}
	return 0;
}
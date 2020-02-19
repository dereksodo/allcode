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
const int maxn = 60005;
int dp[105][maxn];
char s[105];
const int mod = 1e4 + 7;
int vis[maxn],ch[maxn][30],tot;
int que[maxn],h,t,nxt[maxn];
void insert()
{
	int u = 0,n = strlen(s);
	for(int i = 0;i < n; ++i)
	{
		int c = s[i] - 'A';
		if(!ch[u][c])
		{
			ch[u][c] = ++tot;
		}
		u = ch[u][c];
	}
	vis[u] = 1;
}
void build()
{
	for(int i = 0;i < 26; ++i)
	{
		if(ch[0][i])
		{
			que[++t] = ch[0][i];
		}
	}
	while(h < t)
	{
		int u = que[++h];
		for(int i = 0;i < 26; ++i)
		{
			int &v = ch[u][i];
			if(v)
			{
				vis[v] |= vis[ch[nxt[u]][i]];
				nxt[v] = ch[nxt[u]][i];
				que[++t] = v;
			}
			else
			{
				v = ch[nxt[u]][i];
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%s",s);
		insert();
	}
	build();
	dp[0][0] = 1;
	for(int i = 1;i <= m; ++i)
	{
		for(int j = 0;j <= tot; ++j)
		{
			for(int k = 0;k < 26; ++k)
			{
				if(!vis[ch[j][k]])
				{
					(dp[i][ch[j][k]] += dp[i - 1][j]) %= mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= tot; ++i)
	{
		(ans += dp[m][i]) %= mod;
	}
	int sum = 1;
	for(int i = 1;i <= m; ++i)
	{
		(sum *= 26) %= mod;
	}
	printf("%d\n",(sum - ans + mod) % mod);
	return 0;
}
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
const int maxn = 600005;
int n,ch[maxn][30],fa[maxn],sz[maxn],vis[maxn];
vector<int> a[maxn];
ll ans;
char s[maxn];
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	int tot = 1;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%s",s + 1);
		int l = strlen(s + 1);
		int u = 1;
		for(int j = l;j; --j)
		{
			int c = s[j] - 'a';
			if(!ch[u][c])
			{
				ch[u][c] = ++tot,fa[tot] = u;
			}
			u = ch[u][c];
		}
		vis[u] = 1;
	}
	vis[1] = 1;
	for(int i = tot,u;i > 0; --i)
	{
		if(vis[i])
		{
			sort(a[i].begin(),a[i].end());
			for(int k = 0,t = 1;k < a[i].size(); ++k)
			{
				ans += t,t += a[i][k];
			}
			for(u = fa[i],++sz[i];u && !vis[u]; u = fa[u]);
			sz[u] += sz[i];
			a[u].push_back(sz[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
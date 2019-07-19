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
const int maxn = 3e5 + 5;
const int inf = 1e9 + 5;
vector<int> G[maxn];
int n,cnt;
int dc[maxn],m[maxn];
void dfs(int u)
{
	dc[u] = 0;
	if(G[u].empty())
	{
		cnt++;
		return;
	}
	if(m[u] == 1)
	{
		dc[u] = inf;
		for(int v : G[u])
		{
			dfs(v);
			dc[u] = min(dc[u],dc[v]);
		}
	}
	else
	{
		dc[u] = G[u].size() - 1;
		for(int v : G[u])
		{
			dfs(v);
			dc[u] += dc[v];
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",m + i);
	}
	for(int i = 2;i <= n; ++i)
	{
		int p;
		scanf("%d",&p);
		G[p].push_back(i);
	}
	dfs(1);
	cout<<cnt - dc[1]<<endl;
	return 0;
}
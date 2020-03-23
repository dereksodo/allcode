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
vector<int> G[maxn];
int ans[maxn];
pair<int,int> p[maxn];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i < n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(i);
		G[v].push_back(i);
		ans[i] = -1;
	}
	pair<int,int> mx = make_pair(0,0);
	for(int i = 1;i <= n; ++i)
	{
		mx = max(mx,make_pair(int(G[i].size()),i));
	}
	int cnt = 0;
	for(int i = 0;i < G[mx.second].size(); ++i)
	{
		ans[G[mx.second][i]] = cnt++;
	}
	for(int i = 1;i < n; ++i)
	{
		if(ans[i] == -1)
		{
			ans[i] = cnt++;
		}
		printf("%d\n",ans[i]);
	}
	return 0;
}
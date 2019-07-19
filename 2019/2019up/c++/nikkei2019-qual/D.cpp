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
const int maxn = 1e5 + 5;
vector<ll> G[maxn];
ll indegree[maxn],ans[maxn];
ll n,m;
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 0;i < n - 1 + m; ++i)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		G[x].push_back(y);
		indegree[y]++;
	}
	queue<ll> q;
	for(int i = 1;i <= n; ++i)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		ll now = q.front();
		q.pop();
		for(ll i : G[now])
		{
			indegree[i]--;
			if(indegree[i] == 0)
			{
				ans[i] = now;
				q.push(i);
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
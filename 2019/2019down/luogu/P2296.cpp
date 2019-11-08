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
const int maxn = 10005;
vector<int> v1[maxn],v2[maxn];
int ok[maxn],ok2[maxn],dis[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
		v2[y].push_back(x);
	}
	int s,t;
	cin>>s>>t;
	ok[t] = 1;
	queue<int> q;
	q.push(t);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(int i = 0;i < v2[now].size(); ++i)
		{
			int u = v2[now][i];
			if(!ok[u])
			{
				q.push(u);
				ok[u] = 1;
			}
		}
	}
	if(!ok[s])
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(ok[i])
		{
			ok2[i] = 1;
			for(int j = 0;j < v1[i].size(); ++j)
			{
				int u = v1[i][j];
				if(!ok[u])
				{
					ok2[i] = 0;
					break;
				}
			}
		}
	}
	if(!ok2[s])
	{
		printf("-1\n");
		return 0;
	}
	dis[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		if(now == t)
		{
			printf("%d\n",dis[t] - 1);
			return 0;
		}
		for(int i = 0;i < v1[now].size(); ++i)
		{
			int u = v1[now][i];
			if(ok2[u] && !dis[u])
			{
				dis[u] = dis[now] + 1;
				q.push(u);
			}
		}
	}
	printf("-1\n");
	return 0;
}
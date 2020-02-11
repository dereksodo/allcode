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
const int maxn = 55;
int x[maxn],y[maxn];
int dis[maxn],vis[maxn];
int cnt(int a,int b)
{
	return (abs(x[a] - x[b]) + abs(y[a] - y[b]) + 1) / 2;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	memset(dis,0x7f,sizeof(dis));
	dis[1] = 0;
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		int now = 0;
		for(int j = 1;j <= n; ++j)
		{
			if(!vis[j] && dis[j] < dis[now])
			{
				now = j;
			}
		}
		vis[now] = 1;
		ans = max(ans,dis[now]);
		for(int j = 1;j <= n; ++j)
		{
			if(!vis[j] && cnt(now,j) < dis[j])
			{
				dis[j] = cnt(now,j);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
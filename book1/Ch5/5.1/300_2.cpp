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
const int maxn = 350;
int split[maxn][maxn],dp[maxn][maxn],a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for(int len = 2;len <= n; ++len)
	{
		for(int s = 1;s + len - 1 <= n; ++s)
		{
			int t = s + len - 1;
			for(int k = s;k < t; ++k)
			{
				int now = dp[s][k] + dp[k + 1][t] + (a[s] + a[t]) * a[k];
				if(dp[s][t] < now)
				{
					dp[s][t] = now;
					split[s][t] = k;
				}
			}
		}
	}
	printf("%d\n",dp[1][n]);
	queue< pair<int,int> > q;
	q.push(make_pair(1,n));
	while(!q.empty())
	{
		pair<int,int> cur = q.front();
		q.pop();
		int sp = split[cur.first][cur.second];
		printf("%d ",sp);
		if(split[cur.first][sp])
		{
			q.push(make_pair(cur.first,sp));
		}
		if(split[sp + 1][cur.second])
		{
			q.push(make_pair(sp + 1,cur.second));
		}
	}
	return 0;
}
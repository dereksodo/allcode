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
const ll maxn = 150005;
ll dp[2][maxn];
ll a[maxn],b[maxn],ti[maxn];
ll deq[maxn];
int main(int argc, char const *argv[])
{
	ll n,m,d;
	cin>>n>>m>>d;
	ti[0] = 1;
	for(ll i = 1;i <= m; ++i)
	{
		scanf("%lld%lld%lld",&a[i],&b[i],&ti[i]);
	}
	memset(dp,0x00,sizeof(dp));
	int e = 0;
	for(int i = 1;i <= m; ++i)
	{
		e = 1 - e;
		memset(dp[e],0x00,sizeof(dp[e]));
		deque< pair<int,int> > deq;
		int t = ti[i] - ti[i - 1];
		for(int j = 1;j <= n; ++j)
		{
			while(!deq.empty())
			{
				pair<int,int> cur = deq.front();
				if(cur.second + t * d < j - t * d)
				{
					deq.pop_front();
				}
				else
				{
					break;
				}
			}
			pair<int,int> cur = make_pair(dp[1 - e][j],j);
			while(!deq.empty())
			{
				pair<int,int> cur2 = deq.back();
				if(cur2.first >= cur.first)
				{
					deq.pop_back();
				}
				else
				{
					deq.push_back(cur);
					break;
				}
			}
			if(deq.empty())
			{
				deq.push_back(cur);
			}
			if(j - t * d >= 1)
			{
				dp[e][j - t * d] = deq.front().first + abs(a[i] - (j - t * d));
			}
		}
		for(int j = max(1ll,n - t * d + 1);j <= n; ++j)
		{
			while(!deq.empty())
			{
				pair<int,int> cur = deq.front();
				if(cur.second + t * d < j)
				{
					deq.pop_front();
				}
				else
				{
					break;
				}
			}
			dp[e][j] = deq.front().first + abs(a[i] - j);
		}
	}
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(int j = 1;j <= n; ++j)
	{
		ans = min(ans,dp[e][j]);
	}
	ans *= -1;
	for(int i = 1;i <= m; ++i)
	{
		ans += b[i];
	}
	printf("%lld\n",ans);
	return 0;
}
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
const int maxn = 55;
map< pair<ll,ll>,ll > mp;
ll x[maxn],y[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	mp.clear();
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		mp[{x[i],y[i]}] = 1;
	}
	int ans = 0;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			if(i == j)
			{
				continue;
			}
			pair<ll,ll> add = {x[i] - x[j],y[i] - y[j]};
			int cnt = 0;
			for(int i = 0;i < n; ++i)
			{
				pair<ll,ll> now = {x[i] + add.first,y[i] + add.second};
				if(mp[now] == 1)
				{
					cnt++;
				}
			}
			ans = max(ans,cnt);
		}
	}
	printf("%lld\n",n - ans);
	return 0;
}
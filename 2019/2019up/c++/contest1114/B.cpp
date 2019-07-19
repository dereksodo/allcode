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
typedef pair<ll,ll> pll;
int main(int argc, char const *argv[])
{
	ll n,m,k;
	cin>>n>>m>>k;
	priority_queue<pll> pq;
	for(ll i = 0;i < n; ++i)
	{
		ll x;
		scanf("%lld",&x);
		pq.push({x,i + 1});
	}
	ll last = m * k,ans = 0;
	priority_queue<ll,vector<ll>,greater<ll>> v;
	while(last--)
	{
		ans += pq.top().first;
		v.push(pq.top().second);
		pq.pop();
	}
	cout<<ans<<endl;
	ll now = 0;
	vector<ll> ans2;
	while(v.size() >= 1)
	{
		now++;
		if(now == m)
		{
			now = 0;
			ans2.push_back(v.top());
		}
		v.pop();
	}
	for(ll i = 0;i < ans2.size() - 1; ++i)
	{
		printf("%lld ",ans2[i]);
	}
	printf("\n");
	return 0;
}
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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
ll n,k,A,B;
const ll maxn = 1e5 + 5;
// ll a[maxn];
// ll query(ll left,ll right)
// {
// 	ll pos1 = lower_bound(a,a + k,left) - a;
// 	ll pos2 = lower_bound(a,a + k,right) - a;
// 	if(pos2 > k - 1)
// 	{
// 		pos2 = k - 1;
// 	}
// 	if(a[pos2] > right)
// 	{
// 		pos2--;
// 	}
// 	debug("query(%lld,%lld) = %lld\n",left,right,pos2 - pos1 + 1);
// 	return pos2 - pos1 + 1;
// }
// ll solve(ll left,ll right)
// {
// 	ll siz = right - left + 1;
// 	if(siz >= 2)
// 	{
// 		ll mid = (left + right) >> 1;
// 		ll first = solve(left,mid) + solve(mid + 1,right);
// 		ll now = query(left,right),ans = 0;
// 		if(now == 0)
// 		{
// 			ans = A;
// 		}
// 		else
// 		{
// 			ans = B * now * siz;
// 		}
// 		debug("%lld -> %lld, = %lld\n",left,right,min(first,ans));
// 		return min(first,ans);
// 	}
// 	else
// 	{
// 		ll now = query(left,right),ans = 0;
// 		if(now == 0)
// 		{
// 			ans = A;
// 		}
// 		else
// 		{
// 			ans = B * now * siz;
// 		}
// 		debug("%lld -> %lld, = %lld\n",left,right,ans);
// 		return ans;
// 	}
// }
ll solve2(ll minx,ll maxx,vector<ll> v)
{
	if(v.size() == 0)
	{
		return A;
	}
	if(minx == maxx)
	{
		return ll(v.size()) * B;
	}
	ll mid = minx + maxx >> 1;
	vector<ll> a1,a2;
	for(ll u : v)
	{
		if(u <= mid)
		{
			a1.push_back(u);
		}
		else
		{
			a2.push_back(u);
		}
	}
	return min(B * ll(v.size()) * (maxx - minx + 1),solve2(minx,mid,a1) + solve2(mid + 1,maxx,a2));
}
vector<ll> a;
int main(int argc, char const *argv[])
{
	cin>>n>>k>>A>>B;
	a.resize(k);
	for(ll i = 0;i < k; ++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	printf("%lld\n",solve2(1,(1 << n),a));
	return 0;
}
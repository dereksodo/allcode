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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug prllf
#else
	#define debug(...)
#endif
const ll maxn = 200005;
pair<ll,ll> a[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	vector<ll> s;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld%lld",&a[i].first,&a[i].second);
	}
	sort(a + 1,a + n + 1);
	ll ans = 0;
	for(ll i = 1,j;i <= n; i = j)
	{
		j = i;
		for(;a[i].first == a[j].first && j <= n; ++j);
		ans += (j - i) * (j - i - 1) / 2;
	}
	for(ll i = 1;i <= n; ++i)
	{
		swap(a[i].first,a[i].second);
	}
	sort(a + 1,a + n + 1);
	for(ll i = 1,j;i <= n; i = j)
	{
		j = i;
		for(;a[i].first == a[j].first && j <= n; ++j);
		ans += (j - i) * (j - i - 1) / 2;
	}
	for(ll i = 1,j;i <= n; i = j)
	{
		j = i;
		for(;(a[i].first == a[j].first) && (a[i].second == a[j].second) && j <= n; ++j);
		ans -= (j - i) * (j - i - 1) / 2;
	}
	cout<<ans<<endl;
	return 0;
}
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
const ll maxn = 3e5 + 105;
const ll mod = 998244353;
map<ll,ll> mp1,mp2;
map< pair<ll,ll>,ll > mp3;
pair<ll,ll> a[maxn];
ll ca[maxn];
int main(int argc, char const *argv[])
{
	ca[0] = 1;
	ll n;
	cin>>n;
	a[0].second = -1;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld%lld",&a[i].first,&a[i].second);
		ca[i] = (ca[i - 1] * i) % mod;
	}
	ll now = ca[n];
	ll r1 = 1,r2 = 1,r3 = 1;
	for(ll i = 1;i <= n; ++i)
	{
		mp1[a[i].first]++;
	}
	for(map<ll,ll>::iterator iter = mp1.begin();iter != mp1.end(); ++iter)
	{
		r1 = (r1 * ca[iter->second]) % mod;
	}
	for(ll i = 1;i <= n; ++i)
	{
		mp2[a[i].second]++;
	}
	for(map<ll,ll>::iterator iter = mp2.begin();iter != mp2.end(); ++iter)
	{
		r2 = (r2 * ca[iter->second]) % mod;
	}
	sort(a + 1,a + n + 1);
	for(ll i = 1;i <= n; ++i)
	{
		mp3[a[i]]++;
		if(a[i].second < a[i - 1].second)
		{
			r3 = 0;
		}
	}
	for(map< pair<ll,ll>,ll >::iterator iter = mp3.begin();iter != mp3.end(); ++iter)
	{
		r3 = (r3 * ca[iter->second]) % mod;
	}
	printf("%lld\n",(now - r1 - r2 + r3 + mod * 100) % mod);
	return 0;
}
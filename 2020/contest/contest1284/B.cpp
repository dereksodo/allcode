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
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
ll len[maxn];
struct type{
	ll flag;
	ll maxx,minn;
	type(){flag = 0,maxx = -1,minn = inf;};
}t[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll ap = 0;
	vector<ll> s;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&len[i]);
		for(ll j = 1;j <= len[i]; ++j)
		{
			ll x;
			scanf("%lld",&x);
			if(t[i].minn < x)
			{
				t[i].flag = 1;
			}
			t[i].minn = min(t[i].minn,x);
			t[i].maxx = max(t[i].maxx,x);
		}
		if(t[i].flag == 0)
		{
			s.push_back(t[i].maxx);
		}
		else
		{
			ap++;
		}
	}
	ll ans = ap * (2 * n - ap);
	// printf("ans = %lld\n",ans);
	sort(s.begin(),s.end());
	ll sz = (ll)s.size();
	for(ll i = 1;i <= n; ++i)
	{
		if(t[i].flag == 1)
		{
			continue;
		}
		ll pos = upper_bound(s.begin(),s.end(),t[i].minn) - s.begin();
		// printf("minn = %d,s[%d] = %d\n",t[i].minn,pos,s[pos]);
		ans += sz - pos;
		// printf("%lld, ",now);
	}
	printf("%lld\n",ans);
	return 0;
}
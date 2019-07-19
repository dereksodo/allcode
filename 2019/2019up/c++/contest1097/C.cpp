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
map< pair<ll,ll>,ll > mp,mp2;
set< pair<ll,ll> > se;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	string s;
	for(ll i = 0ll;i < n; ++i)
	{
		cin>>s;
		ll leftcnt = 0ll,rightcnt = 0ll,flag = 2ll;
		ll leftcnt2 = 0ll,rightcnt2 = 0ll;
		for(ll p = 0;p < ll(s.size()); ++p)
		{
			char j = s[p];
			leftcnt += j == ')';
			rightcnt += j == '(';
			if(rightcnt < leftcnt)
			{
				flag = min(flag,1ll);
			}
		}
		for(ll p = ll(s.size()) - 1;p >= 0; --p)
		{
			char j = s[p];
			leftcnt2 += j == ')';
			rightcnt2 += j == '(';
			if(rightcnt2 > leftcnt2)
			{
				if(flag == 1)
				{
					flag = 0;
				}
				else if(flag == 0)
				{
					flag = 0;
				}
			}
		}
		if(flag <= 0ll && ll(s.size()) > 1)
		{
			continue;
		}
		ll now = min(leftcnt,rightcnt);
		leftcnt -= now;
		rightcnt -= now;
		debug("\n%s -> left = %lld,right = %lld\n",s.c_str(),leftcnt,rightcnt);
		mp[{leftcnt,rightcnt}]++;
		mp2[{leftcnt,rightcnt}] = 0ll;
		mp2[{rightcnt,leftcnt}] = 0ll;
		se.insert({leftcnt,rightcnt});
	}
	ll ans = 0ll;
	for(auto iter = se.begin();iter != se.end(); ++iter)
	{
		debug("%lld %lld\n",iter->first,iter->second);
		if(mp2[{iter->first,iter->second}])
		{
			continue;
		}
		mp2[{iter->second,iter->first}] = 1ll;
		mp2[{iter->first,iter->second}] = 1ll;
		if(iter->second == 0ll && iter->first == 0ll)
		{
			ans += (mp[{0ll,0ll}] / 2ll);
		}
		else
		{
			ans += min(mp[{iter->first,iter->second}],mp[{iter->second,iter->first}]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
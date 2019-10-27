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
const int maxn = 2e5 + 5;
ll aa[maxn];
vector<ll> v;
ll x,b,y,a,n;
ll check(ll mid)
{
	int j = n;
	for(int i = 1;i <= mid; ++i)
	{
		ll now = 0;
		if(i % a == 0)
		{
			now += x;
		}
		if(i % b == 0)
		{
			now += y;
		}
		v.push_back(now);
	}
	sort(v.begin(),v.end());
	ll ret = 0;
	while(!v.empty() && j > 0)
	{
		ret += v.back() * aa[j--];
		v.pop_back();
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	ll q;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%lld", &aa[i]);
			aa[i] /= 100;
		}
		sort(aa + 1,aa + n + 1);
		scanf("%lld%lld%lld%lld",&x,&a,&y,&b);
		ll k;
		cin>>k;
		ll left = 1,right = n + 1,ans = -1;
		while(left < right)
		{
			ll mid = left + right >> 1;
			// printf("mid = %d\n",mid);
			if(check(mid) >= k)
			{
				right = mid;
				ans = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
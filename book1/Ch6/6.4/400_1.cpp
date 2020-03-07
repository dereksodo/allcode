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
const int mod = 9901;
pair<int,int> cnt[25];
void div(int n)
{
	cnt[0].first = 0;
	for(int i = 2;i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			cnt[++cnt[0].first] = make_pair(i,0);
			while(n % i == 0)
			{
				n /= i;
				cnt[cnt[0].first].second++;
			}
		}
	}
	if(n > 1)
	{
		cnt[++cnt[0].first] = make_pair(n,1);
	}
}
ll mypow(ll a,ll b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a % mod;
	}
	ll res = mypow(a,b / 2);
	return res * res % mod * (b & 1 ? a : 1) % mod;
}
int main(int argc, char const *argv[])
{
	ll a,b;
	cin>>a>>b;
	div(a);
	ll ans = 1;
	for(int i = 1;i <= cnt[0].first; ++i)
	{
		if((cnt[i].first - 1) % mod == 0)
		{
			ans = (b * cnt[i].second + 1) % mod * ans % mod;
		}
		ll x = mypow(cnt[i].first,b * cnt[i].second + 1) - 1;
		if(x < 0)
		{
			x += mod;
		}
		ll y = mypow(cnt[i].first - 1,mod - 2);
		ans = ans * x % mod * y % mod;
	}
	cout<<ans<<endl;
	return 0;
}
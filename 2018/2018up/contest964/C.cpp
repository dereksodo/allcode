#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int mod = 1000000009;
typedef long long ll;
int n,k;
string s;
ll pow_log(ll b,int e)
{
	if(e == 0)
	{
		return 1;
	}
	ll ret = pow_log(b,e / 2);
	ret = (ret * ret) % mod;
	if(e % 2)
	{
		ret = (ret * b) % mod;
	}
	return ret;
}
ll go(ll a,ll b)
{
	ll ans = 0;
	for(int i = 0;i < k; ++i)
	{
		ll tmp = (pow_log(a,n - i) * pow_log(b,i)) % mod;
		if(s[i] == '+')
		{
			ans += tmp;
		}
		else
		{
			ans -= tmp;
		}
		ans = (ans + mod) % mod;
	}
	ll p1 = pow_log(b * pow_log(a,mod - 2) % mod,n + 1),p2 = pow_log(b * (pow_log(a,mod - 2)) % mod,k);
	if (p2 == 1)
	{
		return (ans * ((n + 1) / k)) % mod;
	}
	return (((ans * (1 + mod - p1)) % mod) * pow_log(1 + mod - p2,mod - 2)) % mod;
}
int main(int argc, char const *argv[])
{
	ll a,b;
	cin>>n>>a>>b>>k>>s;
	printf("%lld\n",go(a,b));
	return 0;
}
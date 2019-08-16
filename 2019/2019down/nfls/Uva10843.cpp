#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll mod = 2000000011;
int main(int argc, char const *argv[])
{
	ll T;
	cin>>T;
	for(int kase = 1;kase <= T; ++kase)
	{
		ll n;
		cin>>n;
		ll res = 1;
		for(ll i = 1;i < n - 1; ++i)
		{
			res *= n;
			res %= mod;
		}
		printf("Case #%d: %lld\n",kase,res);
	}
	return 0;
}
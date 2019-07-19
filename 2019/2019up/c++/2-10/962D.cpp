#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
const int maxn = 15e4 + 5;
ll a[maxn];
int main(int argc, char const *argv[])
{
	ll n,cnt = 0;
	scanf("%lld",&n);
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
		while(mp[a[i]])
		{
			a[mp[a[i]]] = 0ll;
			mp[a[i]] = 0ll;
			cnt++;
			a[i] *= 2;
		}
		mp[a[i]] = i;
	}
	printf("%lld\n",n - cnt);
	for(int i = 1;i <= n; ++i)
	{
		if(a[i])
		{
			printf("%lld ",a[i]);
		}
	}
	printf("\n");
	return 0;
}
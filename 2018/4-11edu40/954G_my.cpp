#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 5;
int n,r,a[maxn];
ll k;
ll b[maxn],c[maxn],sum[maxn];
bool ok(ll p)
{
	ll t = k;
	memset(c,0,sizeof(c));
	for(int i = 1;i <= n; ++i)
	{
		c[i] += c[i - 1];
		ll cur = b[i] + c[i];
		if(cur < p)
		{
			ll need = p - cur;
			if(need > t)
			{
				return 0;
			}
			t -= need;
			c[i] += need;
			c[min(n + 1,i + 2 * r + 1)] -= need;
		}
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
	cin>>n>>r>>k;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1;i <= n; ++i)
	{
		int ub = min(n,i + r);
        int lb = max(1,i - r);
		b[i] = sum[ub] - sum[lb - 1];
	}
	ll lb = 0,ub = LLONG_MAX;
	while(ub - lb > 1)
	{
		ll mid = (lb + ub) / 2;
		if(ok(mid))
		{
			lb = mid;
		}
		else
		{
			ub = mid;
		}
	}
	cout << lb << endl;
	return 0;
}
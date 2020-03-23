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
#define mcpy(a,b) (memcpy(a,b,sizeof(a)))
#define mset(a) (memset(a,0x00,sizeof(a)))
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int maxm = 3005;
ll mypow(ll a,ll b)
{
	ll res = 1;
	for(;b;b >>= 1,a = a * a % mod)
	{
		if(b & 1)
		{
			res = res * a % mod;
		}
	}
	return res;
}
ll f[maxn],invf[maxn],pickp[maxn],pickn[maxn],sd[maxn],p[maxn],lp[maxn],rp[maxn];
ll olp[maxn],orp[maxn],lps[maxn];
ll comb(int n,int r)
{
	if(n < 0 || r < 0 || n - r < 0)
	{
		return 0;
	}
	return f[n] * invf[r] % mod * invf[n - r] % mod;
}
void init()
{
	f[0] = invf[0] = 1;
	for(int i = 1;i < maxn; ++i)
	{
		f[i] = f[i - 1] * i % mod;
		invf[i] = mypow(f[i],mod - 2);
	}
}
ll mul(ll x,ll y)
{
	return x * y % mod;
}
ll add(ll x,ll y)
{
	return (x + y + 100ll * mod) % mod;
}
ll sadd(ll &x,ll y)
{
	return x = add(x,y);
}
int main(int argc, char const *argv[])
{
	init();
	int n,m,pa,pb,k;
	scanf("%d%d%d%d%d",&n,&m,&pa,&pb,&k);
	for(int i = 0;i < maxn; ++i)
	{
		pickp[i] = mypow(pa,i) * mypow(mypow(pb,mod - 2),i) % mod;
		pickn[i] = mypow(pb - pa,i) * mypow(mypow(pb,mod - 2),i) % mod;
	}
	for(int j = 0;j < maxn; ++j)
	{
		p[j] = comb(k,j) * pickp[j] % mod * pickn[k - j] % mod;
		sadd(sd[j],add(j == 0 ? 0ll : sd[j - 1],p[j]));
	}
	lp[0] = 1;
	rp[m - 1] = 1;
	for(int d = 0;d <= n; ++d)
	{
		mcpy(olp,lp);
		mcpy(orp,rp);
		mset(lp);
		mset(lps);
		mset(rp);
		ll sumrp = 0,all = 0,cur_val = 0;
		for(int j = 0;j < m; ++j)
		{
			sadd(all,olp[j]);
		}
		if(d == n)
		{
			printf("%lld\n",all);
			break;
		}
		for(int j = m - 1;j >= 0; --j)
		{
			lps[j] = add(lps[j + 1],olp[j]);
		}
		for(int j = 0;j < m; ++j)
		{
			sadd(rp[j],-mul(cur_val,p[m - j - 1]));
			sadd(rp[j],-mul(lps[j + 1],mul(sd[j],p[m - j - 1])));
			sadd(rp[j],mul(mul(all,sd[j]),p[m - j - 1]));
			sadd(sumrp,orp[j]);
			sadd(cur_val,mul(sumrp,p[j + 1]));
		}
		for(int j = 0;j < m; ++j)
		{
			lp[j] = rp[m - j - 1];
		}
	}
	return 0;
}
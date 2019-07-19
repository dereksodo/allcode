#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 6;
const ll base = 998244353;
ll st[maxn],pref_sum[maxn];
string s;
ll n;
void init()
{
	st[0] = 1;
	for(ll i = 1;i < maxn; ++i)
	{
		st[i] = (10 * st[i - 1]) % base;
	}
	pref_sum[0] = s[0] - '0';
	for(ll i = 1;i < n; ++i)
	{
		pref_sum[i] = (10 * pref_sum[i - 1] + s[i] - '0') % base;
	}
}
void trs(ll alen,ll blen,ll slen,ll n)
{
	// assert(alen + blen + slen == n);
	if((s[0] == '0' && alen > 1) || (s[alen] == '0' && blen > 1) || (s[alen + blen] == '0' && slen > 1))
	{
		return;
	}
	ll a = pref_sum[alen - 1];
	ll pref_odd_sum = a * st[blen] % base;
	ll b = (pref_sum[alen + blen - 1] - pref_odd_sum + base) % base;
	pref_odd_sum = pref_sum[alen + blen - 1] * st[slen] % base;
	ll c = (pref_sum[alen + blen + slen - 1] - pref_odd_sum + base) % base;
	if((a + b) % base != c)
	{
		return;
	}
	for(ll i = 0;i < alen; ++i)
	{
		printf("%c",s[i]);
	}
	printf("+");
	for(ll i = alen;i < alen + blen; ++i)
	{
		printf("%c",s[i]);
	}
	printf("=");
	for(ll i = alen + blen;i < n; ++i)
	{
		printf("%c",s[i]);
	}
	printf("\n");
	exit(0);
}
void ok(ll alen,ll blen,ll slen,ll n)
{
	if(alen > slen || blen > slen || blen <= 0 || alen <= 0)
	{
		return;
	}
	trs(alen,blen,slen,n);
}
int main(int argc, char const *argv[])
{
	cin>>s;
	n = s.size();
	init();
	for(ll slen = 1;slen <= n; ++slen)
	{
		ok(slen - 1,n - slen - slen + 1,slen,n);
		ok(slen,n - slen - slen,slen,n);
		ok(n - slen - slen + 1,slen - 1,slen,n);
		ok(n - slen - slen,slen,slen,n);
	}
	return 0;
}
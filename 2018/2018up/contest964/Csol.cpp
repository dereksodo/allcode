#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000009
int n,k;
string s;
typedef long long ll;
ll pow_log(ll b,int e)
{
	if (!e)
	return 1;
	ll ret=pow_log(b,e/2);
	ret=(ret*ret)%mod;
	if (e%2)
	ret=(ret*b)%mod;
	return ret;
}
ll go(ll a,ll b)
{
	ll ans=0;
	for (int i=0;i<k;i++)
	{
		ll tmp=(pow_log(a,n-i)*pow_log(b,i))%mod;
		if (s[i]=='+')
		ans+=tmp;
		else
		ans-=tmp;
		ans=(ans+mod)%mod;
	}
	/*
	ll p1=pow_log(b*pow_log(a,mod-2)%mod,n+1),p2=pow_log(b*(pow_log(a,mod-2))%mod,k);
	*/
	ll p1=pow_log(b*pow_log(a,mod - 2)%mod,n+1),p2=pow_log(b*(pow_log(a,mod - 2))%mod,k);
	if (p2==1)
	return (ans*((n+1)/k))%mod;
	return (((ans*(1-p1+mod))%mod)*pow_log(1-p2+mod,mod - 2))%mod;
}
int main()
{
	int a,b;
	cin >> n >> a >> b >> k >> s;
	cout << go(a,b) << endl;
}
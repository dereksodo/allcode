#include <iostream>
using namespace std;
typedef long long ll;
ll f(ll n)
{
	if(n < 10)
	{
		return max(1ll,n);
	}
	return max(f(n / 10) * f(n % 10),9 * f(n / 10 - 1));
}
int main(int argc, char const *argv[])
{
	ll x;
	cin>>x;
	cout<<f(x)<<endl;
	return 0;
}
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
const int maxn = 2e5 + 500;
int main(int argc, char const *argv[])
{
	ll n;
	scanf("%lld",&n);
	vector<ll> a,b;
	for(ll i = 2;i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			a.push_back(i);
			if(n != i * i)
			{
				a.push_back(n / i);
			}
		}
	}
	a.push_back(n);
	ll m = n;
	--n;
	for(ll i = 2;i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			b.push_back(i);
			if(n != i * i)
			{
				b.push_back(n / i);
			}
		}
	}
	b.push_back(n);
	n = m;
	ll cnt = 0;
	for(int i = 0;i < b.size(); ++i)
	{
		if(n % b[i] != 0)
		{
			++cnt;
		}
	}
	for(int i = 0;i < a.size(); ++i)
	{
		ll tmp = n;
		while(tmp % a[i] == 0)
		{
			tmp /= a[i];
		}
		if(tmp % a[i] == 1)
		{
			++cnt;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
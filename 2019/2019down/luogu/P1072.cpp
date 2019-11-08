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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
ll gcd(ll a,ll b)
{
	return b == 0 ? a : gcd(b,a % b);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--)
	{
		ll a0,a1,b0,b1;
		cin>>a0>>a1>>b0>>b1;
		ll x1 = a0 / a1,x2 = b1 / b0;
		ll ans = 0;
		for(ll i = 1;i * i <= b1; ++i)
		{
			if(b1 % i == 0)
			{
				ll ii = i;
				if(ii % a1 == 0 && gcd(ii / a1,x1) == 1 && gcd(b1 / ii,x2) == 1)
				{
					++ans;
				}
				ii = b1 / i;
				if(ii == i)
				{
					continue;
				}
				if(ii % a1 == 0 && gcd(ii / a1,x1) == 1 && gcd(b1 / ii,x2) == 1)
				{
					++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
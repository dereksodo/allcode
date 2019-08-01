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
const ll mod = 1e9 + 7;
ll mypow(ll k,ll n)
{
	if(n == 0)
	{
		return 1ll;
	}
	else if(n == 1)
	{
		return k;
	}
	ll t = mypow(k,n / 2);
	return t * t * mypow(k,n % 2) % mod;
}
void print(ll p,ll q)
{
	printf("%lld\n",mypow(p,q - 2));
}
int main(int argc, char const *argv[])
{
	int p,q;
	cin>>p>>q;
	print(p,q);
	return 0;
}
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
const ll mod = 100003;
ll mypow(ll a,ll b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a % mod;
	}
	ll res = mypow(a,b / 2);
	return res * res % mod * (b & 1 ? a : 1) % mod;
}
int main(int argc, char const *argv[])
{
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll ans = mypow(a,b);
	ans = (ans - a * mypow(a - 1,b - 1) % mod + mod) % mod;
	printf("%lld\n",ans);
	return 0;
}
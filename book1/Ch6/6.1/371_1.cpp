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
	#define debug prllf
#else
	#define debug(...)
#endif
ll mod,a,b;
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
	scanf("%lld%lld%lld",&a,&b,&mod);
	printf("%lld\n",mypow(a,b));
	return 0;
}
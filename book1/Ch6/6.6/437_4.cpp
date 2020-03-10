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
ll ans,n,m;
ll gcd(ll a,ll b)
{
	return b == 0 ? a : gcd(b,a % b);
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld",&n,&m);
	++n,++m;
	ans = (n * m) * (n * m - 1) * (n * m - 2) / 6;
	if(n >= 3)
	{
		ans -= n * (n - 1) * (n - 2) / 6 * m;
	}
	if(m >= 3)
	{
		ans -= m * (m - 1) * (m - 2) / 6 * n;
	}
	for(int i = 1;i < n; ++i)
	{
		for(int j = 1;j < m; ++j)
		{
			ans -= (n - i) * (m - j) * (gcd(i,j) - 1) * 2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
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
const ll maxn = 200005;
const ll mod = 998244353;
ll fac[maxn];
int main(int argc, char const *argv[])
{
	fac[0] = 1;
	for(int i = 1;i < maxn; ++i)
	{
		fac[i] = fac[i - 1] * 10 % mod;
	}
	int n;
	scanf("%d",&n);
	for(int i = 1;i < n; ++i)
	{
		ll res = 2 * 10 * 9 * fac[n - i - 1];
		res += (n - i - 1) * 10 * 9 * 9 * fac[n - i - 2];
		printf("%lld\n",res % mod);
	}
	printf("10\n");
	return 0;
}
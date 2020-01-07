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
const int maxn = 250000 + 5;
ll fact[maxn];
int n,mod;
int main(int argc, char const *argv[])
{
	cin>>n>>mod;
	fact[0] = 1ll;
	for(int i = 1;i <= n; ++i)
	{
		fact[i] = fact[i - 1] * i % mod;
	}
	ll ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans += (n - i + 1) * (fact[i] * fact[n - i + 1] % mod) % mod;
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}
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
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll ans = n + 1;
	for(ll k1 = 1;k1 * k1 <= n; ++k1)
	{
		ll k2 = n / k1 + bool(n % k1);
		ans = min(ans,k1 + k2);
	}
	cout<<ans<<endl;
	return 0;
}
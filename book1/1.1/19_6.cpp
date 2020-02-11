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
const int maxn = 1e6 + 6;
ll a[maxn];
ll s[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll avg = 0;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
		avg += a[i];
	}
	avg /= n;
	for(int i = 2;i <= n; ++i)
	{
		s[i] = s[i - 1] + a[i] - avg;
	}
	sort(s + 1,s + n + 1);
	ll ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans += abs(s[i] - s[(n >> 1) + 1]);
	}
	cout<<ans<<endl;
	return 0;
	return 0;
}
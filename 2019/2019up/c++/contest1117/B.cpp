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
const ll maxn = 2e5 + 5;
ll a[maxn];
int main(int argc, char const *argv[])
{
	ll n,k,m;
	cin>>n>>k>>m;
	for(int i = 0;i < n; ++i)
	{
		scanf("%lld",a + i);
	}
	sort(a,a + n);
	ll max1 = a[n - 1];
	ll max2 = a[n - 2];
	printf("%lld\n",k / (m + 1) * m * max1 + k / (m + 1) * max2 + (k - (k / (m + 1)) * (m + 1)) * max1);
	return 0;
}
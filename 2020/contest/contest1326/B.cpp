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
const int maxn = 200005;
ll a[maxn],b[maxn],x[maxn];
int main(int argc, char const *argv[])
{
	ll n;
	scanf("%lld",&n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&b[i]);
	}
	a[1] = b[1];
	ll mx = 0;
	for(int i = 1;i <= n; ++i)
	{
		a[i] = b[i] + mx;
		mx = max(mx,a[i]);
		printf("%lld ",a[i]);
	}
	printf("\n");
	return 0;
}
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
const int mod = 998244353;
pair<int,int> b[maxn];
int a[maxn],vis[maxn];
int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		b[i] = make_pair(-a[i],i);
	}
	sort(b + 1,b + n + 1);
	ll ans = 0,cnt = 0;
	for(int i = 1;i <= k; ++i)
	{
		a[++cnt] = b[i].second;
		ans += -b[i].first;
	}
	sort(a + 1,a + cnt + 1);
	printf("%lld ",ans);
	ans = 1;
	for(int i = 2;i <= k; ++i)
	{
		ans = (ans * (a[i] - a[i - 1])) % mod;
	}
	printf("%lld\n",ans);
	return 0;
}
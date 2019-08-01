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
const ll maxn = 1e5 + 5;
ll n,a[maxn],b[maxn],sum[maxn],ans;
int main(int argc, char const *argv[])
{
	cin>>n;
	for(ll i = 0;i < n; ++i)
	{
		scanf("%lld%lld",a + i,b + i);
		ans -= b[i];
		sum[i] = a[i] + b[i];
	}
	sort(sum,sum + n);
	reverse(sum,sum + n);
	for(ll i = 0;i < n; i += 2)
	{
		ans += sum[i];
	}
	cout<<ans<<endl;
	return 0;
}
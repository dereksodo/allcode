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
const int maxn = 1e5 + 5;
int a[maxn];
int main(int argc, char const *argv[])
{
	int n,m,k;
	cin>>n>>m>>k;
	k = n - k;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",a + i);
	}
	ll ans = n;
	for(int i = 1;i < n; ++i)
	{
		a[i] = a[i + 1] - a[i] - 1;
	}
	sort(a + 1,a + n);
	for(int i = 1;i <= k; ++i)
	{
		ans += a[i];
	}
	cout<<ans<<endl;
	return 0;
}
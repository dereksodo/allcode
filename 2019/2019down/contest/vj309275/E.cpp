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
const int maxn = 100005;
ll a[maxn];
ll n,c;
bool check(int s)
{
	int lastpos = a[1];
	int nc = 1;
	for(int i = 2;i <= n; ++i)
	{
		if(a[i] - lastpos >= s)
		{
			lastpos = a[i];
			nc++;
		}
	}
	return nc >= c; 
}
int main(int argc, char const *argv[])
{
	cin>>n>>c;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + n + 1);
	ll l = 0,r = a[n],ans = 1;
	while(l <= r)
	{
		ll mid = l + r >> 1;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
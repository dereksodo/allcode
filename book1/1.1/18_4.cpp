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
const int maxm = 7e5 + 5;
struct task{
	ll e,p;
	bool operator <(const task &b)const
	{
		return p > b.p;
	}
}a[maxn];
int f[maxm];
int ff(int x)
{
	if(x == f[x])
	{
		return x;
	}
	return f[x] = ff(f[x]);
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll sum = 0,maxx = 0;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d%d",&a[i].e,&a[i].p);
		sum += a[i].p;
		maxx = max(maxx,a[i].e);
	}
	sort(a,a + n);
	for(int i = 1;i <= maxx; ++i)
	{
		f[i] = i;
	}
	for(int i = 0;i < n; ++i)
	{
		int x = ff(a[i].e);
		if(!x)
		{
			sum -= a[i].p;
		}
		else
		{
			f[x] = ff(x - 1);
		}
	}
	printf("%lld\n",sum);
	return 0;
}
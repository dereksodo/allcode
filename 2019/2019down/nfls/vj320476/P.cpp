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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
ll abs_(ll p)
{
	return p > 0 ? p : -p;
}
const int maxn = 2005;
struct node{
	ll a,b,i;
}a[maxn];
bool cmp1(node a,node b)
{
	return a.a < b.a;
}
bool cmp2(node a,node b)
{
	return a.i < b.i;
}
ll h[2005],f[2005];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i].a);
		a[i].i = i;
	}
	sort(a + 1,a + n + 1,cmp1);
	int cnt = 0;
	a[0].a = -1;
	for(int i = 1;i <= n; ++i)
	{
		if(a[i].a != a[i - 1].a)
		{
			++cnt;
			h[cnt] = a[i].a;
		}
		a[i].b = cnt;
	}
	sort(a + 1,a + n + 1,cmp2);
	ll ans = LLONG_MAX;
	memset(f,0x00,sizeof(f));
	f[cnt + 1] = ans;
	for(int i = n;i > 0; --i)
	{
		for(int j = 1;j <= cnt; ++j)
		{
			f[j] += abs_(a[i].a - h[j]);
		}
		for(int j = cnt;j > 0; --j)
		{
			f[j] = min(f[j],f[j + 1]);
		}
	}
	for(int i = 1;i <= cnt; ++i)
	{
		ans = min(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
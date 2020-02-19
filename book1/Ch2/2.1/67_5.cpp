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
typedef unsigned int ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 2e5 + 5;
const int base = 1e9 + 7;
set<ll> s;
ll pre[maxn],rev[maxn],f[maxn];
int a[maxn],ans[maxn],acnt;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	f[0] = 1ll;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		pre[i] = pre[i - 1] * base + a[i];
		f[i] = f[i - 1] * base;
	}
	for(int i = n;i; --i)
	{
		rev[i] = rev[i + 1] * base + a[i];
	}
	int maxx = 0,cnt = 0;
	for(int i = 1;i * maxx <= n; ++i)
	{
		s.clear();
		cnt = 0;
		for(int j = 1,t;j + i <= n + 1; j += i)
		{
			t = min(pre[j + i - 1] - pre[j - 1] * f[i],rev[j] - rev[j + i] * f[i]);
			if(s.count(t))
			{
				continue;
			}
			s.insert(t);
			++cnt;
		}
		if(cnt > maxx)
		{
			maxx = cnt,ans[0] = i,acnt = 1;
		}
		else if(cnt == maxx)
		{
			ans[acnt++] = i;
		}
	}
	printf("%d %d\n",maxx,acnt);
	for(int i = 0;i < acnt; ++i)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
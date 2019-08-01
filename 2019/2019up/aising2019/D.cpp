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
const ll maxn = 100005;
ll a[maxn];
ll sum[maxn];
ll vis[maxn];
int main(int argc, char const *argv[])
{
	for(ll k = 1;k <= 10; ++k)
	{
		printf("k = %d\n",k);
	for(int i = 1;i <= k; ++i)
	{
		a[i] = i;
		sum[i] = sum[i - 1] + a[i];
	}
	for(int x = 1;x <= k; ++x)
	{
		int ans = 0;
		memset(vis,0x00,sizeof(vis));
		for(int j = 1;j <= k; ++j)
		{
			if(j & 1)
			{
				for(int i = k;i >= 1; --i)
				{
					if(!vis[i])
					{
						ans += a[i];
						vis[i] = 1;
						break;
					}
				}
			}
			else
			{
				int minx = 0x3f3f3f3f,minpos = 0;
				for(int i = 1;i <= k; ++i)
				{
					if(!vis[i])
					{
						int now = abs(a[i] - x);
						if(now < minx)
						{
							minpos = i;
							minx = now;
						}
					}
				}
				vis[minpos] = 1;
			}
		}
		printf("ans = %d\n",ans);
	}
	printf("\n");
	}

	ll n,q;
	scanf("%lld%lld",&n,&q);
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",a + i);
		sum[i] = sum[i - 1] + a[i];
	}
	sort(a + 1,a + n + 1);
	ll mid = a[(n + 1) / 2];
	printf("mid = %lld\n",mid);
	while(q--)
	{
		ll x;
		scanf("%lld",&x);
		if(x < mid)
		{
			printf("%lld\n",sum[n] - sum[(n >> 1)]);
		}
	}
	return 0;
}
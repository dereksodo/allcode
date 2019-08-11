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
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1005;
struct p{
	int t,l,r;
}a[maxn];
int ans[maxn],vis[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	memset(vis,0x00,sizeof(vis));
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r);
		if(a[i].t == 1)
		{
			debug("a[%d].l = %d,a[%d].r = %d\n",i,a[i].l,i,a[i].r);
			for(int j = a[i].l;j < a[i].r; ++j)//**** <
			{
				vis[j] = 1;
			}
		}
	}
	for(int i = 0;i < maxn; ++i)
	{
		ans[i] = 2000;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(vis[i])
		{
			ans[i + 1] = ans[i];
		}
		else
		{
			ans[i + 1] = ans[i] - 1;
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		debug("%d ",ans[i]);
	}
	debug("\n");
	for(int i = 1;i <= m; ++i)
	{
		if(a[i].t == 0)
		{
			int flag = 0;
			for(int j = a[i].l;j < a[i].r; ++j)
			{
				if(ans[j] > ans[j + 1])
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i = 1;i <= n; ++i)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
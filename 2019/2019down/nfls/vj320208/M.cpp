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
int a[25],n,vis[25];
int cnt;
int prime[50];
int isp(int x)
{
	if(x < 2)
	{
		return 0;
	}
	if(x == 2)
	{
		return 1;
	}
	for(int i = 2;i * i <= x; ++i)
	{
		if(x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void init()
{
	for(int i = 1;i < 50; ++i)
	{
		prime[i] = isp(i);
	}
}
int is_prime(int x)
{
	return prime[x];
}
void dfs(int now)
{
	if(now == n)
	{
		if(is_prime(a[n] + a[1]))
		{
			for(int i = 1;i <= n; ++i)
			{
				printf("%d",a[i]);
				if(i != n)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		return;
	}
	for(int i = 2;i <= n; ++i)
	{
		if(!vis[i] && is_prime((a[now] + i)))
		{
			a[now + 1] = i;
			vis[i] = 1;
			dfs(now + 1);
			vis[i] = 0;
			a[now + 1] = 0;
		}
	}
}
int main(int argc, char const *argv[])
{
	init();
	while(scanf("%d",&n) != EOF)
	{
		printf("Case %d:\n",++cnt);
		memset(a,0x00,sizeof(a));
		memset(vis,0x00,sizeof(vis));
		a[1] = 1;
		vis[1] = 1;
		dfs(1);
		printf("\n");
	}
	return 0;
}
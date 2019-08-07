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
int a[20],vis[20],n;
map<int,int> mp;
int check()
{
	int ret = 1;
	for(int i = 1;i <= n; ++i)
	{
		ret = (ret << 1) + vis[i];
	}
	return ret;
}
void dfs(int now,int cnt)
{
	if(now > n + 1)
	{
		return;
	}
	if(cnt == 6)
	{
		int x = check();
		if(mp[x])
		{
			return;
		}
		mp[x] = 1;
		int flag = 1;
		for(int i = 1;i <= n; ++i)
		{
			if(vis[i])
			{
				if(flag)
				{
					printf("%d",a[i]);
					flag = 0;
				}
				else
				{
					printf(" %d",a[i]);
				}
			}
		}
		printf("\n");
		return;
	}
	for(int i = now;i <= n; ++i)
	{
		vis[i] = 1;
		dfs(i + 1,cnt + 1);
		vis[i] = 0;
	}
	dfs(now + 1,cnt);
}
int main(int argc, char const *argv[])
{
	int cnt = 0;
	while(cin>>n && n)
	{
		if(cnt++)
		{
			printf("\n");
		}
		mp.clear();
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		memset(vis,0x00,sizeof(vis));
		dfs(1,0);
	}
	return 0;
}
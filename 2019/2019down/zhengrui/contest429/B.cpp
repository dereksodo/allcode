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
set<ll> s;
int vis[15];
ll p;
void dfs(ll now)
{
	if(s.find(now) != s.end())
	{
		return;
	}
	if(now * now > p * 10)
	{
		return;
	}
	s.insert(now);
	for(int i = 0;i < 10; ++i)
	{
		if(vis[i])
		{
			vis[i]--;
			dfs(now * 10 + i);
			vis[i]++;
		}
	}
}
void pre()
{
	s.clear();
	memset(vis,0x00,sizeof(vis));
	ll px = p;
	while(px)
	{
		vis[px % 10]++;
		px /= 10;
	}
	dfs(0);
}
int vis2[15];
bool check(ll px)
{
	memcpy(vis2,vis,sizeof(vis));
	while(px)
	{
		vis2[px % 10]--;
		if(vis2[px % 10] < 0)
		{
			return 0;
		}
		px /= 10;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while(cin>>p && p)
	{
		pre();
		// for(int i = 0;i < 10; ++i)
		// {
		// 	printf("%d ",vis[i]);
		// }
		// printf("\n");
		// printf("%d\n",vis[0]);
		if(vis[0])
		{
			printf("0 * 0 = 0\n");
		}
		// cerr << int(s.size()) << endl;
		for(set<ll>::iterator iter = s.begin();iter != s.end(); ++iter)
		{
			ll now = *iter;
			if(now == 0)
			{
				continue;
			}
			// if(now * now > p)
			// {
			// 	break;
			// }
			// if(s.find(now * now) != s.end())
			// {
			// 	printf("%lld * %lld = %lld\n",now,now,now * now);
			// }
			if(check(now * now))
			{
				printf("%lld * %lld = %lld\n",now,now,now * now);
			}
		}
	}
	return 0;
}
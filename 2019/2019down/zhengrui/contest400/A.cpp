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
ll a[100000];
int cnt;
set<ll> s;
void dfs(ll now,ll is,ll p)
{
	if(now >= 1e17)
	{
		return;
	}
	if(is)
	{
		if(now >= 10 && now < 100)
		{
			dfs(now * 10 + (now % 10),is,(now % 10));
		}
		dfs(now * 10 + p,is,p);
		// printf("%lld\n",now);
		// if(now < 200)
		// {
			// printf("%lld\n",now);
		// }
		s.insert(now);
	}
	else
	{
		dfs(now * 10 + p,0,p);
		for(int i = 0;i <= 9; ++i)
		{
			if(i != p)
			{
				dfs(now * 10 + i,1,p);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	for(int i = 1;i <= 9; ++i)
	{
		dfs(i,0,i);
	}
	// printf("%lld\n",s.size());
	// getchar();
	for(set<ll>::iterator iter = s.begin();iter != s.end(); ++iter)
	{
		a[cnt++] = *iter;
	}
	ll be,en;
	cin>>be>>en;
	ll pos1 = lower_bound(a,a + cnt,be) - a;
	ll pos2 = lower_bound(a,a + cnt,en) - a;
	if(a[pos2] > en)
	{
		pos2--;
	}
	// for(int i = pos1;i <= pos2; ++i)
	// {
	// 	printf("%lld ",a[i]);
	// }
	// printf("\n");
	printf("%lld\n",pos2 - pos1 + 1);
	return 0;
}
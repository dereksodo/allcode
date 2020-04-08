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
const int maxn = 1e5 + 50;
set<ll> ans;
void bfs()
{
	priority_queue< ll,vector<ll>,greater<ll> > pq;
	for(int i = 1;i <= 9; ++i)
	{
		pq.push(i);
	}
	while(!pq.empty() && (ans.size() < (1e5 + 10)))
	{
		ll now = pq.top();
		pq.pop();
		ans.insert(now);
		int l = max(0ll,now % 10 - 1);
		int r = min(9ll,now % 10 + 1);
		for(int i = l;i <= r; ++i)
		{
			pq.push(now * 10 + i);
		}
	}
}
int main(int argc, char const *argv[])
{
	bfs();
	ll k;
	scanf("%lld",&k);
	set<ll>::iterator iter = ans.begin();
	while(--k)
	{
		// printf("%lld\n",*iter);
		++iter;
	}
	printf("%lld\n",*iter);
	return 0;
}
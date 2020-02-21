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
const int maxn = 1e4 + 5;
int last[maxn],cnt[maxn],num[maxn];
int main(int argc, char const *argv[])
{
	int n,k,p,pos = 0;
	ll ans = 0;
	scanf("%d%d%d",&n,&k,&p);
	for(int i = 1,color,price;i <= n; ++i)
	{
		scanf("%d%d",&color,&price);
		if(price <= p)
		{
			pos = i;
		}
		if(pos >= last[color])
		{
			cnt[color] = num[color];
		}
		ans += cnt[color];
		last[color] = i;
		++num[color];
	}
	printf("%lld\n",ans);
	return 0;
}
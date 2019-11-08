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
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	ll sum1 = 0,sum2 = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			ll x;
			scanf("%lld",&x);
			if((i + j) & 1)
			{
				sum1 += x;
			}
			sum2 += x;
		}
	}
	if(sum1 * 2 == sum2)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
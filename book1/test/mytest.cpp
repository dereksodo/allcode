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
const int maxn = 1005;
ll a[maxn][maxn];
ll c(ll i,ll y)
{
	if(a[i][y] != -1)
	{
		return a[i][y];
	}
	if(i < 2)
	{
		return 1;
	}
	ll ret = 0;
	ll h = min(i,y);
	for(int j = 1;j <= h; ++j)
	{
		ret += c(i - j,j);
	}
	return a[i][y] = ret;
}
int main(int argc, char const *argv[])
{
	memset(a,-1,sizeof(a));
	for(int i = 1;i <= 100; ++i)
	{
		printf("%lld,",c(i,i));
		if(i % 10 == 0)
		{
			printf("\n");
		}
	}
	return 0;
}
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
const ll mod = 1e9 + 7;
ll dp[1005][15];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	m *= 2;
	for(int i = 1;i <= n; ++i)
	{
		dp[1][i] = 1;
	}
	for(int i = 2;i <= m; ++i)
	{
		for(int j = n;j >= 1; --j)
		{
			dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		ans = (ans + dp[m][i]) % mod;
	}
	cout<<ans<<endl;
	return 0;
}
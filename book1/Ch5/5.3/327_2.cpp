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
int dp[15][5];
int dig[15];
int l,r;
void init()
{
	dp[0][0] = 1;
	for(int i = 1;i <= 9; ++i)
	{
		dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][0] + dp[i - 1][1];
	}
}
int solve(int x)//0~(x-1)
{
	int ret = x,ans = 0;
	memset(dig,0x00,sizeof(dig));
	while(x)
	{
		dig[++dig[0]] = x % 10;
		x /= 10;
	}
	dig[dig[0] + 1] = 0;
	for(int i = dig[0],flag = 0;i; --i)
	{
		ans += dig[i] * dp[i - 1][2];
		if(flag)
		{
			ans += dig[i] * dp[i - 1][0];
		}
		else
		{
			if(dig[i] > 4)
			{
				ans += dp[i - 1][0];
			}
			if(dig[i] > 6)
			{
				ans += dp[i - 1][1];
			}
			if(dig[i + 1] == 6 && dig[i] > 2)
			{
				ans += dp[i][1];
			}
		}
		if(dig[i] == 4 || (dig[i + 1] == 6 && dig[i] == 2))
		{
			flag = 1;
		}
	}
	return ret - ans;
}
int main(int argc, char const *argv[])
{
	init();
	while(scanf("%d%d",&l,&r) && l && r)
	{
		printf("%d\n",solve(r + 1) - solve(l));
	}
	return 0;
}
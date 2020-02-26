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
const int maxn = 15;
int dp[maxn][maxn],dig[maxn];
void init()
{
	dp[0][0] = 1;
	for(int i = 1;i < maxn; ++i)
	{
		for(int j = 0;j < 10; ++j)
		{
			for(int k = 0;k < 10; ++k)
			{
				if(k != 4 && !(j == 6 && k == 2))
				{
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}
}
int solve(int x)
{
	x++;//very important
	memset(dig,0x00,sizeof(dig));
	while(x)
	{
		dig[++dig[0]] = x % 10;
		x /= 10;
	}
	int ans = 0;
	for(int i = dig[0];i; --i)
	{
		for(int j = 0;j < dig[i]; ++j)
		{
			if(j != 4 && !(j == 2 && dig[i + 1] == 6))
			{
				ans += dp[i][j];
			}
		}
		if(dig[i] == 4 || (dig[i] == 2 && dig[i + 1] == 6))
		{
			break;
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int l,r;
	init();
	while(scanf("%d%d",&l,&r) && l && r)
	{
		printf("%d\n",solve(r) - solve(l - 1));
	}
	return 0;
}
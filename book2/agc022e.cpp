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
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
int mp[8][2] = {3,1,5,2,2,2,4,7,3,3,6,1,5,5,3,1};
int dp[maxn][8],len;
char s[maxn];
int main(int argc, char const *argv[])
{
	scanf("%s",s);
	int len = strlen(s);
	dp[len][1] = dp[len][2] = 1;
	for(int i = len - 1;i >= 0; --i)
	{
		for(int j = 0;j < 8; ++j)
		{
			if(s[i] != '0')
			{
				dp[i][j] += dp[i + 1][mp[j][1]];
			}
			if(s[i] != '1')
			{
				dp[i][j] += dp[i + 1][mp[j][0]];
			}
			dp[i][j] %= mod;
		} 
	}
	printf("%d\n",dp[0][0]);
	return 0;
}
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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int dp[60][60];
const int dx[] = {1,0,-1, 0,1,-1, 1,-1};
const int dy[] = {0,1, 0,-1,1,-1,-1, 1};
struct DesertWind{
	int daysNeeded(vector<string> mp)
	{
		int n = mp.size();
		int m = mp[0].size();
		memset(dp,0x3f3f3f3f,sizeof(dp));
		for(int i = 0;i < n; ++i)
		{
			for(int j = 0;j < m; ++j)
			{
				if(mp[i][j] == '*')
				{
					dp[i][j] = 0;
				}
			}
		}
		for(int it = 0;it <= n * m; ++it)
		{
			for(int i = 0;i < n; ++i)
			{
				for(int j = 0;j < m; ++j)
				{
					if(mp[i][j] == 'X')
					{
						continue;
					}
					int min1 = -1,min2 = -1;
					for(int k = 0;k < 8; ++k)
					{
						int ni = i + dx[k];
						int nj = j + dy[k];
						if(ni >= 0 && nj >= 0 && ni < n && nj < m && mp[ni][nj] != 'X')
						{
							if(min1 == -1 || dp[ni][nj] < min1)
							{
								min2 = min1,min1 = dp[ni][nj];
							}
							else if(min2 == -1 || dp[ni][nj] < min2)
							{
								min2 = dp[ni][nj];
							}
						}
					}
					if(min1 != -1)
					{
						dp[i][j] = min(dp[i][j],min1 + 3);
					}
					if(min2 != -1)
					{
						dp[i][j] = min(dp[i][j],min2 + 1);
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0;i < n; ++i)
		{
			for(int j = 0;j < m; ++j)
			{
				if(mp[i][j] == '@')
				{
					ans = (dp[i][j] == 0x3f3f3f3f ? -1 : dp[i][j]);
					break;
				}
			}
		}
		return ans;
	}
};
int main(int argc, char const *argv[])
{
	
	return 0;
}
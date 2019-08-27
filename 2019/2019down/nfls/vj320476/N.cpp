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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 1005;
char a[maxn][maxn];
int dp[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n && n)
	{
		for(int i = 0;i < n; ++i)
		{
			scanf("%s",a[i]);
		}
		memset(dp,0x00,sizeof(dp));
		int ans = 1;
		for(int i = 0;i < n; ++i)
		{
			for(int j = 0;j < n; ++j)
			{
				if(i == 0 || j == n - 1)
				{
					dp[i][j] = 1;
				}
				else
				{
					int j2 = j;
					int i2 = i;
					int cnt = 0;
					while(j2 >= 0 && i2 < n && a[i][j2] == a[i2][j])
					{
						cnt++;
						j2++;
						i2--;
					}
					dp[i][j] = min(dp[i - 1][j + 1] + 1,cnt);
				}
				ans = max(ans,dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
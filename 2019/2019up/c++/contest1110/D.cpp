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
const int maxn = 1e6 + 5;
int a[maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	vector<int> mp(m);
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",a + i);
		a[i]--;
		mp[a[i]]++;
	}
	int dp[3][3] = {0};
	for(int i : mp)
	{
		int new_dp[3][3] = {0};
		for(int p1 = 0;p1 <= 2; ++p1)
		{
			for(int p2 = 0;p2 <= 2; ++p2)
			{
				for(int p3 = 0;p3 <= 2; ++p3)
				{
					if(p1 + p2 + p3 <= i)
					{
						new_dp[p2][p3] = max(new_dp[p2][p3],dp[p1][p2] + p3 + (i - p1 - p2 - p3) / 3);
					}
				}
			}
		}
		for(int i = 0;i < 3; ++i)
		{
			for(int j = 0;j < 3; ++j)
			{
				dp[i][j] = new_dp[i][j];
			}
		}
	}
	printf("%d\n",dp[0][0]);
	return 0;
}
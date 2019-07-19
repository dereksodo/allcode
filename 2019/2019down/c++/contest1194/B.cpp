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
const int maxn = 5e4 + 5;
string ch[maxn];
int dp[maxn],dp2[maxn];
int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	while(q--)
	{
		int n,m;
		scanf("%d%d\n",&n,&m);
		for(int i = 1;i <= n; ++i)
		{
			cin>>ch[i];
			ch[i] = " " + ch[i];
		}
		for(int i = 1;i <= n; ++i)
		{
			dp[i] = 0;
			for(int j = 1;j <= m; ++j)
			{
				dp[i] += (ch[i][j] == '*');
			}
		}
		for(int j = 1;j <= m; ++j)
		{
			dp2[j] = 0;
			for(int i = 1;i <= n; ++i)
			{
				dp2[j] = dp2[j] + (ch[i][j] == '*');
			}
		}
		int ans = 1e9;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= m; ++j)
			{
				if(ch[i][j] == '.')
				{
					ans = min(ans,n + m - dp[i] - dp2[j] - 1);
				}
				else
				{
					ans = min(ans,n + m - dp[i] - dp2[j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
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
struct nod{
	int begin,end,eff;
	bool operator <(const nod &b)const
	{
		return begin < b.begin;
	}
};
nod node[maxn];
int b[maxn],e[maxn],f[maxn],dp[maxn];
int main(int argc, char const *argv[])
{
	int n,m,r;
	cin>>n>>m>>r;
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d%d",&node[i].begin,&node[i].end,&node[i].eff);
	}
	sort(node + 1,node + m + 1);
	for(int i = 1;i <= m; ++i)
	{
		b[i] = node[i].begin,e[i] = node[i].end,f[i] = node[i].eff;
	}
	int ans = dp[1] = f[1];
	for(int i = 2;i <= m; ++i)
	{
		dp[i] = f[i];
		for(int j = i - 1;j >= 1; --j)
		{
			if(b[i] - r >= e[j])
			{
				dp[i] = max(dp[i],dp[j] + f[i]);
			}
		}
		ans = max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
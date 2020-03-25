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
const int maxn = 1e5 + 5;
vector<int> cp[maxn];
int vis[maxn],vis2[maxn];
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i = 1,k;i <= n; ++i)
		{
			cp[i].clear();
			vis[i] = 0,vis2[i] = 0;
			scanf("%d",&k);
			for(int j = 1,kk;j <= k; ++j)
			{
				scanf("%d",&kk);
				cp[i].push_back(kk);
			}
		}
		int cpcnt = 0;
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 0;j < cp[i].size(); ++j)
			{
				if(!vis[cp[i][j]])
				{
					vis2[i] = 1;
					vis[cp[i][j]] = 1;
					++cpcnt;
					break;
				}
			}
		}
		if(cpcnt == n)
		{
			printf("OPTIMAL\n");
		}
		else
		{
			int k1,k2;
			for(int i = 1;i <= n; ++i)
			{
				if(!vis[i])
				{
					k1 = i;
				}
				if(!vis2[i])
				{
					k2 = i;
				}
			}
			printf("IMPROVE\n%d %d\n",k2,k1);
		}
	}
	return 0;
}
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
const int maxn = 505;
int node[maxn];
int G[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&node[i]);
	}
	for(int i = 1;i <= m; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		G[x][y] = G[y][x] = z;
	}
	int ans1 = 0;
	int ans2 = 1;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			if(G[i][j] != 0)
			{
				if(ans1 * G[i][j] < ans2 * (node[i] + node[j]))
				{
					ans1 = node[i] + node[j];
					ans2 = G[i][j];
				}
			}
		}
	}
	printf("%.20lf\n",double(ans1 + 0.0) / double(ans2 + 0.0));
	return 0;
}
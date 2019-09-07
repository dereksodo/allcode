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
//126B,119D,535D,955D:Z-algorithm
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
const int maxn = 1e4 + 5;
vector< pair<int,int> > G[maxn];
int v[maxn];
int f[64][maxn];
int n,m,d,res;
void solve()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i = 0;i < n; ++i)
	{
		G[i].clear();
	}
	for(int i = 0;i < m; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		--x,--y;
		G[x].push_back(make_pair(y,z));
		G[y].push_back(make_pair(x,z));
	}
	int rt = 230;
	res = -1;
	while(rt--)
	{
		for(int i = 0;i < n; ++i)
		{
			v[i] = rand() % d;
		}
		for(int i = 0;i < (1 << d); ++i)
		{
			memset(f[i],-1,sizeof(int) * n);
		}
		for(int i = 0;i < n; ++i)
		{
			f[1 << v[i]][i] = 0;
		}
		for(int i = 0;i < (1 << d); ++i)
		{
			for(int j = 0;j < n; ++j)
			{
				if(f[i][j] == -1)
				{
					continue;
				}
				for(int d = 0;d < G[j].size(); ++d)
				{
					int u = G[j][d].first,p = G[j][d].second;
					if(!(i & (1 << v[u])))
					{
						f[i | (1 << v[u])][u] = max(f[i | (1 << v[u])][u],f[i][j] + p);
					}
				}
			}
		}
		for(int i = 0;i < n; ++i)
		{
			res = max(res,f[(1 << d) - 1][i]);
		}
	}
	if(res == -1)
	{
		printf("impossible\n");
	}
	else
	{
		printf("%d\n",res);
	}
}
int main(int argc, char const *argv[])
{
	srand(19260817);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
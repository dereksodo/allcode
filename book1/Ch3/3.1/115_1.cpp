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
const int maxn = 305;
int mat[maxn][maxn];
int p[maxn],vis[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	memset(p,0x3f3f3f3f,sizeof(p));
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&p[i]);
	}
	for(int i = 1;i <= n; mat[i][i] = p[i++])
	{
		for(int j = 1;j <= n; ++j)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		int u = 0;
		for(int j = 1;j <= n; ++j)
		{
			if(!vis[j] && p[j] < p[u])
			{
				u = j;
			}
		}
		ans += p[u];
		vis[u] = 1;
		for(int j = 1;j <= n; ++j)
		{
			p[j] = min(p[j],mat[u][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
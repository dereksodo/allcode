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
const int maxn = 105;
int h1[maxn],h2[maxn];
bool vis[maxn][maxn];
int ans[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n,m,h;
	cin>>n>>m>>h;
	for(int i = 0;i < m; ++i)
	{
		scanf("%d",h1 + i);
	}
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",h2 + i);
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			scanf("%d",&vis[i][j]);
		}
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if(!vis[i][j])
			{
				ans[i][j] = 0;
				continue;
			}
			ans[i][j] = min(h1[j],h2[i]);
			// printf("h2[n - i - 1] = %d,i = %d,j = %d\n",h2[n - i - 1],i,j);
		}
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
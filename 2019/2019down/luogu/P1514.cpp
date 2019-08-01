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
const int maxn = 505;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int vis[maxn][maxn],h[maxn][maxn];
int l[maxn][maxn],r[maxn][maxn];
int n,m;
int ok(int x,int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}
void dfs(int x,int y)
{
	vis[x][y] = 1;
	for(int i = 0;i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(ok(nx,ny) && h[x][y] > h[nx][ny])
		{
			if(!vis[nx][ny])
			{
				dfs(nx,ny);
			}
			l[x][y] = min(l[x][y],l[nx][ny]);
			r[x][y] = max(r[x][y],r[nx][ny]);
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&h[i][j]);
			l[i][j] = 0x3f3f3f3f;
		}
	}
	for(int j = 1;j <= m; ++j)
	{
		l[n][j] = r[n][j] = j;
	}
	for(int j = 1;j <= m; ++j)
	{
		if(vis[1][j])
		{
			continue;
		}
		dfs(1,j);
	}
	int ans1 = 0;
	bool flag = 0;
	for(int j = 1;j <= m; ++j)
	{
		if(!vis[n][j])
		{
			ans1++;
			flag = 1;
		}
	}
	if(flag)
	{
		printf("0\n%d\n",ans1);
		return 0;
	}
	int ans2 = 0;
	int nowleft = 1;
	while(nowleft <= m)
	{
		int maxr = 0;
		for(int i = 1;i <= m; ++i)
		{
			if(l[1][i] <= nowleft)
			{
				maxr = max(maxr,r[1][i]);
			}
		}
		ans2++;
		nowleft = maxr + 1;
	}
	printf("1\n%d\n",ans2);
	return 0;
}
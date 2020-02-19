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
const int maxn = 105;
const int maxk = 15;
const int inf = 0x3f3f3f3f;
int G[maxn][maxn];
int dist[maxn][maxn][maxk];
int vis[maxn][maxn][maxk];
struct node{
	int x,y,k;
	node(){};
	node(int xx,int yy,int kk)
	{
		x = xx,y = yy,k = kk;
	}
};
queue<node> q;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int n,K,cost[4];
int check(int x,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
int push(int x,int y,int k)
{
	if(!vis[x][y][k])
	{
		vis[x][y][k] = 1;
		q.push(node(x,y,k));
	}
}
int spfa()
{
	memset(dist,0x3f3f3f3f,sizeof(dist));
	dist[1][1][K] = 0;
	vis[1][1][K] = 1;
	q.push(node(1,1,K));
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		int x = now.x,y = now.y,k = now.k;
		vis[x][y][k] = 0;
		if(G[x][y] && k != K)
		{
			if(dist[x][y][K] > dist[x][y][k] + cost[0])
			{
				dist[x][y][K] = dist[x][y][k] + cost[0];
				push(x,y,K);
			}
			continue;
		}
		else
		{
			if(dist[x][y][K] > dist[x][y][k] + cost[0] + cost[2])
			{
				dist[x][y][K] = dist[x][y][k] + cost[0] + cost[2];
				push(x,y,K);
			}
		}
		if(k < 1)
		{
			continue;
		}
		for(int i = 0;i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!check(nx,ny))
			{
				continue;
			}
			int w = 0;
			if(nx < x || ny < y)
			{
				w = cost[1];
			}
			int nk = k - 1;
			if(dist[nx][ny][nk] > dist[x][y][k] + w)
			{
				dist[nx][ny][nk] = dist[x][y][k] + w;
				push(nx,ny,nk);
			}
		}
	}
	int ans = inf;
	for(int i = 0;i <= K; ++i)
	{
		ans = min(ans,dist[n][n][i]);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&K);
	for(int i = 0;i < 3; ++i)
	{
		scanf("%d",&cost[i]);
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			scanf("%d",&G[i][j]);
		}
	}
	printf("%d\n",spfa());
	return 0;
}
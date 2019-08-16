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
const int maxn = 190;
int a[maxn][maxn];
int dis[maxn][maxn];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int n,m;
int check(int x,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
void bfs(int x,int y)
{
	dis[x][y] = 0;
	queue< pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for(int k = 0;k < 4; ++k)
		{
			int ni = i + dx[k];
			int nj = j + dy[k];
			if(check(ni,nj))
			{
				if(dis[i][j] + 1 >= dis[ni][nj])
				{
					continue;
				}
				dis[ni][nj] = dis[i][j] + 1;
				q.push(make_pair(ni,nj));
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(a,0x00,sizeof(a));
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= m; ++j)
			{
				scanf("%01d",&a[i][j]);
			}
		}
		memset(dis,0x3f3f3f3f,sizeof(dis));
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= m; ++j)
			{
				if(a[i][j])
				{
					bfs(i,j);
				}
			}
		}
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= m; ++j)
			{
				printf("%d",dis[i][j]);
				if(j != m)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
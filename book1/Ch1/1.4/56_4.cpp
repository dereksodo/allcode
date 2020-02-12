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
const int maxn = 1005;
bool vis[maxn][maxn];
int a[maxn][maxn],n;
int q[maxn * maxn][2];
const int dx[] = {1,1,1,0,0,-1,-1,-1};
const int dy[] = {0,1,-1,1,-1,0,1,-1};
int check(int x,int y)
{
	return x >= 1 && y >= 1 && x <= n && y <= n;
}
int cnt1,cnt2;
void bfs(int i,int j)
{
	int h = 0,t = 1,low = 0,high = 0;
	q[1][0] = i;
	q[1][1] = j;
	vis[i][j] = 1;
	while(h < t)
	{
		int x = q[++h][0],y = q[h][1];
		for(int k = 0;k < 8; ++k)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(check(nx,ny))
			{
				if(a[nx][ny] < a[x][y])
				{
					high = 1;
				}
				if(a[nx][ny] > a[x][y])
				{
					low = 1;
				}
				if(a[nx][ny] == a[x][y] && !vis[nx][ny])
				{
					vis[nx][ny] = 1;
					q[++t][0] = nx;
					q[t][1] = ny;
				}
			}
		}
	}
	if(low && high)
	{
		return;
	}
	cnt1 += low;
	cnt2 += high;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			if(!vis[i][j])
			{
				bfs(i,j);
			}
		}
	}
	if(cnt1 || cnt2)
	{
		printf("%d %d\n",cnt2,cnt1);
	}
	else
	{
		printf("1 1\n");
	}
	return 0;
}
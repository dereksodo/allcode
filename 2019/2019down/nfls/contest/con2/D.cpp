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
int a[maxn][maxn];
int dp[maxn][maxn];
const int dx[] = {0,1,-1,0};
const int dy[] = {-1,0,0,1};
int n;
inline int read(){
   register int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline bool check(int x,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
inline void bfs(int x,int y)
{
	// printf("x = %d,y = %d,step = %d\n",x,y,step);
	queue< pair<int, pair<int,int> > > q;
	q.push(make_pair(0,make_pair(x,y)));
	while(!q.empty())
	{
		register int xx = q.front().second.first;
		register int yy = q.front().second.second;
		register int now = q.front().first;
		q.pop();
		if(dp[xx][yy] != now)
		{
			continue;
		}
		for(register int i = 0;i < 4; ++i)
		{
			register int nx = xx + dx[i];
			register int ny = yy + dy[i];
			if(check(nx,ny))
			{
				if(dp[nx][ny] > dp[xx][yy] + a[xx][yy])
				{
					dp[nx][ny] = dp[xx][yy] + a[xx][yy];
					q.push(make_pair(dp[nx][ny],make_pair(nx,ny)));
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	n = read();
	srand(time(NULL));
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			scanf("%1d",&a[i][j + 1]);
			dp[i][j + 1] = 0x3f3f3f3f;
		}
	}
	int k;
	k = read();
	for(int i = 1;i <= k; ++i)
	{
		int x,y;
		x = read(),y = read();
		dp[x][y] = 0;
		bfs(x,y);
	}
	int ans = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			int now = dp[i][j] + a[i][j];
			ans = ans > now ? ans : now;
		}
	}
	printf("%d\n",ans);
	return 0;
}
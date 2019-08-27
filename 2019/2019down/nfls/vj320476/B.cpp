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
const int maxn = 205;
struct node{
	int x,y,h,index;
	node(){};
	node(int a,int b,int c,int d)
	{
		x = a,y = b,h = c,index = d;
	}
	void scan()
	{
		scanf("%d%d%d",&x,&y,&h);
	}
	bool operator ==(const node &c)
	{
		return x == c.x && y == c.y && h == c.h;
	}
	bool operator <(const node &c)
	{
		if(c.x != x)
		{
			return x < c.x;
		}
		if(c.y != y)
		{
			return y < c.y;
		}
		return h > c.h;
	}
}a[maxn],b[maxn],c[maxn];
int dp[2][maxn][maxn];
int cmp1(node a,node b)
{
	return a.x < b.x;
}
int cmp2(node a,node b)
{
	return a.y < b.y;
}
int main(int argc, char const *argv[])
{
	int n;
	int cnt = 0;
	while(cin>>n && n)
	{
		for(int i = 1;i <= n; ++i)
		{
			c[i].scan();
		}
		int len = 1;
		for(int i = 1;i <= n; ++i)
		{
			a[len] = node(c[i].x,c[i].y,c[i].h,len);
			++len;
			a[len] = node(c[i].y,c[i].x,c[i].h,len);
			++len;
			a[len] = node(c[i].x,c[i].h,c[i].y,len);
			++len;
			a[len] = node(c[i].h,c[i].x,c[i].y,len);
			++len;
			a[len] = node(c[i].h,c[i].y,c[i].x,len);
			++len;
			a[len] = node(c[i].y,c[i].h,c[i].x,len);
			++len;
		}
		n = len - 1;
		sort(a + 1,a + n + 1,cmp1);
		int nowx = 0;
		int px = 0;
		for(int i = 1;i <= n; ++i)
		{
			if(a[i].x > nowx)
			{
				nowx = a[i].x;
				b[a[i].index].x = ++px;
			}
			else
			{
				b[a[i].index].x = px;
			}
			// printf("b[%d].x = %d\n",a[i].index,b[a[i].index].x);
		}
		sort(a + 1,a + n + 1,cmp2);
		int nowy = 0;
		int py = 0;
		for(int i = 1;i <= n; ++i)
		{
			if(a[i].y > nowy)
			{
				nowy = a[i].y;
				b[a[i].index].y = ++py;
			}
			else
			{
				b[a[i].index].y = py;
			}
			b[a[i].index].h = a[i].h;
			// printf("b[%d].y = %d\n",a[i].index,b[a[i].index].y);
			// printf("b[%d].h = %d\n",a[i].index,b[a[i].index].h);
		}
		sort(b + 1,b + n + 1);
		// for(int i = 1;i <= n; ++i)
		// {
		// 	printf("%d %d %d\n",b[i].x,b[i].y,b[i].h);
		// }
		memset(dp,0x00,sizeof(dp));
		b[0] = node(0,0,0,0);
		int ans = 0;
		int e = 0;
		for(int i = 0;i < n; ++i)
		{
			memset(dp[1 - e],0x00,sizeof(dp[1 - e]));
			for(int j = 1;j <= py + 1; ++j)
			{
				for(int k = 1;k <= px + 1; ++k)
				{
					if(b[i].x < j && b[i].y < k)
					{
						dp[1 - e][j][k] = max(dp[1 - e][j][k],dp[e][b[i].x][b[i].y] + b[i].h);
					}
					dp[1 - e][j][k] = max(dp[1 - e][j][k],dp[e][j][k]);
					// printf("dp[%d][%d][%d] = %d\n",i + 1,j,k,dp[i + 1][j][k]);
				}
			}
			e = 1 - e;
		}
		for(int j = 1;j <= py + 1; ++j)
		{
			for(int k = 1;k <= px + 1; ++k)
			{
				ans = max(ans,dp[1 - e][j][k]);
			}
		}
		printf("Case %d: maximum height = %d\n",++cnt,ans);
	}
	return 0;
}
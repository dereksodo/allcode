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
const int maxn = 10;
struct oil{
	int x,y;
	double rad;
	void input()
	{
		scanf("%d%d",&x,&y);
		rad = -1.0;
	}
}p[maxn];
int xa,ya,xb,yb;
int vis[maxn],n;
double r[maxn];
double dis[maxn][maxn];
double ans;
void dfs(double area,int sum)
{
	if(sum == n)
	{
		ans = max(ans,area);
		return;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			p[i].rad = (double)min(min(abs(p[i].x - xa),abs(p[i].x - xb)),min(abs(p[i].y - ya),abs(p[i].y - yb)));
			for(int j = 1;j <= n; ++j)
			{
				if(i != j && vis[j])
				{
					p[i].rad = min(p[i].rad,max(sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x)
												 + (p[i].y - p[j].y) * (p[i].y - p[j].y))
												 - p[j].rad,0.0));
				}
			}
			dfs(area + p[i].rad * p[i].rad * M_PI,sum + 1);
			vis[i] = 0;
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	cin>>xa>>ya>>xb>>yb;
	double siz = abs(xa - xb) * abs(ya - yb);
	for(int i = 1;i <= n; ++i)
	{
		p[i].input();
	}
	dfs(0.0,0);
	printf("%d\n",int(siz - ans + 0.5));
	return 0;
}
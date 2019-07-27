#include <bits/stdc++.h>
using namespace std;
typedef double lf;
const int maxn = 20;
int n,vis[maxn];
struct point{
	lf x,y;
	void scan()
	{
		scanf("%lf%lf",&x,&y);	
	}
};
point a[maxn];
lf ans;
lf dist[maxn][maxn];
lf cnt(int i,int j)
{
	return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
}
void dfs(int step,int now,lf dis)
{
	if(dis > ans)
	{
		return;
	}
	if(step == n)
	{
		ans = min(ans,dis);
	}
	for(int i = 1;i <= n; ++i)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			dfs(step + 1,i,dis + dist[now][i]);
			vis[i] = 0;
		}
	}
}
int main(int argc,char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		a[i].scan();
	}
	a[0].x = 0.0;
	a[0].y = 0.0;
	for(int i = 0;i <= n; ++i)
	{
		for(int j = 0;j <= n; ++j)
		{
			dist[i][j] = cnt(i,j);
		}
	}
	ans = 1e9 + 7;
	vis[0] = 1;
	dfs(0,0,0.0);
	printf("%.2lf\n",ans);
	return 0;
}


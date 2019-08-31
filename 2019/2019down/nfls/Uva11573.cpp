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
const int dx[] = {-1,-1,0,1,1,1,0,-1};
const int dy[] = {0,1,1,1,0,-1,-1,-1};
const int maxn = 1005;
int a[maxn][maxn],n,m;
int vis[maxn][maxn];
struct node{
	int x,y,t;
	node(int xx = 0,int yy = 0,int tt = 0)
	{
		x = xx,y = yy,t = tt;
	}
	bool operator <(const node &p)const
	{
		return t > p.t;
	}
	void scan()
	{
		scanf("%d%d",&x,&y);
		t = 0;
	}
};
int check(int nx,int ny)
{
	return nx > 0 && nx <= n && ny > 0 && ny <= m;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		memset(vis,-1,sizeof(vis));
		priority_queue<node> q;
		node st,ed;
		st.scan();
		ed.scan();
		q.push(st);
		vis[st.x][st.y] = 0;
		while(!q.empty())
		{
			node now = q.top();
			q.pop();
			if(now.x == ed.x && now.y == ed.y)
			{
				printf("%d\n",now.t);
				break;
			}
			for(int i = 0;i < 8; ++i)
			{
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				int p = now.t + (i != a[now.x][now.y]);
				if(check(nx,ny) && (vis[nx][ny] == -1 || vis[nx][ny] > p))
				{
					vis[nx][ny] = p;
					q.push(node(nx,ny,p));
				}
			}
		}
	}
	return 0;
}
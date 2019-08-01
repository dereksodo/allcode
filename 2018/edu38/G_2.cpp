#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
int n;
const int maxn = 200;
#define inf INT_MAX
bool vis[maxn];
int dis[maxn];
unsigned int G[maxn][maxn];
void spfa(int index)
{
	memset(dis,inf,sizeof(dis));
	memset(vis,0x00,sizeof(vis));
	queue<int> q;
	q.push(index);
	vis[index] = 1;
	dis[index] = 0;
	bool flag = 0;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i = 1;i <= n; ++i)
		{
			if(G[cur][i] != inf)
			{
				if(dis[i] > dis[cur] + G[cur][i])
				{
					dis[i] = dis[cur] + G[cur][i];
					if(!vis[i])
					{
						q.push(i);
						vis[i] = 1;
					}
				}
			}
		}
	}
}
void show()
{
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
}
int main(int agrc, char const *argv[])
{
	int m;
	cin>>n>>m;
	memset(G,inf,sizeof(G));
	for(int i = 0;i < m; ++i)
	{
		int x,y,w;
		cin>>x>>y>>w;
		G[x][y] = G[y][x] = w;
	}
	int q;
	cin>>q;
	show();
	while(q--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op == 1)
		{
			int d;
			cin>>d;
			G[x][y] = G[y][x] = d;
		}
		else if(op == 2)
		{
			G[x][y] = G[y][x] = inf;
		}
		else
		{
			spfa(x);
			printf("%d\n",dis[y]);
		}
	}
	return 0;
}
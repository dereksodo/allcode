nn.cpp#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
int n;
const int maxn = 20;
const int inf = INT_MAX;
int G[maxn][maxn] = {inf};
void insertt(int x,int y,int d)
{
	G[x][y] = G[y][x] = d;
}
void deletes(int x,int y)
{
	G[x][y] = G[y][x] = inf;
}
bool vis[maxn];
int dis[maxn];
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
		cout<<endl;
	}
}
int main(int agrc, char const *argv[])
{
	int m;
	cin>>n>>m;
	for(int i = 0;i < m; ++i)
	{
		int x,y,w;
		cin>>x>>y>>w;
		insertt(x,y,w);
		show();
	}
	int q;
	cin>>q;
	while(q--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op == 1)
		{
			printf("1\n");
			int d;
			cin>>d;
			insertt(x,y,d);
		}
		else if(op == 2)
		{
			printf("2\n");
			deletes(x,y);
		}
		else
		{
			printf("3\n");
			spfa(x);
			printf("%d\n",dis[y]);
		}
	}
	return 0;
}
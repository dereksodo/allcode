#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
const int maxn = 1e9 + 5;
#define INF 1000000001LL
int n,m;
vector< pair<int,int> > G[maxn];
bool vis[maxn];
short dis[maxn];
int dp[maxn];
void bfs(int index)
{
	//use G[][]
	memset(vis,0x00,sizeof(vis));
	queue<int> q;
	q.push(index);
	vis[index] = 1;
	while(!q.empty())
	{
		int cur = q.front();
		printf("%d ",cur);
		q.pop();
		vis[cur] = 1;
		for(int i = 0;i < G[cur].size(); ++i)
		{
			if(!vis[G[cur][i]])
			{
				q.push(G[cur][i]);
				vis[G[cur][i]] = 1;
			}
		}
	}
	memset(vis,0x00,sizeof(vis));
	printf("\n");
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 0;i < m; ++i)
	{
		int l,r,d;
		cin>>l>>r>>d;
		l--,r--;
		G[l].push_back(make_pair(r,d));
		G[r].push_back(make_pair(l,-d));
	}
	for(int i = 0;i < n; ++i)
	{
		dp[i] = INF;
	}
	for(int i = 0;i < n; ++i)
	{
		if(dp[i] = INF)
		{
			queue<int> q;
			q.push(i);
			dp[i] = 0;
			while(!q.empty())
			{
				int cur = q.front();
				q.pop();
				for(int i = 0;i < G[cur].size(); ++i)
				{
					pair<int,int> p = G[i][j];
					if(!vis[G[cur][i]])
					{
						q.push(G[cur][i]);
						vis[G[cur][i]] = 1;
					}
				}
			}
		}
	}
	return 0;
}
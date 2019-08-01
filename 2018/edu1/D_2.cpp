#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1005;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
bool a[maxn][maxn];
bool visDot[maxn][maxn];
bool vis[maxn][maxn];
int n,m,k;
bool checkDot(int x,int y)
{
	return (x < n && y < m && x >= 0 && y >= 0) 
	&& (a[x][y] == 1) 
	&& !visDot[x][y];
}
bool judge(int x,int y)
{
	return (x < n && y < m && x >= 0 && y >= 0);
}
void dfs(int x,int y)
{
	visDot[x][y] = 1;
	for(int i = 0;i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(checkDot(nx,ny)
			&& visDot[nx][ny] == 0)
		{
			visDot[nx][ny] = 1;
			dfs(nx,ny);
		}
	}
}
int dfssum(int x,int y)
{
	// getchar();
	int ret = 0;
	for(int k = 0;k < 4; ++k)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(!judge(nx,ny))
		{
			continue;
		}
		if(!a[nx][ny])
		{
			ret++;
		}
	}
	visDot[x][y] = 0;
	for(int k = 0;k < 4; ++k)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(visDot[nx][ny])
		{
			visDot[nx][ny] = 0;
			ret += dfssum(nx,ny);
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			char c;
			cin>>c;
			a[i][j] = (c == '.');
		}
	}
	int x,y;
	while(k--)
	{
		memset(visDot,0x00,sizeof(visDot));
		memset(vis,0x00,sizeof(vis));
		cin>>x>>y;
		--x,--y;
		dfs(x,y);
		printf("%d\n",dfssum(x,y));
	}
	return 0;
}
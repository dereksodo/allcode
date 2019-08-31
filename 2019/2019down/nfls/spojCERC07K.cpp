#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <cstring>
using namespace std;
map<char,int> mp;
const int inf = 0x3f3f3f3f;
//input
//bfs to get the smallest distance
//output
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,1,-1};
struct xx{
	int x,y,k/*key*/,step;
	xx(int X = 0,int Y = 0,int K = 0,int Step = inf)
	{
		x = X,y = Y,k = K,step = Step;
	}
};
const int maxn = 105;
char labyrinth[maxn][maxn];
int dp[maxn][maxn][maxn];
int pos_x = -1,pos_y = -1;
int size_x,size_y;
bool inboard(int x,int y)
{
	return x >= 0 && y >= 0 && x < size_x && y < size_y;
}
bool ok(int x,int y)
{
	return labyrinth[x][y] != '#';
}
bool is_door(int x,int y)
{
	return labyrinth[x][y] == 'B' || labyrinth[x][y] == 'G' || labyrinth[x][y] == 'R' || labyrinth[x][y] == 'Y'; 
}
bool is_key(int x,int y)
{
	return labyrinth[x][y] == 'b' || labyrinth[x][y] == 'g' || labyrinth[x][y] == 'r' || labyrinth[x][y] == 'y'; 
}
void bfs()
{
	memset(dp,inf,sizeof(dp));
	queue<xx> q;
	while(!q.empty())
	{
		q.pop();
	}
	q.push(xx(pos_x,pos_y,0,0));
	dp[pos_x][pos_y][0] = 0;
	while(!q.empty())
	{
		auto now = q.front();
		q.pop();
		for(int i = 0;i < 4; ++i)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			int nk = now.k;
			if(inboard(nx,ny) && ok(nx,ny))
			{
				if(is_key(nx,ny))
				{
					nk |= (1 << mp[labyrinth[nx][ny]]);
				}
				if(is_door(nx,ny))
				{
					if(!(nk & (1 << mp[labyrinth[nx][ny]])))
					{
						continue;
					}
				}
				if(dp[nx][ny][nk] == inf)
				{
					dp[nx][ny][nk] = now.step + 1;
					q.push(xx(nx,ny,nk,now.step + 1));
				}
			}
		}
	}
}
int solve()
{
	mp['B'] = mp['b'] = 0;
	mp['G'] = mp['g'] = 1;
	mp['R'] = mp['r'] = 2;
	mp['Y'] = mp['y'] = 3;
	bfs();
	int res = inf;
	for(int i = 0;i < size_x; ++i)
	{
		for(int j = 0;j < size_y; ++j)
		{
			for(int k = 0;k < 16; ++k)
			{
				if(labyrinth[i][j] == 'X')
				{
					res = min(res,dp[i][j][k]);
				}
			}
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	while(cin>>size_x>>size_y && size_x)
	{
		getchar();
		for(int i = 0;i < size_x; ++i)
		{
			string s;
			getline(cin,s);
			for(int j = 0;j < size_y; ++j)
			{
				labyrinth[i][j] = s[j];
				if(labyrinth[i][j] == '*')
				{
					pos_x = i;
					pos_y = j;
				}
			}
		}
		if(pos_x == -1)
		{
			printf("The poor student is trapped!\n");
			continue;
		}
		int ans = solve();
		if(ans == inf)
		{
			printf("The poor student is trapped!\n");
		}
		else
		{
			printf("Escape possible in %d steps.\n",ans);
		}
	}
	return 0;
}
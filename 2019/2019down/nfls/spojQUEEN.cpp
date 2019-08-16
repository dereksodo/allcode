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
char mp[1005][1005];
struct node{
	int x,y;
	node(){};
	node(int a,int b):x(a),y(b){};
};
int dis[1005][1005];
int dir[1005][1005];
int n,m;
const int dx[] = {0,0,1,1,1,-1,-1,-1};
const int dy[] = {1,-1,1,0,-1,1,0,-1};
int check(int x,int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != 'X';
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		queue<node> q;
		node lastnode;
		memset(dis,0x3f3f3f3f,sizeof(dis));
		memset(dir,0x00,sizeof(dir));
		for(int i = 0;i < n; ++i)
		{
			scanf("%s",mp[i]);
			for(int j = 0;j < m; ++j)
			{
				if(mp[i][j] == 'S')
				{
					q.push(node(i,j));
					dir[i][j] = 255;
					dis[i][j] = 0;
				}
				if(mp[i][j] == 'F')
				{
					lastnode = node(i,j);
				}
			}
		}
		bool flag = 1;
		while(!q.empty())
		{
			node cur = q.front();
			q.pop();
			if(cur.x == lastnode.x && cur.y == lastnode.y)
			{
				printf("%d\n",dis[cur.x][cur.y]);
				flag = 0;
				break;
			}
			for(int i = 0;i < 8; ++i)
			{
				int di = 1;
				while(1)
				{
					int nx = cur.x + dx[i] * di;
					int ny = cur.y + dy[i] * di;
					if(check(nx,ny) && mp[nx][ny] != 'X' && !(dir[nx][ny] & (1 << i)))
					{
						if(!dir[nx][ny])
						{
							dis[nx][ny] = dis[cur.x][cur.y] + 1;
							q.push(node(nx,ny));
						}
						dir[nx][ny] |= (1 << i);
					}
					else
					{
						break;
					}
					++di;
				}
			}
		}
		if(flag)
		{
			printf("-1\n");
		}
	}
	return 0;
}
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
const int N = 4;
const int maxn = 10;
int a[maxn][maxn],ed[maxn][maxn];
int vis[(1 << 20)],edd;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
int num(int fg = 0)
{
	int ret = 0;
	if(fg == 1)
	{
		for(int i = 1;i <= N; ++i)
		{
			for(int j = 1;j <= N; ++j)
			{
				ret = (ret << 1) + ed[i][j];
			}
		}
		return ret;
	}
	for(int i = 1;i <= N; ++i)
	{
		for(int j = 1;j <= N; ++j)
		{
			ret = (ret << 1) + a[i][j];
		}
	}
	return ret;
}
int getnum(int x,int i,int j)
{
	return (x & (1 << (20 - (4 * i + j)))) != 0;
}
int check(int i,int j,int co,int x)
{
	return i >= 1 && i <= N && j >= 1 && j <= N && (getnum(x,i,j) != co);
}
int ch(int i,int j,int ni,int nj)
{
	return (1 << (20 - (4 * ni + nj))) - (1 << (20 - (4 * i + j)));
}
int bfs()
{
	queue< pair<int,int> > q;
	q.push(make_pair(num(),0));
	vis[num()] = 1;
	while(!q.empty())
	{
		pair<int,int> now = q.front();
		q.pop();
		if(now.first == edd)
		{
			return now.second;
		}
		for(int i = 1;i <= N; ++i)
		{
			for(int j = 1;j <= N; ++j)
			{
				for(int k = 0;k < 4; ++k)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(check(nx,ny,getnum(now.first,i,j),now.first))
					{
						int newsum = ch(nx,ny,i,j);
						if(getnum(now.first,i,j) == 1)
						{
							newsum = ch(i,j,nx,ny);
						}
						if(!vis[newsum + now.first])
						{
							vis[newsum + now.first] = 1;
							q.push(make_pair(newsum + now.first,now.second + 1));
						}
					}
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	for(int i = 1;i <= N; ++i)
	{
		for(int j = 1;j <= N; ++j)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	for(int i = 1;i <= N; ++i)
	{
		for(int j = 1;j <= N; ++j)
		{
			scanf("%1d",&ed[i][j]);
		}
	}
	edd = num(1);
	printf("%d\n",bfs());
	return 0;
}
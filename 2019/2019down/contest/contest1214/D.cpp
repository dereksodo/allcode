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
int n,m;
vector<string> vs;
vector< vector<int> > vis_p,vis_p2;
// vector<int> vis[2];
const int dx[] = {0,1};
const int dy[] = {1,0};
int cnt,ansx,ansy;
vector< pair<int,int> > path;
void dfs(int x,int y,int flag)
{
	// printf("x = %d,y = %d\n",x,y);
	if(flag)
	{
		path.push_back(make_pair(x,y));
	}
	vis_p[x][y] = 1;
	if(x == n - 1 && y == m - 1)
	{
		flag = 0;
	}
	for(int i = 0;i < 2; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		// printf("nx = %d,ny = %d\n",nx,ny);
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && (vs[nx][ny] != '#') && (!vis_p[nx][ny]))
		{
			dfs(nx,ny,flag);
		}
	}
}
char qry(int x,int y)
{
	if(x >= n || y >= m)
	{
		return '.';
	}
	return vs[x][y];
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	// vis[0].resize(n);
	// vis[1].resize(m);
	vis_p.resize(n);
	vis_p2.resize(n);
	for(int i = 0;i < n; ++i)
	{
		vis_p2[i].resize(m);
		vis_p[i].resize(m);
		string p;
		cin>>p;
		vs.push_back(p);
	}
	dfs(0,0,1);
	if(!vis_p[n - 1][m - 1])
	{
		printf("0\n");
		return 0;
	}
	for(int i = 1;i < path.size(); ++i)
	{
		if(path[i].first == n - 1 && path[i].second == m - 1)
		{
			break;
		}
		if(qry(path[i].first + 1,path[i].second) == '#' || qry(path[i].first,path[i].second) == '#')
		{
			continue;
		}
		// printf("%d %d\n",path[i].first,path[i].second);
		vs[path[i].first][path[i].second] = '#';
		vis_p = vis_p2;
		dfs(0,0,0);
		if(!vis_p[n - 1][m - 1])
		{
			// printf("%d %d\n",path[i].first,path[i].second);
			printf("1\n");
			return 0;
		}
		vs[path[i].first][path[i].second] = '.';
	}
	printf("2\n");
	return 0;
}
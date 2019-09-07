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
vector< vector<int> > vis;
const int dx[] = {0,1,-1,0};
const int dy[] = {1,0,0,-1};
vector< pair<int,int> > v_cnt[2];
void dfs(int x,int y,int flag)
{
	vis[x][y] = 1;
	v_cnt[flag].push_back(make_pair(x,y));
	if(flag == 0)
	{
		for(int i = 0;i < 2; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			// printf("nx = %d,ny = %d\n",nx,ny);
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && (vs[nx][ny] != '#') && (!vis[nx][ny]))
			{
				dfs(nx,ny,flag);
			}
		}
	}
	else
	{
		for(int i = 2;i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			// printf("nx = %d,ny = %d\n",nx,ny);
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && (vs[nx][ny] != '#') && (!vis[nx][ny]))
			{
				dfs(nx,ny,flag);
			}
		}
	}
}
map< pair<int,int>,int > mp;
map<int,int> s;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	// vis[0].resize(n);
	// vis[1].resize(m);
	vis.resize(n);
	for(int i = 0;i < n; ++i)
	{
		vis[i].resize(m);
		string p;
		cin>>p;
		vs.push_back(p);
	}
	dfs(0,0,0);
	if(!vis[n - 1][m - 1])
	{
		printf("0\n");
		return 0;
	}
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			vis[i][j] = 0;
		}
	}
	dfs(n - 1,m - 1,1);
	for(int i = 0;i < v_cnt[0].size(); ++i)
	{
		mp[make_pair(v_cnt[0][i].first,v_cnt[0][i].second)] = v_cnt[0][i].first + v_cnt[0][i].second;
	}
	for(int i = 0;i < v_cnt[1].size(); ++i)
	{
		if(mp[make_pair(v_cnt[1][i].first,v_cnt[1][i].second)])
		{
			s[mp[make_pair(v_cnt[1][i].first,v_cnt[1][i].second)]]++;
		}
	}
	for(map<int,int>::iterator iter = s.begin();iter != s.end(); ++iter)
	{
		if(iter->first == n + m - 2)
		{
			continue;
		}
		// printf("%d %d\n",iter->first,iter->second);
		if(iter->second == 1)
		{
			printf("1\n");
			return 0;
		}
	}
	printf("2\n");
	return 0;
}
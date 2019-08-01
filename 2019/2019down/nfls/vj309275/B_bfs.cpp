#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int n = 5;
queue< pair<int,int> > q;
int a[n][n];
int vis[n][n];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
bool ok(int i,int j)
{
	return i >= 0 && i < n && j >= 0 && j < n && !a[i][j] && !vis[i][j];
}
map< pair<int,int>,pair<int,int> > mp;
int main(int argc,char const *argv[])
{
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			scanf("%d",&a[i][j]);
			mp[make_pair(i,j)] = make_pair(-1,-1);
		}
	}
	vis[0][0] = 1;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
		pair<int,int> now = q.front();
		q.pop();
		for(int i = 0;i < 4; ++i)
		{
			int ni = now.first + dx[i];
			int nj = now.second + dy[i];
			if(ok(ni,nj))
			{
				q.push(make_pair(ni,nj));
				mp[make_pair(ni,nj)] = now;
				vis[ni][nj] = 1;
			}
		}
		if(now.first == n - 1 && now.second == n - 1)
		{
			break;
		}
	}
	pair<int,int> cur = make_pair(n - 1,n - 1);
	vector< pair<int,int> > v;
	v.clear();
	while(cur.first != -1)
	{
		v.push_back(cur);
		cur = mp[cur];
	}
	reverse(v.begin(),v.end());
	for(int i = 0;i < v.size(); ++i)
	{
		printf("(%d, %d)\n",v[i].first,v[i].second);
	}
	return 0;
}


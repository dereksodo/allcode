#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int n = 5;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int a[n][n];
int vis[n][n];
bool ok(int i,int j)
{
	return i >= 0 && i < n && j >= 0 && j < n && !a[i][j] && !vis[i][j];
}
vector< pair<int,int> > dfs(int i,int j)
{
	// debug("i = %d,j = %d\n",i,j);
	vector< pair<int,int> > ans;
	ans.clear();
	if(i == n - 1 && j == n - 1)
	{
		ans.push_back({n - 1,n - 1});
		return ans;
	}
	ans.push_back({-1,-1});
	for(int k = 0;k < 4; ++k)
	{
		int ni = i + dx[k];
		int nj = j + dy[k];
		if(ok(ni,nj))
		{
			vis[ni][nj] = 1;
			vector< pair<int,int> > ret = dfs(ni,nj);
			if(ret[0] != make_pair(-1,-1))
			{
				ans = ret;
				break;
			}
			vis[ni][nj] = 0;
		}
	}
	if(ans[0] == make_pair(-1,-1))
	{
		return ans;
	}
	reverse(ans.begin(),ans.end());
	ans.push_back({i,j});
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(int argc, char const *argv[])
{
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	vis[0][0] = 1;
	vector< pair<int,int> > ans = dfs(0,0);
	for(int i = 0;i < ans.size(); ++i)
	{
		printf("(%d, %d)\n",ans[i].first,ans[i].second);
	}
	return 0;
}

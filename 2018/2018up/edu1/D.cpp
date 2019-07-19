#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>
#include <utility>
using namespace std;
const int maxn = 1005;
bool a[maxn][maxn];
bool vis[maxn][maxn];
int n,m,k;
bool check1(int a,int b)
{
	if(a < n && b < m && a >= 0 && b >= 0)
	{
		return 1;
	}
	return 0;
}
bool check2(int x,int y)
{
	return check1(x,y) && (a[x][y] == 1);
}
unordered_set< pair<int,int> > __ok;
void dfs1(int x,int y)
{
	if(check2())
	{
		
	}
}
/*
5 6 3
******
*..*.*
******
*....*
******
2 2
2 5
4 3
*/
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
		memset(vis,0x00,sizeof(vis));
		cin>>x>>y;
		--x,--y;
		printf("%d\n",dfs(x,y));
	}
	return 0;
}
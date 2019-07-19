#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 305;
vector<int> a[maxn];
int p[maxn];
void dfs(int x,int from) 
{
	p[x] = from;
	for(int i = 0;i < a[x].size(); ++i)
	{
		if(a[x][i] != from)
		{
			dfs(a[x][i], x);
		}
	}
}
vector<int> path;
void addpath(int x,int y) 
{
	int Q[maxn],d[maxn];
	int r = 1;
	memset(Q,0x00,sizeof(Q));
	memset(d,0x00,sizeof(d));
	while(y) 
	{
		d[y] = r; 
		Q[r] = y;
		++r;
	 	y = p[y];
	}
	while(x) 
	{
		if(d[x]) 
		{
			for(int i = d[x] - 1;i > 0; --i) 
			{
				path.push_back(Q[i]);
			}
			break;
		}
		x = p[x];
		path.push_back(x);
	}
}
int main(int argc,char const *argv[]) 
{
	int n;
	scanf("%d", &n);
	int x,y;
	for(int i =1;i < n; ++i)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,-1);
	int last = 1;
	path.push_back(1);
	for(int i = 2;i <= n; ++i)
	{
		if(a[i].size() == 1) 
		{
			int cur;
			cin>>cur;
			addpath(last, cur);
			last = cur;
		}
	}
	addpath(last, 1);
	if(path.size() != 2 * n - 1) 
	{
		printf("-1\n");
	}
	else 
	{
		printf("1");
		for(int i = 1;i < path.size(); ++i)
		{
			printf(" %d", path[i]);
		}
		printf("\n");
	}
	return 0;
}
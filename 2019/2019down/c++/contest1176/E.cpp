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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int n,m;
vector< vector<int> > G;
vector<int> d;
const int inf = 1e9;
void bfs(int start)
{
	d = vector<int>(n,inf);
	d[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(auto u : G[v])
		{
			if(d[u] == inf)
			{
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		G = vector< vector<int> >(n);
		for(int i = 0;i < m; ++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			--x,--y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		bfs(0);
		vector<int> even,odd;
		for(int i = 0;i < n; ++i)
		{
			if(d[i] & 1)
			{
				odd.push_back(i);
			}
			else
			{
				even.push_back(i);
			}
		}
		if(even.size() < odd.size())
		{
			cout<<even.size()<<endl;
			for(auto v : even)
			{
				printf("%d ",v + 1);
			}
		}
		else
		{
			cout<<odd.size()<<endl;
			for(auto v : odd)
			{
				printf("%d ",v + 1);
			}
		}
		printf("\n");
	}
	return 0;
}
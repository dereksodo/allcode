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
const int maxn = 30;
vector<int> v[maxn];
char pa[maxn],pb[maxn];
int color[maxn];
int f(int b)
{
	for(int i = 0;i < v[color[b]].size(); ++i)
	{
		if(v[color[b]][i] == b)
		{
			return i;
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		v[i].clear();
		v[i].push_back(i);
		color[i] = i;
	}
	while(1)
	{
		int a,b;
		scanf(" %s",pa);
		if(pa[0] == 'q')
		{
			break;
		}
		scanf(" %d %s %d",&a,pb,&b);
		if(a == b)
		{
			continue;
		}
		if(pa[0] == 'm')
		{
			if(pb[1] == 'n')
			{
				int j = f(a);
				int j2 = f(b);
				for(int i = j + 1;i < v[color[a]].size(); ++i)
				{
					int u = v[color[a]][i];
					v[u].push_back(u);
					color[u] = u;
				}
				int sz = v[color[a]].size() - (j + 1);
				while(sz--)
				{
					v[color[a]].pop_back();
				}
				for(int i = j2 + 1;i < v[color[b]].size(); ++i)
				{
					int u = v[color[b]][i];
					v[color[b]].pop_back();
					v[u].push_back(u);
					color[u] = u;
				}
				sz = v[color[b]].size() - (j2 + 1);
				while(sz--)
				{
					v[color[b]].pop_back();
				}
				v[color[a]].pop_back();
				color[a] = b;
				v[b].push_back(a);
			}
			else
			{
				int j = f(a);
				for(int i = j + 1;i < v[color[a]].size(); ++i)
				{
					int u = v[color[a]][i];
					v[u].push_back(u);
					v[color[a]].pop_back();
					color[u] = u;
				}
				v[color[a]].pop_back();
				color[a] = b;
				v[b].push_back(a);
			}
		}
		else
		{
			if(pb[1] == 'n')
			{
				int j = f(a);
				int j2 = f(b);
				for(int i = j2 + 1;i < v[color[b]].size(); ++i)
				{
					int u = v[color[b]][i];
					v[u].push_back(u);
					v[color[b]].pop_back();
					color[u] = u;
				}
				int sz = v[color[a]].size();
				for(int i = j;i < sz; ++i)
				{
					int u = v[color[a]][i];
					color[u] = b;
					v[color[b]].pop_back();
					v[b].push_back(u);
				}
			}
			else
			{
				int j = f(a);
				int sz = v[color[a]].size();
				for(int i = j + 1;i < sz; ++i)
				{
					int u = v[color[a]][i];
					color[u] = b;
					v[color[a]].pop_back();
					v[b].push_back(u);
				}
			}
		}
		printf("done\n");
		for(int i = 0;i < n; ++i)
		{
			printf("%d:",i);
			int sz = v[i].size();
			for(int j = 0;j < sz; ++j)
			{
				printf(" %d",v[i][j]);
			}
			printf("\n");
		}
	}
	for(int i = 0;i < n; ++i)
	{
		printf("%d:",i);
		int sz = v[i].size();
		for(int j = 0;j < sz; ++j)
		{
			printf(" %d",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}
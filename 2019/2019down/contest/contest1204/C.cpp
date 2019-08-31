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
const int maxn = 105;
const int maxn2 = 1e6 + 100;
const int inf = 0x3f3f3f3f;
int a[maxn][maxn];
int dis[maxn][maxn];
int b[maxn2];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			scanf("%1d",&a[i][j]);
			if(i == j)
			{
				dis[i][j] = 0;
			}
			else
			{
				if(a[i][j])
				{
					dis[i][j] = 1;
				}
				else
				{
					dis[i][j] = inf;
				}
			}
		}
	}
	for(int k = 1;k <= n; ++k)
	{
		for(int i = 1;i <= n; ++i)
		{
			for(int j = 1;j <= n; ++j)
			{
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	int m;
	cin>>m;
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d",&b[i]);
	}
	vector<int> v;
	v.clear();
	int last = 0;
	for(int i = 1;i <= m; ++i)
	{
		if(last == 0)
		{
			last = i;
			v.push_back(b[i]);
		}
		else if(i - last != dis[b[last]][b[i]])
		{
			v.push_back(b[i - 1]);
			last = i - 1;
		}
	}
	v.push_back(b[m]);
	printf("%d\n",v.size());
	for(int i = 0;i < v.size(); ++i)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
	return 0;
}
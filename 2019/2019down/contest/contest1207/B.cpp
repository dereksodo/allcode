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
const int maxn = 55;
int a[maxn][maxn],b[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&a[i][j]);
			b[i][j] = 0;
		}
	}
	vector< pair<int,int> > v;
	for(int i = 1;i + 1 <= n; ++i)
	{
		for(int j = 1;j + 1 <= m; ++j)
		{
			if(a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1])
			{
				v.push_back(make_pair(i,j));
				b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(a[i][j] != b[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",v.size());
	for(int i = 0;i < v.size(); ++i)
	{
		printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}
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
#define left my_left
#define right my_right
const int maxn = 2005;
int a[maxn][maxn];
int up[maxn][maxn],left[maxn][maxn],right[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			scanf("%d",&a[i][j]);
			up[i][j] = 1;
			left[i][j] = right[i][j] = j;
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 2;j <= m; ++j)
		{
			if(a[i][j] != a[i][j - 1])
			{
				left[i][j] = left[i][j - 1];
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		for(int j = m - 1;j >= 1; --j)
		{
			if(a[i][j] != a[i][j + 1])
			{
				right[i][j] = right[i][j + 1];
			}
		}
	}
	int ans1 = 0,ans2 = 0;
	for(int i = 1;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			if(i > 1 && a[i][j] != a[i - 1][j])
			{
				left[i][j] = max(left[i][j],left[i - 1][j]);
				right[i][j] = min(right[i][j],right[i - 1][j]);
				up[i][j] = up[i - 1][j] + 1;
			}
			int a = right[i][j] - left[i][j] + 1;
			int b = min(a,up[i][j]);
			ans1 = max(ans1,b * b);
			ans2 = max(ans2,a * up[i][j]);
		}
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
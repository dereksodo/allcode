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
const int maxn = 2e5 + 5;
int n,m;
int lg[maxn],maxx[maxn][30];
int a[maxn];
void init()
{
	for(int i = 1;i <= n; ++i)
	{
		maxx[i][0] = a[i];
	}
	for(int j = 1;j < 30; ++j)
	{
		for(int i = 1;i + (1 << j) - 1 <= n; ++i)
		{
			maxx[i][j] = max(maxx[i][j - 1],maxx[i + (1 << j - 1)][j - 1]);
		}
	}
}
int query(int l,int r)
{
	int k = lg[r - l + 1];
	return max(maxx[l][k],maxx[r - (1 << k) + 1][k]);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	lg[0] = -1;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		lg[i] = lg[i >> 1] + 1;
	}
	init();
	scanf("%d",&m);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
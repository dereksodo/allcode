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
const int maxn = (1 << 12) + 5;
ll sum[maxn][maxn],n,m;
void update(int x,int y,int v)
{
	for(int i = x;i <= n;i += i & (-i))
	{
		for(int j = y;j <= m;j += j & (-j))
		{
			sum[i][j] += v;
		}
	}
}
ll query(int x,int y)
{
	ll ret = 0;
	for(int i = x;i;i -= i & (-i))
	{
		for(int j = y;j;j -= j & (-j))
		{
			ret += sum[i][j];
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	int fg;
	while(~scanf("%d",&fg))
	{
		if(fg == 1)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			update(x,y,k);
		}
		else
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			printf("%lld\n",query(c,d) - query(a - 1,d) - query(c,b - 1) + query(a - 1,b - 1));
		}
	}
	return 0;
}
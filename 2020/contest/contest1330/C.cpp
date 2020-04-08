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
const int maxn = 100005;
int len[maxn];
ll sum[maxn];
void output(ll x,int flag = 1)
{
	printf("%lld",x);
	if(flag == -1)
	{
		printf("\n");
		exit(0);
	}
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d",&len[i]);
		if(len[i] + i - 1 > n)
		{
			output(-1,-1);
		}
	}
	for(int i = m;i > 0; --i)
	{
		sum[i] = sum[i + 1] + len[i];
	}
	if(sum[1] < n)
	{
		output(-1,-1);
	}
	for(int i = 1;i <= m; ++i)
	{
		output(max(1ll * i,n - sum[i] + 1));
		printf(" ");
	}
	printf("\n");
	return 0;
}
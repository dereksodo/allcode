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
const int maxn = 1e6 + 6;
int a[maxn];
int sum[maxn];
int vis[maxn << 2];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1;i <= n; ++i)
	{
		if(a[i] == 1)
		{
			int sn = sum[n] - sum[i - 1];
			for(int k = 1;k <= sn; ++k)
			{
				vis[k] = 1;
			}
			for(int k = sn;k <= sum[n];k += 2)
			{
				vis[k] = 1;
			}
			break;
		}
	}
	for(int i = n;i >= 1; --i)
	{
		if(a[i] == 1)
		{
			int sn = sum[i];
			for(int k = 1;k <= sn; ++k)
			{
				vis[k] = 1;
			}
			for(int k = sn;k <= sum[n];k += 2)
			{
				vis[k] = 1;
			}
			break;
		}
	}
	while(m--)
	{
		int x;
		scanf("%d",&x);
		if(vis[x])
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}
	return 0;
}
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
const int maxn = 1e6 + 6;
int a[maxn],c[maxn],l[maxn],r[maxn];
ll cf[maxn];
int n,m;
ll sum;
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d%d",&c[i],&l[i],&r[i]);
		cf[l[i]] += c[i];
		cf[r[i] + 1] -= c[i];
	}
	int j = m;
	int x = 0x3f3f3f3f;
	for(int i = 1;i <= n; ++i)
	{
		sum += cf[i];
		if(sum > a[i])
		{
			while(sum > a[i])
			{
				cf[l[j]] -= c[j];
				cf[r[j] + 1] += c[j];
				if(l[j] <= i && i <= r[j])
				{
					sum -= c[j];
				}
				--j;
			}
			x = min(x,j);
		}
	}
	if(x == 0x3f3f3f3f)
	{
		printf("0\n");
	}
	else
	{
		printf("-1\n%d\n",x + 1);
	}
	return 0;
}
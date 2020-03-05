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
const int maxn = 1000005;
int a[maxn],mp[maxn],cnt[maxn];
int main(int argc, char const *argv[])
{
	int n,maxx = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		mp[a[i]]++;
		maxx = max(maxx,a[i]);
	}
	for(int i = 1;i <= maxx; ++i)
	{
		if(mp[i])
		{
			for(int j = 1;i * j <= maxx; ++j)
			{
				cnt[i * j] += mp[i];
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		printf("%d\n",cnt[a[i]] - 1);
	}
	return 0;
}
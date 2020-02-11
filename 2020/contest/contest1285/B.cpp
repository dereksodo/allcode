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
const int maxn = 1e5 + 5;
int a[maxn];
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		int k;
		cin>>k;
		for(int j = 1;j <= k; ++j)
		{
			scanf("%d",&a[j]);
		}
		bool flag = 1;
		ll now = 0;
		for(int j = 1;j <= k; ++j)
		{
			now += a[j];
			if(now <= 0)
			{
				flag = 0;
				break;
			}
		}
		now = 0;
		for(int j = k;j >= 1; --j)
		{
			now += a[j];
			if(now <= 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
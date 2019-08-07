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
const int maxn = 100005;
int x,n;
int a[maxn],dp1[maxn],dp2[maxn];
int main(int argc, char const *argv[])
{
	while(cin>>a[++n]);
	--n;
	int len1 = 1,len2 = 1;
	dp1[1] = dp2[1] = a[1];
	for(int i = 2;i <= n; ++i)
	{
		if(dp1[len1] >= a[i])
		{
			dp1[++len1] = a[i];
		}
		else
		{
			*upper_bound(dp1 + 1,dp1 + 1 + len1,a[i],greater<int>()) = a[i];
		}
		if(dp2[len2] < a[i])
		{
			dp2[++len2] = a[i];
		}
		else
		{
			*lower_bound(dp2 + 1,dp2 + 1 + len2,a[i]) = a[i];
		}
	}
	printf("%d\n%d\n",len1,len2);
	return 0;
}
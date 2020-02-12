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
int n,m;
int check(int mid)
{
	int cnt = 0;
	int now = 0;
	for(int i = 1;i <= n; ++i)
	{
		if(a[i] + now > mid)
		{
			cnt++;
			now = 0;
		}
		now += a[i];
	}
	// printf("mid = %d,cnt + 1 = %d\n",mid,cnt + 1);
	return cnt + 1 <= m;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	int l = 0,r = 1e9;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
		l = max(l,a[i]);
	}
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("%d\n",r);
	return 0;
}
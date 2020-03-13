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
const int maxn = 5e4 + 10;
int a[maxn],q[maxn],h,t,f[maxn],n,tim;
int check(int mid)
{
	h = t = 0;
	for(int i = 1;i <= n; ++i)
	{
		while(h <= t && i - q[h] > mid + 1)
		{
			++h;
		}
		f[i] = f[q[h]] + a[i];
		while(h <= t && f[q[t]] >= f[i])
		{
			--t;
		}
		q[++t] = i;
	}
	return f[q[h]] <= tim;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&tim);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",a + i);
	}
	int l = 1,r = n;
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
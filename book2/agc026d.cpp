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
const int maxn = 103;
const int mod = 1e9 + 7;
int n,m,a[maxn],b[maxn],f[maxn][maxn],tp;
int i,j;
ll mypow(ll a,ll b)
{
	if(b <= 0)
	{
		return 1;
	}
	ll res = 1;
	for(;b;b >>= 1,a = a * a % mod)
	{
		if(b & 1)
		{
			res = res * a % mod;
		}
	}
	return res;
}
void trans(int d)
{
	d = min(d,a[i + 1]);
	f[i + 1][d] = (f[i + 1][d] + mypow(2,b[a[i]] - b[max(j,a[i + 1])]) * tp) % mod;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 0;i < n; ++i)
	{
		scanf("%d",&a[i]);
		b[i] = --a[i];
	}
	sort(b,b + n + 1);
	m = unique(b,b + n + 1) - b;
	for(int i = 0;i < n; ++i)
	{
		a[i] = lower_bound(b,b + m,a[i]) - b;
	}	
	f[0][0] = 1;
	for(i = 0;i < n; ++i)
	{
		for(j = 0;j <= a[i]; ++j)
		{
			if((tp = f[i][j]))
			{
				trans(j),trans(a[i]);
			}
		}
	}
	printf("%d\n",f[n][0]);
	return 0;
}
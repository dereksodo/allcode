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
const int maxn = 200005;
const int mod = 1e9 + 7;
int a[maxn];
ll sum[maxn],mul[maxn];
ll f[maxn];
ll mypow(ll a,ll b)
{
	ll ret = 1;
	for(;b;b >>= 1,a = a * a % mod)
	{
		if(b & 1)
		{
			ret = ret * a % mod;
		}
	}
	return ret;
}
void init()
{
	f[0] = 1;
	for(int i = 1;i < maxn; ++i)
	{
		f[i] = f[i - 1] * i % mod;
	}
}
int check(int l,int r)
{
	ll len = r - l + 1;
	ll s = len * (len + 1) / 2;
	ll m = mul[r] * mypow(mul[l - 1],mod - 2) % mod;
	return (sum[r] - sum[l - 1] == s) && (m == f[len]);
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	init();
	while(t--)
	{
		int n;
		scanf("%d",&n);
		sum[0] = 0;
		mul[0] = 1;
		for(int i = 1;i <= n; ++i)
		{
			scanf("%d",&a[i]);
			sum[i] = sum[i - 1] + a[i];
			mul[i] = mul[i - 1] * a[i] % mod;
		}
		vector<int> vec;
		for(int i = 1;i <= n; ++i)
		{
			if(check(1,i) && check(i + 1,n))
			{
				vec.push_back(i);
			}
		}
		printf("%d\n",(int)vec.size());
		for(int i = 0;i < vec.size(); ++i)
		{
			printf("%d %d\n",vec[i],n - vec[i]);
		}
	}
	return 0;
}
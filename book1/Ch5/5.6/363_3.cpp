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
ll d[maxn],s[maxn],f[maxn],q[maxn],l,r;
ll a,b,c,n;
double slope(int j,int k)
{
	return 1.0 * (f[j] - f[k] + a * (s[j] * s[j] - s[k] * s[k]) + b * (s[k] - s[j])) / (2.0 * a * (s[j] - s[k]));
}
int main(int argc, char const *argv[])
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%lld",&d[i]);
		s[i] = s[i - 1] + d[i];
	}
	l = r = 1;
	for(int i = 1;i <= n; ++i)
	{
		while(l < r && slope(q[l],q[l + 1]) <= s[i])
		{
			++l;
		}
		int j = q[l],x = s[i] - s[j];
		f[i] = f[j] + a * x * x + b * x + c;
		while(l <= r && slope(q[r - 1],q[r]) >= slope(q[r],i))
		{
			--r;
		}
		q[++r] = i;
	}
	printf("%lld\n",f[n]);
	return 0;
}